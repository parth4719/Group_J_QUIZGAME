
int updatetextfile (int user_score, char* user_name) {

    /*! \brief Comparing the current score with maximum score through function
     */
    bool result;
    char score_string[5];
    if(user_score != ""){
    	if(user_name != ""){
    		
    		//Here we assume that compare_score will return true
    			//result = compare_score(user_score);
    			result = true;
    			
    			if(result) {
				
		
				FILE *fpw;
				fpw = fopen("maximum.txt", "w");
				if (fpw== NULL){
            		//printf("Issue in opening the Output file");
            		return 0;
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
			//printf("Username missing while updating text !!");
			return 0;
		}
		
	}
	else{
				//printf("User Score missing while updating text !!");
				return 0;
		}
		
	return 1;
 
}



