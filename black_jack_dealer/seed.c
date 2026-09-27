/*
* Created by Enrique Liera Chávez.
* This is a practice sofware.
* No licence.
* Component from the main game of blackjack.
* Obtain seed with bcrypt, enter the limit and return the seed
*/
#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include <bcrypt.h>

uint32_t random_uniform_win(uint32_t limit){
    if (limit < 1){
        puts("Error during introducing seed");
        return 0;
    }

    uint32_t min = -limit % limit;
    uint32_t r;

    do{
        BCryptGenRandom(NULL, (PUCHAR)&r, sizeof(r), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
    } while(r < min);

    return r % limit;
}