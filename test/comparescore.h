
int compare_score(int user_score){
	
	if(user_score != ""){
	

	FILE *infile; 

	infile = fopen("maximum.txt", "r");       
	/* relative path for file */

	if ( infile == NULL ) {  
	
    return true;
	}
	
	else{
		
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
    
	int highest_score= atoi(newString[1]);
	

			/* compare highest score with current user socre. return true if user score is higher than highest score else false. */
    
		if(highest_score > user_score){
			return false;
		}
		else{
			return true;
		}
	
  

	}

 
	

	} 
	
	else{
		//printf("\n User score missing at time of compare score !! ");
		return 0;
	}
}


