/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Component to assign values to the cards.
 */
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int check(char card_name[3])
{
    int val = 0;
    if (card_name[0] == 'J')
        val = 10;
    else if (card_name[0] == 'Q')
        val = 10;
    else if (card_name[0] == 'K')
        val = 10;
    else if (card_name[0] == 'T')
        val = 10;
    else if (card_name[0] == 'A')
        val = 11;
    else
        val = atoi(card_name);

    return val;
}