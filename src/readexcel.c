/** 
 * @file readexcel.c
 * @author Pavan Patel
 * @date 22 June 2020
 * @brief Read Excel data.
 */

#include "..\include\timer.h"
#include "..\include\readexcel.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* @brief Function will be able to get data from comma seperated csv file
* @author Pavan Patel
* Based on the data retrieved from the file it will be further seperated and stored in array of structure.
* and this data will be used further in quiz.
* @param[in] No input parameters
* @return No return value
*
*/

void readexcel(){
	FILE * filehandle;
	char lyne[121];
	char *item;
	char filename[100] = "Book.csv";

	
	
	if (filename[0]){
		
		/* open file */

        filehandle = fopen(filename,"r");

		if ( filehandle == NULL ) { 
		 
			/* error checking with fopen call */
    		printf("Data File with given name not found"); 
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
							printf("Incorrect data format");
						 exit(0);
						
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"A") == 0){
                			 strcpy(record[reccount].opt1,item);
						}
						else{
							printf("Incorrect data format");
							 exit(0); 
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"B") == 0){
                			 strcpy(record[reccount].opt2,item);
						}
						else{
							printf("Incorrect data format");
							  exit(0);
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"C") == 0){
                			 strcpy(record[reccount].opt3,item);
						}
						else{
							printf("Incorrect data format"); 
							exit(0); 
						}
						
						item = strtok(NULL,",");
                		if(strcmp(item,"D") == 0){
                			 strcpy(record[reccount].opt4,item);
						}
						else{
							printf("Incorrect data format \n"); 
						 exit(0);
						}
						
						item = strtok(NULL,"\n");
						if(strcmp(item,"Ans") == 0){
							
                			 strcpy(record[reccount].ans,item);
						}
						else{
							printf("Incorrect data format \n");
								 exit(0);
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
    		printf("Please provide name of the data  file"); 
    		exit(0);
    		
	}
        
	
}
