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
#include <stdbool.h>

/* Function declaration*/

void swap(int *a, int *b);
void randomize(int arr[], int n);

/* Variable declaration*/

FILE * filehandle;
char lyne[121];
char *item;
int reccount = 0;
int arr[] = {};
char userinput[] = {};
int user_score, highest_score;

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
	 	
	switch(choice){
    default:
        printf("Wrong Entry!!");
        printf("Press any key and re-enter correct option");
    case 'Q':
        quit();
	case 'H':
        help();
		getch();
		goto mainhome;
    case 'R':
        reset_score();
		getch();
		goto mainhome;

    case 'V':
        display_score();
		goto mainhome;   
	case 'S':
        system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\tEnter your name:");
		gets(playername);
		
		system("cls");
		int i;
		for (i=0; i<reccount-1; i++) {
        	
        		int index = arr[i];
        		char Answer;
        		int count=10;
        		
        		// All Questions and four option will be printed
                while(count>0&&_kbhit()==0)
                {
                	printf("\n\n");
                	printf("%d\n",i+1);
                	printf("%s?\n",record[index].que);
                	printf("A.%s\t",record[index].opt1);
                	printf("B.%s\t",record[index].opt2);
                	printf("C.%s\t",record[index].opt3);
                	printf("D.%s\t",record[index].opt4);
                	printf("\n\n\n Time Remaining: %d\t",count);
					count--;
                	sleep(1);
                	system("cls");
                }
                	if (kbhit()==0)
					{
						// timer overflow
						userinput[i] = "0";
					}
					else
					{
						// user input
						char temp= toupper(getch());
						userinput[i] = temp;
					}

                system("cls");
            
            }
            
         user_score = calculatescore(userinput);
			
		}
	 	if(updatetextfile(user_score,playername) == true){
			printf("congratulations your score is highest score");
			printf("Your score is : %d",user_score );
		}
		else{
			printf("Your score is : %d",user_score );
			printf("sorry! your score is not highest score");
		}

    return 0;
}

/**
* @brief Function calculate user score.
* @author Vimil Rathod
* The function use to calculate score based on user answer given at time of quiz
* Function will match all the given answer with the correct answer stored in excel file  
* @param[in] char userinput[], array of chracter that has value given by the user
* @param[in] pointer to second array element
* @Return int value of total score of the user
*
*/


int calculatescore(char userinput[]){
			int t;
			int count = 0;
            for (t=0; t<reccount-1; t++){
            	
            	char* pPosition = strchr(record[t].ans, userinput[t]);
            	if(pPosition != 0){
            		//printf("1");
            		count++;
				}
				else{
            		//printf("0");
				}
			}
			return count;
				
}


/**
* @brief The Swap function will to exchange data.
* @author Pavan Patel
* The function is part of randomize() function.
* Function will switch each other data and store the result value at each other address  
* @param[in] pointer to one of the array element
* @param[in] pointer to second array element
*
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


bool updatetextfile (int user_score, char* user_name) {

    /*! \brief Comparing the current score with maximum score through function
     */
    bool result;
 	result = compare_score(user_score);
    if(result) {
		/*! \brief Updating the score as the current score is maximum
			*/
		FILE *fpw;
		fpw = fopen("../data/maximum.txt", "w");
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

bool compare_score(){

	FILE *infile; 

	infile = fopen("../data/maximum.txt", "r");       
	/* relative path for file */

	if ( infile == NULL ) {  
	/* error checking with fopen call */
    printf("Unable to open file."); 
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

/**
* @author Parth Patel
* @brief  The function display the highest score user recorded in the system.
 	
	 */ 
void display_score(){
	system("cls");
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t Secured Highest Score is %d",highest_score);
	printf("\n\n\t\t*************************************************************");
	getch();
}

/**
* @author Parth Patel
* @brief   	The function terminate all the ongoing process and exit.
	 */ 
void quit(){
	exit(1);
}

/**
 * @author Hitul Shah
 * \fn void reset_score()
 * @brief 	The function will reset the maximum.txt file with 0 score.
 */
void reset_score(){
	system("cls")
	FILE *f;
	f=fopen("../data/maximum.txt","w");
	char reset_string = 'reset,0';
 	fputs(reset_string, f);
    fclose(f);
	}

/** 
 * @author Hitul Shah
 * \fn void help()
 * @brief The function will provide the basic informations and the rules of the quiz game to the player.
 */
void help(){
	system("cls");
    printf("\n\n                      HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ................Quick Quiz Game...........");
    printf("\n ----> There are ten questions in the game");
    printf("\n ----> You can earn one point for each correct answer");
    printf("\n ----> Maximum 10 seconds are given for each question ");
	printf("\n ----> You will be given 4 options and you have to press A, B ,C or D for ");
    printf("\n       the right option");
    printf("\n ----> You will be asked questions continuously even if your answer is incorrect.");
    printf("\n ----> There are no negative markings for wrong answers");
	printf("\n\n\t**************Good LUCK**************");
}
