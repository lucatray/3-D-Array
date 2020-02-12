#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"


void validInput (void){//funtion to recognize if user entered invalid input

    int i = getchar();

    while (i != '\n' && i != EOF)
        i = getchar();
}

void totalSold(){
  //method to determine total number of hot dogs sold for all 5 games
  fprintf(stderr, "Chosen:: Total Hotdogs Sold\n");
  int total = 0;
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 3; k++) {
              total += data[i][j][k];
          }
      }
  } //end outer for loop
  fprintf(stderr, "Total Sold is: %d\n\n", total);
} // end of totalSold

void avgPerHour() {
  //method to determine number of hot dogs sold per hour for all 5 games
  fprintf(stderr, "Chosen:: Average Hotdogs Sold\n");
  int total = 0;
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 3; k++) {
              total += data[i][j][k];
          }
      }
  } //end outer for loop
  total = total / 15;
  fprintf(stderr, "Average Sold is: %d\n\n", total);
} //end of avgPerHour

void mostSoldGame(){
  //method to determine number of hot dogs sold per game and display the highest selling game
  fprintf(stderr, "Chosen:: Highest Selling Game\n");
  int highestGame = 0;
  int gameTotal = 0;
  int total = 0;
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 2; j++) {
          for (int k = 0; k < 3; k++) {
              total += data[i][j][k];
              if (k ==2 && j ==1) { //reached the end of the game data: "block of array"
                  if (total > gameTotal) {
                    gameTotal = total;
                    highestGame = i + 1; //thus game 0 == "game 1"
                    total = 0; //resets the total 'counter'
                    //fprintf(stderr, "Total Sales for game %d was %d\n", i+1, gameTotal);
                    /*Above Line prints off sales for increasing value games*/
                  }
                  else {
                    //fprintf(stderr, "Total Sales for game %d was %d\n", i+1, total);
                    /*Above Line prints off sales that do not increase in value from
                    the current highest value game*/
                    total = 0;
                  }
              } //end outer if
          }
      }
  } //end outer for loop
  fprintf(stderr, "Highest Sales occurred at game %d\n\n", highestGame);
} //end of mostSoldGame

void manualGame(){
  //method to determine total number of hot dogs sold for user selected game
  fprintf(stderr, "Chosen:: Manual Game Select \n");
  fprintf(stderr, "Which game sales do you want?: ");
  int game;
  while (game != -1) {
  scanf("%d",&game);
  //fprintf(stderr, "\n");
    switch(game)
    {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        game = game - 1; //changes the choice to a valid array selection (0-4)
        int total = 0;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                total += data[game][j][k];
            }
        } //end outer for loop
        fprintf(stderr, "Total Sales for game %d are: %d\n\n", game + 1,total);
        game = -1;
        break;
      default:
        fprintf(stderr, "Invalid game!\n\n");
        game = -1;
    } //switch
  } //end while loop
} // end of manualGame


void load_menu() {
    int choice;
    system("clear");
    while (1) {
      choice = '\0';
      fprintf(stderr, "Menu\n\n");
      fprintf(stderr, "1. Calculate total of hot dogs sold for all 5 games.\n");
      fprintf(stderr, "2. Calculate average amount of dogs sold per hour for all 5 games.\n");
      fprintf(stderr, "3. Calculate which game sold the most hot dogs.\n");
      fprintf(stderr, "4. Manual Lookup of total sales for a game.\n");
      fprintf(stderr, "5. Exit\n\n");
      fprintf(stderr, "Selection Choice: ");
      scanf("%d",&choice);
      fprintf(stderr, "\n");
      switch(choice)
      {
        case 1:
          system("clear");
          totalSold();
          break;
        case 2:
          system("clear");
          avgPerHour();
          break;
        case 3:
          system("clear");
          mostSoldGame();
          break;
        case 4:
          system("clear");
          manualGame();
          break;
        case 5:
          fprintf(stderr, "Quitting program!\n");
          exit(0);
          system("clear");
          break;
        default:
          fprintf(stderr, "Invalid choice! Please select options 1-5.\n\n");
          validInput();
          //choice = "\0";
          break;
      } //switch
    } //while
} //load_menu



void main(void) {
  printData();
  load_menu();
} //main
