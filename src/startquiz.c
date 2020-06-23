/** 
 * @file startquiz.c
 * @author Vimil Rathod
 * @date 22 June 2020
 * @brief Starts the Quiz.
 */

#include "..\include\startquiz.h"
#include "..\include\timer.h"
#include "..\src\timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief Function will start the quiz.
* @author Vimil Rathod
* This Function is used to start the quiz
* This Function will launch the quiz by display each question and respective options for a limited time of 10 seconds, if the user doesn't answer the respective question then the control will be skipped to the next question
* @param[in] No input parameters
* @Return No return value
*
*/

void startquiz(){
	
	    system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\tEnter your name:");
		gets(playername);
		system("cls");
		
		Timer();
		        
}

