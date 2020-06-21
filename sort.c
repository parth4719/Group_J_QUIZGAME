/**
* \file main.c
*
* Contains the main function from which different functions
* located in other files are called to perform different
* tasks excel based on the
* user inputs.
*
*/


#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/* Function declaration*/

void swap(int *a, int *b);
void randomize(int arr[], int n);

/* Variable declaration*/

FILE * filehandle;
char lyne[121];
char *item;
int reccount = 0;
int k,l,m;
int arr[] = {};


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

int main() {
	
/**
* \brief The main function which distributes various tasks to other functions.
*
* Extract data from excel that is in csv format - comma seperated
* Based on the data retrieved from the file it will be further seperated and stored in array of structure.
* and this data will be used further in quiz.
*
*/
	
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
        
        //Removing header element of excel store at index1
        int c;
        for (c = 0; c < reccount - 1; c++)
        record[c] = record[c+1];
        
        //Creating random array
        for (c = 0; c < reccount - 2; c++)
        arr[c] = c;

        /* Randomizing the data */
		int n = reccount - 1;
	 	randomize (arr, n);
	 	
    return 0;
}

/**
* \brief The Swap function will to exchange data.
*
* The function is part of randomize() function.
* Function will switch each other data and store the result value at each other address  
*1
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* \brief The randomize function which change the order of elements in array.
*
* The funtion will take any element on random basis and pass to swap() function.
* Two of these element will swap each other place and loop continues untill all elements are swapped 
* and this data will be changed every time whenever user takes quiz.
*
*/
void randomize(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

