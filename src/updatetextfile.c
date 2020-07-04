
/** 
 * @file updatetextfile.c
 * @author Hitul Shah
 * @brief update the highest score of the player in the file.
 */

/** 
 * \fn bool updatetextfile (int user_score, char* user_name)
 *  @author Hitul Shah
 *  @brief Initially, function will create file having data of the first user name with score gained by him/her.
 *  The function observes the Boolean value of the bool compare_score (int user_score); which generates true if highest score is achieved or false if user achieves comparatively lower score. 
 *  If bool compare_score (int user_score) generates true, then file will be updated by the new data base (new high score and user name who achieved it). 
 *  If bool compare_score (int user_score) generates false, then file will not be updated. 
 *  If function overrides the file with new data, then it returns true, else it is false.
 *  @param[in] int user_score score achieved by the user in current quiz game as integer.
 *	@param[in] char* user_name pointer user_name which stores the user name as a string.
 *	@return Boolean true if file is changed else false
 */

#include "../include/updatetextfile.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


bool updatetextfile (int user_score, char* user_name) {

    /*! \brief Comparing the current score with maximum score through function
     */
    bool result;
    char score_string[5];
    if(user_score != '\0'){
    	if(user_name != '\0'){
    		
    		
    			result = compare_score(user_score);
    			
    			
    			if(result) {
				
		
				FILE *fpw;
				fpw = fopen("data\\maximum.txt", "w");
				if (fpw== NULL){
            		printf("Issue in opening the Output file");
            		exit(0);
        		}
        		
        		sprintf(score_string, "%d", user_score);
        		char result_string[100];
        		strcpy(result_string, user_name);
        		strcat(result_string, ",");
        		strcat(result_string,score_string);
        		
        		fputs(result_string, fpw);
        		fclose(fpw);
        		return true;
    			}   
				else {
        			return false;
    			}	
		}
		else{
			printf("Username missing while updating text !!");
			
			exit(0);
		}
		
	}
	else{
				printf("User Score missing while updating text !!");
				
				exit(0);
		}
 
}


