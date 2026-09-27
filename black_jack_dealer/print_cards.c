/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Component to print cards based on the values.
 */
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

#define CARD_LINES 7
#define TOTAL_CARDS 13
void print_cards(char card)
{

    // Arreglo con las 13 cartas representadas como 7 líneas de texto cada una
    const char *cards[TOTAL_CARDS][CARD_LINES] = {
        // As
        {"+-------+",
         "|A      |",
         "|       |",
         "|   A   |",
         "|       |",
         "|      A|",
         "+-------+"},
        // 2
        {"+-------+",
         "|2      |",
         "|   *   |",
         "|       |",
         "|   *   |",
         "|      2|",
         "+-------+"},
        // 3
        {"+-------+",
         "|3      |",
         "| *     |",
         "|   *   |",
         "|     * |",
         "|      3|",
         "+-------+"},
        // 4
        {"+-------+",
         "|4      |",
         "| *   * |",
         "|       |",
         "| *   * |",
         "|      4|",
         "+-------+"},
        // 5
        {"+-------+",
         "|5      |",
         "| *   * |",
         "|   *   |",
         "| *   * |",
         "|      5|",
         "+-------+"},
        // 6
        {"+-------+",
         "|6      |",
         "| *   * |",
         "| *   * |",
         "| *   * |",
         "|      6|",
         "+-------+"},
        // 7
        {"+-------+",
         "|7      |",
         "| *   * |",
         "| * * * |",
         "| *   * |",
         "|      7|",
         "+-------+"},
        // 8
        {"+-------+",
         "|8      |",
         "| * * * |",
         "|  * *  |",
         "| * * * |",
         "|      8|",
         "+-------+"},
        // 9
        {"+-------+",
         "|9      |",
         "| * * * |",
         "| * * * |",
         "| * * * |",
         "|      9|",
         "+-------+"},
        // 10 (Notar ajuste de padding a la derecha por ocupar 2 dígitos)
        {"+-------+",
         "|10     |",
         "| * * * |",
         "|* * * *|",
         "| * * * |",
         "|     10|",
         "+-------+"},
        // Jack (J)
        {"+-------+",
         "|J      |",
         "|   _   |",
         "|   |   |",
         "| `-'   |",
         "|      J|",
         "+-------+"},
        // Queen (Q)
        {"+-------+",
         "|Q      |",
         "|  ___  |",
         "| (   ) |",
         "|  `-\\| |",
         "|      Q|",
         "+-------+"},
        // King (K)
        {"+-------+",
         "|K      |",
         "| | /   |",
         "| |<    |",
         "| | \\   |",
         "|      K|",
         "+-------+"}};

    int val = 0;
    if (card == 'J')
        for (int line = 0; line < CARD_LINES; line++)
        {
            printf("%s\n", cards[10][line]);
        }
    else if (card == 'Q')
        for (int line = 0; line < CARD_LINES; line++)
        {
            printf("%s\n", cards[11][line]);
        }
    else if (card == 'K')
        for (int line = 0; line < CARD_LINES; line++)
        {
            printf("%s\n", cards[12][line]);
        }
    else if (card == 'T')
        for (int line = 0; line < CARD_LINES; line++)
        {
            printf("%s\n", cards[9][line]);
        }
    else if (card == 'A')
        for (int line = 0; line < CARD_LINES; line++)
        {
            printf("%s\n", cards[0][line]);
        }
    else
    {
        val = atoi(card);
        for (int line = 0; line < CARD_LINES; line++)
        {
            printf("%s\n", cards[val - 1][line]);
        }
    }
}