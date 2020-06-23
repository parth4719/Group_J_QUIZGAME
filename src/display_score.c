/**
* @file display_score.c
* @author Parth Patel
* @brief  The function display the highest score user recorded in the system.
*/ 
/**
* @fn void display_score()
* @author Parth Patel
* @brief  The function display the highest score user recorded in the system.
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "..\include\display_score.h" 
	 
void display_score(){
	FILE *infile;
	infile = fopen("data\\maximum.txt", "r");       
	if ( infile == NULL ) {  
		printf("Unable to open the file"); 
	} 
	char outstream[255];
	fscanf(infile, "%s", outstream); 
	int i=0,j=0, ctr=0;
	char newString[10][10]; 
	for(i=0;i<=(strlen(outstream));i++){
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
	int highest_score= atoi(newString[1]);
	system("cls");
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t                      Highest Score is %d",highest_score);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\n\n\n\n\n\n\t\tPress any Key to return to the main menu of the game");
}

