


int readexcel(){
	FILE * filehandle;
	char lyne[121];
	char *item;
	char filename[100] = "testbook.csv";
	/* Define a structure */
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
	
	
	if (filename[0]){
		
		/* open file */

        filehandle = fopen(filename,"r");

		if ( filehandle == NULL ) { 
		 
			/* error checking with fopen call */
    		//printf("Data File with given name not found"); 
    		return 0; 
    		exit(0);
    		
		} 
		else{
		
			/* Read file line by line */

        	while (fgets(lyne,1200,filehandle)) {

				if(reccount == 0){
						
						item = strtok(lyne,",");
                		if(strcmp(item,"Question") == 0){
                			strcpy(record[reccount].que,item);
						}
						else{
							//printf("Incorrect data format");
							return 0;  
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"A") == 0){
                			 strcpy(record[reccount].opt1,item);
						}
						else{
							//printf("Incorrect data format");
							return 0;  
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"B") == 0){
                			 strcpy(record[reccount].opt2,item);
						}
						else{
							//printf("Incorrect data format");
							return 0;  
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"C") == 0){
                			 strcpy(record[reccount].opt3,item);
						}
						else{
							//printf("Incorrect data format"); 
							return 0; 
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"D") == 0){
                			 strcpy(record[reccount].opt4,item);
						}
						else{
							//printf("Incorrect data format \n"); 
							return 0; 
						}
						
						item = strtok(NULL,"\n");
						if(strcmp(item,"Ans") == 0){
							
                			 strcpy(record[reccount].ans,item);
						}
						else{
							//printf("Incorrect data format \n");
								return 0; 
						}

                	reccount++;
				}
				else{
					
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
                
            }

		}
        
        /* Close file */

        fclose(filehandle);
    	
        
	}
	else{
			/* error checking null file name */
    		//printf("Please provide name of the data  file"); 
    		return 0; 
    		exit(0);
	}
    return 1;    
	
}



