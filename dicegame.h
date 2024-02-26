#ifndef DICEGAME_H //Header guard
#define DICEGAME_H

typedef enum { //Enum for round types
    BONUS,
    DOUBLE,
    REGULAR
} RoundType;

typedef struct { //Structure which can be referred to with pointers of the variable type Round
    int dice;
    int points;
    RoundType type;
} Round; //"New variable type"

//Function prototypes
int getRandomNumber(int min, int max);
RoundType getRoundType();
int getRoundPoints(RoundType roundType);
void generateRound(Round *round);
void printPlayerPoints(int p1, int p2);
void printRoundInfo(RoundType t, int dice, int points);

#endif
