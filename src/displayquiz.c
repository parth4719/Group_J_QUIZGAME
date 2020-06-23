/** 
 * @file displayquiz.c
 * @author Pavan Patel
 * @date 22 June 2020
 * @brief Displays the Main Menu of the Quiz.
 */

#include "..\include\displayquiz.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
* @brief The start quiz function will display the Main Menu of the quiz.
* @author Pavan Patel
* The funtion will display multiple options to select from, for the user.
* The function will wait for the user input and then store the result 
* At the end, choice of the user will be returned to the main function.
* @Return char choice that is user input
*
*/
void displayquiz() {
	
	system("cls");
     
     printf("\n \t\t--------------- Quiz Game --------------");
     printf("\n\t\t________________________________________");

     printf("\n\n\t\t\t         WELCOME ");
     printf("\n\t\t\t         to  the");
     printf("\n\t\t\t        QUIZ GAME ");
     printf("\n\t\t________________________________________");
     
     printf("\n\n\t\t > Press S to start the game");
     printf("\n\t\t > Press V to view the highest score  ");
     printf("\n\t\t > Press R to reset score");
     printf("\n\t\t > press H for help            ");
     printf("\n\t\t > press Q to quit             ");
     printf("\n\t\t________________________________________\n\n");

}

