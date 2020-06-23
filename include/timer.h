#ifndef TIMER_H
#define TIMER_H

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
char userinput[] = {};


void Timer();

#endif 
