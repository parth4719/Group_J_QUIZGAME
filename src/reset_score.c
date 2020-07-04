/**
 * @file reset_score.c
 * @author Hitul Shah
 * @brief The function will reset the maximum.txt file with 0 score.
 */
/**
 * 
 * \fn void reset_score()
 * @author Hitul Shah
 * @brief The function will put the 0 score in the output 'maximum.txt' file.
 * @param[in] void
 * @return void
 */

#include <stdio.h>
#include <string.h>
#include "../include/reset_score.h"

void reset_score(){
    system("cls");
	FILE *f;
	f=fopen("data\\maximum.txt","w");
    char reset[100];
    strcat(reset, "reset,0");
    fputs(reset, f);
    fclose(f);
    printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t        The Highest Score is reinitialized to 'Zero'");
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\n\n\n\n\n\n\t\tPress any Key to return to the main menu of the game");
	}


