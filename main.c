/**
 * @file main.c
 * @author Pavan Patel
 * @author Vimil Rathod
 * @author Hitul Shah
 * @author Parth Patel
 * @brief Processing of input file, calling different functions from other files to perform the different 
 tasks to compute output(score) and storing data in output file.
 * \mainpage This program is designed to extracts data from excel that is in csv format - comma seperated and based on the data retrieved from the file which will be further seperated and stored in array of structure and this data will be used to do further funcionality in the quiz, i.e., calcuate_score, compare_score, reset_score, timer, help, display_score, etc and at the end of the quiz, it generates highest score with the name of the player in the output text file. 
 * Input file is a .csv containing data of the quiz. File contains the questions and their corresponding answers of the quiz.
 * Output file contains the data of the player name and the highest score achieved among all players.    
*/

#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

/* Include all dependencies */

#include "include\readexcel.h"
#include "src\readexcel.c"
#include "include\startquiz.h"
#include "src\startquiz.c"
#include "include\calculatescore.h"
#include "src\calculatescore.c"
#include "include\displayquiz.h"
#include "src\displayquiz.c"
#include "include\swap.h"
#include "src\swap.c"
#include "include\randomize.h"
#include "src\randomize.c"
#include "include\reset_score.h"
#include "src\reset_score.c"
#include "include\help.h"
#include "src\help.c"
#include "include\compare_score.h"
#include "src\compare_score.c"
#include "include\updatetextfile.h"
#include "src\updatetextfile.c"
#include "include\display_score.h"
#include "src\display_score.c"
#include "include\quit.h"
#include "src\quit.c"


/* Variable declaration*/


char choice;
int user_score;



int main() {
	
/**
* \brief The main function which distributes various tasks to other functions.
* @author Pavan Patel
* @author Vimil Rathod
* @author Hitul Shah
* @author Parth Patel
*
*/
		readexcel();
                
        //Removing header element of excel data  store in array of structure at index1
        int c;
        for (c = 0; c < reccount - 1; c++)
        record[c] = record[c+1];
        
        //Creating random array
        for (c = 0; c < reccount - 2; c++)
        arr[c] = c;

        /* Randomizing the data */
		int n = reccount - 1;
	 	randomize (arr, n);
	 	
	 	mainhome:
	 	//Displaying the quiz
	 	displayquiz();
	 	
	 	//Getting user input
	 	choice=toupper(getch());
	 	
	 	
	switch(choice){
    default:
        printf("\n\nWrong Entry!!!\n");
        printf("Please re-enter the correct option");
        sleep(5);
        goto mainhome;
    case 'Q':
        quit();
	case 'H':
        help();
		getch();
		goto mainhome;
    case 'R':
        reset_score();
        getch();
		goto mainhome;

    case 'V':
        display_score();
        getch();
		goto mainhome;   
	
    case 'S':
    	startquiz();
        user_score = calculatescore(userinput);
			
		}
		
	 	if(updatetextfile(user_score,playername) == true){
	 		highest_score = user_score;
			printf("\n Your score is : %d",user_score );
			printf("\n Congratulations, your score is the 'New highest score!'");
		}
		else{
			printf("\n Your score is : %d",user_score );
			printf("\n Unfortunately, your score is not the highest score!");
			getch();
		}
		
    return 0;
}
