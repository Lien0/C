/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Component from the main game of blackjack.
 * Shuffle with algorithm Fisher Yates Shuffle, obtain seed from seed.c
 * Get array cards and return a shuffle array cards
 * Obtains a shuffle without sesgo.
 */
#include "game.h"
#include <stdint.h>

char Shuffle(char *cards, int lenght)
{
    uint32_t j = random_uniform_win(lenght - 1);
    for (int i = lenght - 1; i >= 0; i--)
    {
        char temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}