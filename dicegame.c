#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int getRandomNumber(int min, int max) { //Main RNG which other functions can call
    return rand() % (max - min + 1) + min; //Random number between min and max inclusive
}

RoundType getRoundType() { //Returns the round type based on probability
    int randValue = getRandomNumber(0, 9);

    if (randValue < 2) { //20% for bonus
        return BONUS;
    } else if (randValue < 5) { //30% for double
        return DOUBLE;
    } else {
        return REGULAR; //50% for regular
    }
}

int getRoundPoints(RoundType roundType) { //Calls the RNG for the number of points times 10 (10 - 100 inclusive)
    return getRandomNumber(1, 10) * 10;
}

void rollDice(int *dice) { //Calls the RNG for a number between 1 and 6 inclusive
    *dice = getRandomNumber(1, 6);
}

void generateRound(Round *round) { //Main function for generating round details
    rollDice(&round->dice); //Uses the struct in dicegame.h to refer to values: dice, points, and type
    round->type = getRoundType();

    switch (round->type) {
        case REGULAR:
            round->points = getRoundPoints(REGULAR); //Keeps orginal point value
            break;
        case BONUS:
            round->points = 200; //Fixed point value at 200
            break;
        case DOUBLE:
            round->points = getRoundPoints(DOUBLE) * 2; //Doubles original point value
            break;
    }
}


void printPlayerPoints(int p1, int p2) {
    printf("P1\t: %d\nP2\t: %d\n", p1, p2);
}

void printRoundInfo(RoundType t, int dice, int points) {
    printf("Type\t: %s\n", t == BONUS ? "BONUS" : t == DOUBLE ? "DOUBLE" : "REGULAR");
    printf("Dice\t: %d\n", dice);
    printf("Points\t: %d\n", points);
}

