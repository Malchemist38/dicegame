#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h" // Include the header file containing function prototypes

int main() {
    srand(time(NULL)); // Initialize the RNG with the current time as the seed
    int player1Points = 0, player2Points = 0; // Initialize player points
    Round round; // Declare a variable of type Round to hold round information

    int rounds;
    printf("Enter the number of rounds: "); //Prompt for and read user input
    scanf("%d", &rounds);

    printPlayerPoints(player1Points, player2Points); //Print initial player points (both set to 0)
    printf("\n"); 

    int currentPlayer = rand() % 2 + 1; //Start with a random player (1 or 2)

    int i;
    for (i = 1; i <= rounds; i++) { //This is the main loop for the game
        printf("ROUND %d\n", i); //Print heading
        printf("--------\n");

        generateRound(&round); //Generate round (type, dice, points)
        printf("Player\t: %d\n", currentPlayer); 
        printRoundInfo(round.type, round.dice, round.points); //Print round details

        int isOddPlayer = (currentPlayer % 2 != 0);
        int isSuccess = (isOddPlayer && round.dice % 2 != 0) || (!isOddPlayer && round.dice % 2 == 0);
                        //If P1 and the dice number are both odd OR if P2 and the dice number are both even = SUCCESS
        if (isSuccess) {
            if (currentPlayer == 1) {
                player1Points += round.points; //P1 gains points
            } else {
                player2Points += round.points; //P2 gains points
            }
            printf("P1\t: %d\nP2\t: %d\n\n", player1Points, player2Points);
        } else {
            if (currentPlayer == 1) {
                player1Points -= round.points; //P1 receives penalty
            } else {
                player2Points -= round.points; //P2 receives penalty
            }
            printf("P1\t: %d\nP2\t: %d\n\n", player1Points, player2Points); //Updated points
        }

        if (isSuccess) {
            //Current player gets another turn if successful
            continue;
        }

        currentPlayer = (currentPlayer % 2) + 1; //Change player on failure
    }

    printf("GAME OVER!!\n"); //End of game

    if (player1Points > player2Points) {
        printf("P1 Won\n\n");
    } else if (player1Points < player2Points) {
        printf("P2 Won\n\n");
    } else {
        printf("It's a tie!\n\n");
    }

    return 0;
}
