/**
* \file main.c
*
* Contains the main function from which different functions
* located in other files are called to perform different
* tasks excel based on the
* user inputs.
*
*/


#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>


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

FILE * filehandle;
char lyne[121];
char *item;
char choice;
int user_score;



int main() {
	
/**
* \brief The main function which distributes various tasks to other functions.
* @author Pavan Patel
* @author Vimil Rathod
* @author Hitul Shah
* @author Parth Patel
* @Extract data from excel that is in csv format - comma seperated
* Based on the data retrieved from the file it will be further seperated and stored in array of structure.
* and this data will be used further in quiz.
*
*/
	
        /* Abstracting data from the excel file */
        /* open file */

        filehandle = fopen("Book.csv","r");

        /* Read file line by line */

        while (fgets(lyne,1200,filehandle)) {
                printf("%s \n",lyne);

                item = strtok(lyne,",");
                strcpy(record[reccount].que,item);

                item = strtok(NULL,",");
                strcpy(record[reccount].opt1,item);

                item = strtok(NULL,",");
                strcpy(record[reccount].opt2,item);

                item = strtok(NULL,",");
                strcpy(record[reccount].opt3,item);
                
                item = strtok(NULL,",");
                strcpy(record[reccount].opt4,item);
                
                item = strtok(NULL,"\n");
                strcpy(record[reccount].ans,item);

                reccount++;
                }

        /* Close file */

        fclose(filehandle);
        
        //Removing header element of excel store at index1
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
	 	//Starting the quiz
	 	displayquiz();
	 	
	 	choice=toupper(getch());
	switch(choice){
    default:
        printf("Wrong Entry!!");
        printf("Press any key and re-enter correct option");
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
			sleep(5);
		}
    return 0;
}
