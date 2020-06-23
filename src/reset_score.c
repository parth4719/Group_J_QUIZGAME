/**
 * @author Hitul Shah
 * \fn void reset_score()
 * @brief 	The function will reset the maximum.txt file with 0 score.
 */

#include <stdio.h>
#include <string.h>
#include "../include/reset_score.h"

void reset_score(){
	system("cls");
	FILE *f;
	f=fopen("data\\maximum.txt","w");
	char reset_string[] = "reset,0";
 	fputs(reset_string, f);
    fclose(f);
    printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t        The Highest Score is reinitialized to 'Zero'");
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\n\n\n\n\n\n\t\tPress any Key to return to the main menu of the game");
	}

