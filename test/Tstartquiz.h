/** 
 * @file startquiz.c
 * @author Vimil Rathod
 * @date 22 June 2020
 * @brief Starts the Quiz.
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief Function will start the quiz.
* @author Vimil Rathod
* This Function is used to start the quiz
* This Function will launch the quiz by display each question and respective options for a limited time of 10 seconds, if the user doesn't answer the respective question then the control will be skipped to the next question
* @param[in] No input parameters
* @return No return value
*
*/

int startquiz(){
	
	    char playername[20] = "Vimil";
		
		if (strlen(playername)>10){
			printf("Player's Name cannot be longer than 10 characters");
			return 0;
		}
		system("cls");
		
	
		return 1;
		        
}

