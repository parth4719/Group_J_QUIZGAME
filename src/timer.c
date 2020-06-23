/** 
 * @file startquiz.c
 * @author Vimil Rathod
 * @date 22 June 2020
 * @brief Starts the Timer.
 */

#include "..\include\timer.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief Function will incorporate a timer of 10 seconds during each question of the quiz
* @author Vimil Rathod
* This Function is used to limit the amount of time given to a user to solve a question to 10 seconds
* @param[in] No input parameters
* @Return No return value
*
*/

void Timer(){
	    int i;
		for (i=0; i<reccount-1; i++) {
        	
        		int index = arr[i];
        		int count=10;
        		
        		// All Questions and four option will be printed, one a time with a timer of 10 seconds
                while(count>0&&_kbhit()==0)
                {
                	printf("\n\n");
                	printf(" %d]\n\n",i+1);
                	printf(" Question:  %s\n\n",record[index].que);
                	printf(" Options:   A.%s",record[index].opt1);
                	printf("  B.%s",record[index].opt2);
                	printf("  C.%s",record[index].opt3);
                	printf("  D.%s",record[index].opt4);
                	printf("\n\n\n\n Time Remaining: %d\t",count);
					count--;
                	sleep(1);
                	system("cls");
                }
                	if (kbhit()==0)
					{
						// timer overflow
						userinput[i] = '0';
					}
					else
					{
						// user input
						char temp= toupper(getch());
						userinput[i] = temp;
					}

                system("cls");
            
            }
}

