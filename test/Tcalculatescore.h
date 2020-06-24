/** 
 * @file calculatescore.c
 * @author Vimil Rathod
 * @date 22 June 2020
 * @brief Calculates the final score.
 */

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

int calculatescore(char userinput[]);

        typedef struct {
                char que[1000]; 
				char opt1[100]; 
                char opt2[100]; 
				char opt3[100];
				char opt4[100];
				char ans[100];
        } data ;

        data record[300];
        
int reccount = 0;
int arr[] = {};
char userinput[] = {};


int calculatescore(char userinput[]){
	
	        //Testing Validation
	        
	        //Assuming array of que size is 10
	        int q_size = 10;
	        
			if (q_size == 0){
				printf("questions array cannot be empty");
				return 0;
			}
			if (strlen(userinput) == 0){
	        	printf("The length of User Input array cannot be zero");
				return 0;
			}
	        if (strlen(userinput) != q_size){
	        	printf("The lengths of both the arrays should be equal");
				return 0;
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
			return 1;
				
}


