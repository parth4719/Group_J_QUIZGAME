/**
* @author Parth Patel
* \fn bool compare_score(int user_score, int highest_score)
* @param[in] int user_score achieved by the user in current quiz game in terms of the integer.
* @param[in] int highest_score ever scored in the game in terms of integer.
* @return Boolean true if user_score is greater than highest_score else false
* @brief  The function compares user_score with the existed highest_score stored in the text file.
 	* The function will return true if highest_score needs to be updated for current user else it will return false if not needed. 
 	* If there is no highest score stored in the text file, the function updateTextFile will generate a new text file named highest_score.
	 
	 */ 

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../include/compare_score.h"


bool compare_score(int user_score){

	FILE *infile; 

	infile = fopen("data\\maximum.txt", "r");       
	/* relative path for file */

	if ( infile == NULL ) {  
	/* error checking with fopen call */
    //printf("Parth : Unable to open file."); 
    return true;
	} 

	char outstream[255];

	fscanf(infile, "%s", outstream); 

	/* get two string value username and highest score. */

	int i=0,j=0, ctr=0;
	char newString[10][10]; 
	
	/* seperate two string. */
 
	for(i=0;i<=(strlen(outstream));i++){
    /* if space or NULL found, assign NULL into newString[ctr] */
    if(outstream[i]==','||outstream[i]=='\0'){
        newString[ctr][j]='\0';
        ctr++;  /*for next word */
        j=0;    /*for next word, init index to 0 */
        }
    else{
        newString[ctr][j]=outstream[i];
        j++;
        }
	}
    
	fclose(infile); 

	/* convert highest score string value into integer value.*/
    
	highest_score= atoi(newString[1]);
  
	/* compare highest score with current user socre. return true if user score is higher than highest score else false. */
    
	if(highest_score > user_score){
		return false;
	}
	else{
		return true;
	}
}
