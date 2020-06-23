
#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

#include "readexcel.h"

int main(){
	
	int val;
	
	FILE *fp = fopen("testresult.txt","a");
    if(fp==NULL)
    {
        printf("Unable to open file\n");
    }
    else
    {
    	fprintf(fp,"*********************************TEST 1 for Excel data**********************************************\n");
        fprintf(fp,"We are first going to conduct test by not giving file name \n");
        fprintf(fp,"Expected result it will give error message for the same \n ");
        
		val = readexcel();
		if(val == 0){
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 2 for Excel data**********************************************\n");
        fprintf(fp,"We are going to conduct test by giving different file name \n");
        fprintf(fp,"Expected result it will give error message for the file not found \n ");
        
		val = readexcel();
		if(val == 0){
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 3 for Excel data**********************************************\n");
        fprintf(fp,"We are going to conduct test by giving different file format \n");
        fprintf(fp,"Expected result it will give error message for the file not found \n ");
        
		val = readexcel();
		if(val == 0){
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 4 for Excel data**********************************************\n");
        fprintf(fp,"We are going to conduct test by giving different coloumn name in csv file \n");
        fprintf(fp,"Expected result it will give error message for the incorrect data format \n ");
        
		val = readexcel();
		if(val == 0){
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 5 for Excel data**********************************************\n");
        fprintf(fp,"We are going to conduct test by giving correct data in csv file \n");
        fprintf(fp,"Expected result it will run successfully \n ");
        
		val = readexcel();
		printf("%d",val);
		if(val == 0){
			
			fprintf(fp,"****Test Fail*****\n\n");
		}
		else{
			fprintf(fp,"****Test Pass*****\n\n");
		}
	}	
}
