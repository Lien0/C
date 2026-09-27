/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Component to assign values to the cards.
 */
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int check(char card)
{
    if (card == 'T' || card == 'J' || card == 'Q' || card == 'K')
        return 10;
    if (card == 'A')
        return 11;
    return card - '0';
}