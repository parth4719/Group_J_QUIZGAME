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
* @author Pavan Patel
* @Extract data from excel that is in csv format - comma seperated
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
	 	
	 	//Starting the quiz
	 	char choice = startquiz();
	 	
    return 0;
}

/**
* @brief The Swap function will to exchange data.
* @author Pavan Patel
* The function is part of randomize() function.
* Function will switch each other data and store the result value at each other address  
*
* @param[in] pointer to one of the array element
* @param[in] pointer to second array element
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* @brief The randomize function which change the order of elements in array.
* @author Pavan Patel
* The funtion will take any element on random basis and pass to swap() function.
* Two of these element will swap each other place and loop continues untill all elements are swapped 
* and this data will be changed every time whenever user takes quiz.
* @param[in] arr[] integer array
* @param[in] n No of elements in array
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



/**
* @brief The start quiz function will intiate first display screen.
* @author Pavan Patel
* The funtion will display multiple option to select for the user.
* The function will wait for the user input and then store the result 
* At the end choice of the user will be returned to main function.
* @Return char choice that is user input

*
*/
char startquiz() {
     char choice;
     printf("\n \t\t------------ Quiz Game -----------------");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      to ");
     printf("\n\t\t\t   THE QUIZ GAME ");
     printf("\n\t\t________________________________________");
     
     printf("\n\t\t > Press S to start the game");
     printf("\n\t\t > Press V to view the highest score  ");
     printf("\n\t\t > Press R to reset score");
     printf("\n\t\t > press H for help            ");
     printf("\n\t\t > press Q to quit             ");
     printf("\n\t\t________________________________________\n\n");

    choice=toupper(getch());
    return choice;
}

