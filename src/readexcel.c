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
	/* Abstracting data from the excel file */
        /* open file */

        filehandle = fopen("Book.csv","r");

        /* Read file line by line */

        while (fgets(lyne,1200,filehandle)) {
                printf("%s \n",lyne);

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

        /* Close file */

        fclose(filehandle);
	
}
