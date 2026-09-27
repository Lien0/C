/*
 * Created by Enrique Liera Chávez.
 * This is a practice sofware.
 * No licence.
 * Component to take the action for the player decision of his hand.
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "game.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
int actions(int player_cards[], int crup_cards[], int counter, char shoe[])
{
    int selection = 0;
    int index = 2;
    int total = 0;
    int total_crup = 0;
    for (int i = 0; i < 18; i++)
    {
        total += player_cards[i];
        if (total == 21)
        {
            printf("\032[¡BlackJack! ¡You Win!]\032");
            return counter;
        }
    }
    for (int i = 0; i < 18; i++)
    {
        total_crup += crup_cards[i];
        if (total_crup == 21)
        {
            printf("\031[¡BlackJack! ¡You Lose!]\031");
            return counter;
        }
    }
    do
    {
        total = 0;
        for (int i = 0; i < 18; i++)
        {

            if (player_cards[i] != 0)
            {
                if (player_cards[i] == 11 && total != 0)
                {
                    if (total + 11 > 21)
                    {
                        player_cards[i] = 1;
                    }
                }
                total += player_cards[i];
            }
            else
                break;
        }
        printf("Your Score: \036[%i]\036", total);
        if (total >= 22)
        {
            printf("\031[Bust!]\031");
            return counter;
        }
        selection = menu_blackjack_windows();
        if (selection == 0)
        {
            player_cards[index] = check(shoe[counter]);
            print_cards(check(shoe[counter]));
            index++;
            counter++;
        }
    } while (selection == 0);

    index = 2;
    while (total_crup < 17 || total_crup > total)
    {
        for (int i = 0; i < 18; i++)
        {

            if (crup_cards[i] != 0)
            {
                if (crup_cards[i] == 11 && total_crup != 0)
                {
                    if (total_crup + 11 > 21)
                    {
                        crup_cards[i] = 1;
                    }
                }
                total_crup += crup_cards[i];
            }
            else
                break;
        }

        if (total_crup < 17 && total_crup < total)
        {
            crup_cards[index] = check(shoe[counter]);
            print_cards(check(shoe[counter]));
            index++;
            counter++;
        }
        if (total_crup >= 17)
        {
            if (total_crup > 21)
            {
                printf("\032[¡You Win! Crupier Bust]\032");
                return counter;
            }
            else if (total_crup > total)
            {
                printf("\031[¡You Lose!]\031");
                return counter;
            }
            else if (total_crup == total)
            {
                printf("\033[¡It´s a Push!]\033");
                return counter;
            }
            else if (total_crup < total)
            {
                printf("\032[¡You Win!]\032");
                return counter;
            }
        }
    }
    return counter;
}

/*
 * I need to check and review this code, this was created by AI.
 */
int menu_blackjack_windows(void)
{
    const char *options[] = {
        "Hit",
        "Stand"};
    int total_options = 2;
    int selection = 0;

    while (1)
    {
        // En Windows puedes limpiar pantalla con el comando cls
        // o usando secuencias ANSI si la consola de Windows 10/11 las soporta
        printf("\033[H\033[J");

        printf("=== Your Turn (Arrows Key & Enter) ===\n\n");
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