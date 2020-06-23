/** 
 * @author Hitul Shah
 * \fn bool updatetextfile (int user_score, char* user_name)
 *	@param[in] int user_score score achieved by the user in current quiz game as integer.
 *	@param[in] char* user_name pointer user_name which stores the user name as a string.
 *	@return Boolean true if file is changed else false
 * @brief 	Initially, function will create file having data of the first user name with score gained by him/her.
 *   The function observes the Boolean value of the bool compare_score (int user_score); which generates true if highest score is achieved or false if user achieves comparatively lower score. 
 *   If bool compare_score (int user_score) generates true, then file will be updated by the new data base (new high score and user name who achieved it). 
 *   If bool compare_score (int user_score) generates false, then file will not be updated. 
 *   If function overrides the file with new data, then it returns true, else it is false.
 */

#include "../include/updatetextfile.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


bool updatetextfile (int user_score, char* user_name) {

    /*! \brief Comparing the current score with maximum score through function
     */
    bool result;
 	result = compare_score(user_score);
    if(result) {
		/*! \brief Updating the score as the current score is maximum
			*/
		FILE *fpw;
		fpw = fopen("data\\maximum.txt", "w");
        char score_string[5];
        sprintf(score_string, "%d", user_score);
        char result_string[100];
        strcpy(result_string, user_name);
        strcat(result_string, ",");
        strcat(result_string,score_string);
        if (fpw== NULL){
            puts("Issue in opening the Output file");
        }
        fputs(result_string, fpw);
        fclose(fpw);
        return true;
    }   else {
        return false;
    }
}
