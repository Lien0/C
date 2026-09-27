/*
 * This is a header file to create prototypes or headers.
 * This is functionally to share functions and variables
 * with other files
 */

// game.h
#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <stddef.h>

void Cards(char *shoe);
void Shuffle(char *cards, int length);
int check(char card);
void print_cards(char card);
int actions(int player_cards[], int crup_cards[], int counter, char shoe[]);
int menu_blackjack_windows(void);
int menu_exit(void);
uint32_t random_uniform_win(uint32_t limite);

#endif