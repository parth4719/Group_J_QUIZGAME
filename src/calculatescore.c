/** 
 * @file calculatescore.c
 * @author Vimil Rathod
 * @date 22 June 2020
 * @brief Calculates the final score.
 */

#include "..\include\calculatescore.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief Function will calculate user's final score.
* @author Vimil Rathod
* This function is used to calculate user's final score based on user's answers to individual questions provided at the time of the quiz
* Function will compare all the given answers with the correct answers stored in the excel file  
* @param[in] char userinput[], array of chracters containing answers provided by the user
* @return int Value of total score of the user
*
*/


int calculatescore(char userinput[]){
	        //Testing Validation
	        //printf("%d",strlen(userinput));
	        int q_size = reccount-1;
	        if (userinput == 0){
	        	printf("User Input array cannot be empty");
				sleep(3);
				exit(1);
			}
			if (q_size == 0){
				printf("questions array cannot be empty");
				sleep(3);
				exit(1);
			}
			if (strlen(userinput) == 0){
	        	printf("The length of User Input array cannot be zero");
				sleep(3);
				exit(1);
			}
	        if (strlen(userinput) != q_size){
	        	printf("The lengths of both the arrays should be equal");
				sleep(3);
				exit(1);
			}
			
			//Function Implementation
			int t;
			int count = 0;
            for (t=0; t<reccount-1; t++){
            	
            	char* pPosition = strchr(record[t].ans, userinput[t]);
            	if(pPosition != 0){
            		//printf("1");
            		count++;
				}
				else{
            		//printf("0");
				}
			}
			return count;
				
}


