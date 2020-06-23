
/** 
 * @file help.c
 * @author Hitul Shah
 * @brief The function will provide the basic informations and the rules of the quiz game.
 */
/**
 * \fn void help()
 * @author Hitul Shah
 * @brief The function gives the informations like, number of options and earing points per question in the quiz.
 * @param[in] void
 * @return void
 */
 
#include "..\include\help.h"
#include <stdio.h>

void help(){
	system("cls");
    printf("\n\n                      HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ................Quick Quiz Game...........");
    printf("\n ----> There are ten questions in the game");
    printf("\n ----> You can earn one point for each correct answer");
    printf("\n ----> Maximum of 10 seconds are given for each question ");
	printf("\n ----> You will be given 4 options and you have to press A, B ,C or D for ");
    printf("\n       the right option");
    printf("\n ----> You will be asked questions continuously even if your answer is incorrect.");
    printf("\n ----> There is no negative marking for wrong answers");
	printf("\n\n\t**************Good LUCK**************");
	printf("\n\n\n\n\n\n\n\nPress any Key to return to the main menu of the game");
}

