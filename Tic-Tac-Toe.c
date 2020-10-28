#include <stdio.h>
#include <stdbool.h>


void PrintBoard(char b[][3]);
bool CheckWin(char bd[][3], char player);

void Game(char b[][3]){

  int row, col;

    for (int i = 0; i < 5; i++){

    //X's turn
    printf("\nX's turn\n");
    scanf("%d %d", &col, &row);

    while(1){

      if ((row > 3) || (col > 3)){
        printf("Enter a valid space.\n");
        scanf("%d %d", &col, &row);
      }
      else if(b[col-1][row-1] == ' '){
        b[col-1][row-1] = 'X';
        break;
      }
      else {
        printf("Enter a valid space.\n");
        scanf("%d %d", &col, &row);
      }
    }

    printf("\n");
    PrintBoard(b);

    if (CheckWin(b, 'X') == true){
      printf("X Wins!");
      break;
    }

    if (i == 4){
      printf("Cat's Game!");
      break;
    }

    //O's turn
    printf("\nO's turn\n");
    scanf("%d %d", &col, &row);

    while(1){

      if ((row > 3) || (col > 3)){
        printf("Please enter a valid space.\n");
        scanf("%d %d", &col, &row);
      }
      else if(b[col-1][row-1] == ' '){
        b[col-1][row-1] = 'O';
        break;
      }
      else {
        printf("Enter a valid space.\n");
        scanf("%d %d", &col, &row);
      }
    }

    printf("\n");
    PrintBoard(b);

    if (CheckWin(b, 'O') == true){
      printf("O Wins!");
      break;
    }

  }
  
}

int main(){

	char board[3][3];

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      board[j][i] = ' ';
    }
  }

  PrintBoard(board);
  printf("\nInput: '[row] [column]'\n");
  
  Game(board);

	return 0;
}

bool CheckWin(char bd[][3], char player){
  int NumsH = 0, NumsV = 0, NumsDL = 0, NumsDR = 0;
  
  for (int j = 0; j < 3; j++){
    for (int i = 0; i < 3; i++){
      if(bd[j][i] == player){ //Checks Rows
        NumsV++;
      }

      if(bd[i][j] == player){ //Checks Columns
        NumsH++;
      }

      if (i == j){
        if(bd[i][j] == player){ //Checks left to right Diagonal
          NumsDL++;
        }
      }

      if((2 - i) == j){
        if(bd[i][j] == player){ //Checks right to left Diagonal
          NumsDR++;
        }
      }

      if(NumsV == 3){
        return true;
        break;
      }
      else if(NumsH == 3){
        return true;
        break;
      }
      else if(NumsDL == 3){
        return true;
        break;
      }
      else if(NumsDR == 3){
        return true;
        break;
      }
    }
    NumsV = 0;
    NumsH = 0;
  }

  return false;

}

void PrintBoard(char b[][3]){

  for(int i = 0; i < 3; i++){
		
	for(int j = 0; j < 3; j++){
			
		printf("%c", b[j][i]);

		if( j != (2)){
			printf(" | ");
		}
	}

   	printf("\n");

    	if(i != 2){
     		printf("---------\n");
    	}
		
	}

}
