#MAKEFILE
CC=gcc
INC_DIR = include
CFLAGS=-O0 -std=c11 -I $(INC_DIR)

#CREATE BIN, BUILD, AND RESULTS FOLDERS TO SAVE THE COMPILED FILES DURING RUNTIME
bin_folder := $(shell mkdir -p bin)
build_folder := $(shell mkdir -p build)

#TARGET TO BUILD EVERYTHING

startquiz.o: src/startquiz.c
	$(CC) -g -c $(CFLAGS) src/startquiz.c -o build/startquiz.o
	
Timer.o: src/Timer.c
	$(CC) -g -c $(CFLAGS) src/Timer.c -o build/Timer.o
	
calculatescore.o: src/calculatescore.c
	$(CC) -g -c $(CFLAGS) src/calculatescore.c -o build/calculatescore.o

swap.o: src/swap.c
	$(CC) -g -c $(CFLAGS) src/swap.c -o build/swap.o
	
randomize.o: src/randomize.c
	$(CC) -g -c $(CFLAGS) src/randomize.c -o build/randomize.o
	
displayquiz.o: src/displayquiz.c
	$(CC) -g -c $(CFLAGS) src/displayquiz.c -o build/displayquiz.o

compare_score.o: src/compare_score.c
	$(CC) -g -c $(CFLAGS) src/compare_score.c -o build/compare_score.o

updatetextfile.o: src/updatetextfile.c
	$(CC) -g -c $(CFLAGS) src/updatetextfile.c -o build/updatetextfile.o
	
display_score.o: src/display_score.c
	$(CC) -g -c $(CFLAGS) src/display_score.c -o build/display_score.o

reset_score.o: src/reset_score.c
	$(CC) -g -c $(CFLAGS)  src/reset_score.c -o build/reset_score.o

help.o: src/help.c
	$(CC) -g -c $(CFLAGS)  src/help.c -o build/help.o

quit.o: src/quit.c
	$(CC) -g -c $(CFLAGS) src/quit.c  -o build/quit.o

main.o: src/main.c
	$(CC) -g -c $(CFLAGS)  src/main.c -o build/main.o
	
#TARGET TO COMPILE EVERYTHING 
main: main.o swap.o randomize.o displayquiz.o reset_score.o help.o quit.o display_score.o startquiz.o Timer.o calculatescore.o compare_score.o updatetextfile.o main.o
		$(CC) -g -o bin/quiz build/main.o build/swap.o build/randomize.o build/displayquiz.o build/reset_score.o build/help.o build/quit.o build/display_score.o build/startquiz.o build/Timer.o build/calculatescore.o build/compare_score.o build/updatetextfile.o 


all: main

#CLEAN COMMANDS
clean: 
	rm -f bin/* build/*