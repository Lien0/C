/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Component to print cards based on the values.
 */
#define CARD_LINES 7
#define TOTAL_CARDS 13
void print_cards(char card_name[3])
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
    if(card_name[0] == 'J')
        for(int line = 0; line < CARD_LINES; line++){
            printf("%s\n", cards[10][line]);
        }
    else if (card_name[0] == 'Q')
        for(int line = 0; line < CARD_LINES; line++){
            printf("%s\n", cards[11][line]);
        }
    else if (card_name[0] == 'K')
        for(int line = 0; line < CARD_LINES; line++){
            printf("%s\n", cards[12][line]);
        }
    else if (card_name[0] == 'T')
        for(int line = 0; line < CARD_LINES; line++){
            printf("%s\n", cards[9][line]);
        }
    else if (card_name[0] == 'A')
        for(int line = 0; line < CARD_LINES; line++){
            printf("%s\n", cards[0][line]);
        }
    else{
        val = atoi(card_name);
         for(int line = 0; line < CARD_LINES; line++){
            printf("%s\n", cards[val - 1][line]);
        }
    }

}