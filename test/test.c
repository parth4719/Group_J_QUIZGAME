
#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "readexcel.h"
#include "updatetxtfile.h"

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
		if(val == 0){
			
			fprintf(fp,"****Test Fail*****\n\n");
		}
		else{
			fprintf(fp,"****Test Pass*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 6 for Update text File**********************************************\n");
        fprintf(fp,"We are testing data by not giving username \n");
        fprintf(fp,"Expected result it will give error message \n ");
        
		val = updatetextfile(2,"");
		
		if(val == 0){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 7 for Update text File**********************************************\n");
        fprintf(fp,"We are testing data by not giving userscore \n");
        fprintf(fp,"Expected result it will give error message \n ");
        
		val = updatetextfile("","hitul");
		
		if(val == 0){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 8 for Update text File**********************************************\n");
        fprintf(fp,"We are testing data by by providing all correct information \n");
        fprintf(fp,"Expected result it will run successfully \n ");
        
		val = updatetextfile("8","hitul");
		
		if(val == 1){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
	}	
}
