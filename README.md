
# Group_J_QuizGame

This quiz game application is used to test the general knowledge of the player. This application will be importing the quiz data from an excel file. Once the quiz is launched, the user will have only 30 seconds to answer each question or else it will skip to the next question. The users will be prompted with their respective scores and the total points earned at the end of the quiz with the highest score of the quiz. The user can reset the Highest score of the quiz on his/ her device to start again from scratch or even request for help to know additional information about the quiz in the main menu of the quiz.

---

### Organization

- Carleton University

---

### Clone

- Clone this repo to your local machine using `https://github.com/parth4719/Group_J_QUIZGAME.git`

---

### Dependencies

- Dev-C++ (IDE)
- CSV file
- Text file

---

### Source File Organization

### src folder 
- This folder contains the source code for the implementation.
- calculatescore.c - The function will calculate user's final score.
- compare_score.c - The function compares user_score with the existed highest_score stored in the text file.
- display_score.c - The function display the highest score user recorded in the system.
- displayquiz.c - Displays the Main Menu of the Quiz.
- help.c - The function will provide the basic informations and the rules of the quiz game.
- quit.c - The function terminate all the ongoing process and exit.
- randomize.c - Incorporates randomness in the quiz.
- readexcel.c - The function will be able to get data from comma separated csv file.
- reset_score.c - The function will reset the maximum.txt file with 0 score.
- startquiz.c - Starts the Quiz.
- swap.c - Executes a Swap function.
- timer.c - The function will incorporate a timer of 10 seconds during each question of the quiz.
- updatetextfile.c - updates the highest score of the player in the text file.

---

### main.c

- This file connects all the functions together.

---

### book.csv

- This excel file contains the all questions and answers.
---

### include folder

- This folder contains the header files for the source files

---

### data folder

- This folder contains the text file which saves the maximum score.

---

### test 

- This folder includes the test cases for testing the software

---

## User Document

- please refer /documents/developer_doc/User_manual.docx for compilation steps

---

## Developer Document

- please refer /documents/developer_doc/developerguide.docx

---

## Team

- Hitul Shah   
- Pavan Patel
- Parth patel
- Vimil Rathod

---

## Support

- Email to hitulshah@cmail.carleton.ca / pavanpatel@cmail.carleton.ca/ parthppatel3@cmail.carleton.ca/ vimilrathod@cmail.carleton.ca

---

## Acknowledgements

Dr. Cristina Ruiz Martin of SYSC department at Carleton University for guiding us throughout the course of this project.
