/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Main of the system black_jack, it envolve 6 components that help to build all the
 * functionality.
 * gcc -Wall -Wextra -O2 *.c -o blackjack.exe -lsodium
 * $cert = Get-ChildItem Cert:\CurrentUser\Root | Where-Object { $_.Subject -like '*LienCertificado*' } | Select-Object -First 1
Set-AuthenticodeSignature -FilePath .\blackjack.exe -Certificate $cert
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "game.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
int main()
{
    int counter = 0;
    int sum = 0;
    int exit = 0;
    int third_card = 0;
    int is_as = 0;
    int lenght = 156;
    char shoe[156];
    Cards(shoe);
    Shuffle(shoe, 156);
    puts("Welcome to the marvelous Casino of Liera, we´re happy to join us!");
    puts("Black Jack!!");
    puts("I give you two cards and you decide if you want one more, Crupier gives 2 cards and if the result of the");
    puts("addition of the values of the 2 cards is less than 17, Crupier gives one more card.");
    puts("You bust when the addition of your cards is more than 21, you win ");
    puts("when you have a BlackJack!, your hand is closer to 21 than the hand of the Crupier or the hand");
    puts("of the Crupier bust.");
    puts("Cards: |A| |2| |3| |4| |5| |6| |7| |8| |9| |10| |J| |Q| |K|");
    puts("A´s is 1 or 11, J is 10, Q is 10 and K is 10");
    do
    {
        int player_cards[18] = {};
        int crupier_cards[18] = {};
        puts("There is your two cards:");
        player_cards[0] = check(shoe[counter]);
        player_cards[1] = check(shoe[counter + 1]);
        print_cards(shoe[counter]);
        print_cards(shoe[counter + 1]);
        puts("Crupier Cards:");
        crupier_cards[0] = check(shoe[counter + 2]);
        crupier_cards[1] = check(shoe[counter + 3]);
        print_cards(shoe[counter + 2]);
        print_cards(shoe[counter + 3]);
        counter += 4;
        counter = actions(player_cards, crupier_cards, counter, shoe);
        exit = menu_exit();

    } while (!exit || counter <= 126);
}

/*
 * I need to check and review this code, this was created by AI.
 */
int menu_exit(void)
{
    const char *options[] = {
        "Continue",
        "Exit"};
    int total_options = 2;
    int selection = 0;

    while (1)
    {
        // En Windows puedes limpiar pantalla con el comando cls
        // o usando secuencias ANSI si la consola de Windows 10/11 las soporta
        printf("\033[H\033[J");

        printf("=== Do you want to continue? (Arrows Key & Enter) ===\n\n");
        for (int i = 0; i < total_options; i++)
        {
            if (i == selection)
            {
                printf("  -> [ %s ]\n", options[i]);
            }
            else
            {
                printf("      %s\n", options[i]);
            }
        }

        int key_hit = _getch();

        // Si es una tecla especial o flecha, _getch() devuelve 0 o 224 primero
        if (key_hit == 0 || key_hit == 224)
        {
            key_hit = _getch(); // Leer el código real de la tecla extendida
            if (key_hit == KEY_UP)
            {
                selection = (selection - 1 + total_options) % total_options;
            }
            else if (key_hit == KEY_DOWN)
            {
                selection = (selection + 1) % total_options;
            }
        }
        else if (key_hit == KEY_ENTER)
        {
            break;
        }
    }

    return selection;
}