
//Header file for lab1.c by Lucas and Tyler
  int data[5][2][3] = {
      {
          {30, 25, 15},
          {32, 23, 16}
      },
      {
          {28, 22, 18},
          {29, 23, 17}
      },
      {
          {31, 22, 12},
          {29, 23, 20}
      },
      {
          {30, 23, 16},
          {31, 20, 14}
      },
      {
          {35, 29, 22},
          {33, 24, 16}
      },
  }; //end of data
  //return data; //returns the array for usage

void printData() {
  fprintf(stderr, "\nDisplaying values:\n\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == 0 && k == 2) { //end of top row
          fprintf(stderr, "%d\n", data[i][j][k]);
        }//end if
        else if (j == 1 && k == 2) { //end of bottom row
          fprintf(stderr, "%d\n\n", data[i][j][k]);
        }//end else if
        else if (j <= 1 && k < 2) { //other data entries
          fprintf(stderr, "%d ", data[i][j][k]);
        }//end else if
      }//end for
    }//end for
  }//end for
}//end printData
