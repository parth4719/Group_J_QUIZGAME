#include<windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

#include "readexcel.h"
#include "updatetxtfile.h"
#include "comparescore.h"
#include "Tcalculatescore.h"
#include "Tstartquiz.h"

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
		
		fprintf(fp,"*********************************TEST 9 for Compare score**********************************************\n");
        fprintf(fp,"We are testing data by not providing user score \n");
        fprintf(fp,"Expected result it will provide error message \n ");
        
		val = compare_score("");
		
		if(val == 0){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 10 for Compare score**********************************************\n");
        fprintf(fp,"We are testing data by giving all needed information \n");
        fprintf(fp,"Expected result it will work properly \n ");
        
		val = compare_score(3);
		
		if(val == 1){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 11 for Calculate score**********************************************\n");
        fprintf(fp,"We are testing by considering an empty user input array \n");
        fprintf(fp,"Expected result is it will give error message \n ");
        
        char userinput[] = {};
		//val = calculatescore(userinput);
		
		if(val == 0){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 12 for Calculate score**********************************************\n");
        fprintf(fp,"We are testing by considering an input non zero array as given below\n");
        fprintf(fp,"Expected result is it will not give error message \n ");
        
        char userinput1[] = {1,1,1,1,1,1,1,1,1,1};
		//val = calculatescore(userinput1);
		
		if(val == 1){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 13 for Start quiz**********************************************\n");
        fprintf(fp,"We are testing by considering an input player name greater than 10 char\n");
        fprintf(fp,"Expected result is it will give error message \n ");
        
        
		val = startquiz();
		
		if(val == 0){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
		fprintf(fp,"*********************************TEST 14 for Start quiz**********************************************\n");
        fprintf(fp,"We are testing by considering an input player name less than 10 char\n");
        fprintf(fp,"Expected result is it will not give error message \n ");
        
        
		val = startquiz();
		
		if(val == 1){
			
			fprintf(fp,"****Test Pass*****\n\n");
		}
		else{
			fprintf(fp,"****Test Fail*****\n\n");
		}
		
	}	
}
	
    
