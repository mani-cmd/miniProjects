#include <stdio.h>

char board[3][3] = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}

};
int gameState = 1;
char currentChar = 'X';
char winCon = '.';

char checkWinner()
{
   //check rows
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0]!= '.')
      {
         return board[i][0];
      }
   }
   //check columns
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[2][i]!= '.')
      {
         return board[0][i];
      }
   }
   //check diagonals
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[2][2]!= '.' )
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[2][2]!= '.')
   {
      return board[0][2];
   }
   return '.';
}
void display(char board[3][3]){
    char currentChars = 'X';
    printf("    1   2   3 \n");
    printf("   --- --- ---\n1 |");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c |", board[i][j]);
        }

        if (i == 2)
        {
            printf("\n");
        }
        else
        {
            printf("\n%d |",i+2);
        }
    }
    printf("   --- --- ---\n");

}
void updateBoard(char boardAdd[3][3], int row, int col){
   if (board[row][col] == '.'){
        if(currentChar=='X'){
        }
        board[row][col] = currentChar; 
   }else{
       if (row < 2 && col < 2){
           printf("\n ========================== \n   Position already occupied\n==========================\n");
           currentChar = (currentChar == 'X') ? 'O' : 'X';
       }
   }

    currentChar = (currentChar == 'X') ? 'O' : 'X';
    display(board);
}
void resetBoard(char boardAdd[3][3])
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = '.';
      }
   }
   display(boardAdd);
}

int main(){
    printf("▀█▀ █ █▀▀   ▀█▀ ▄▀█ █▀▀   ▀█▀ █▀█ █▀▀\n░█░ █ █▄▄   ░█░ █▀█ █▄▄   ░█░ █▄█ ██▄\n\n");
    printf("Instructions:\n- The board below is the tictactoe board.\n- X goes first, O goes next\n- Enter the coordinate of the position you wanna occupy by the guideline.\n- For example to put your character in the first row first column enter '2 1'\n- Enter '0 7' to exit\n");
    display(board);
    // Initial prompt
    int row, col;

    while(gameState){
        printf("%c's Turn: ", currentChar);
        scanf("%d %d", &row, &col);
        if(row == 0 && col == 7){
            return 0;
        }
        else if(col>3 || row>3){
            printf("\n============================== \n Enter the correct coordinate\n=============================\n");
            currentChar = (currentChar == 'X') ? 'O' : 'X';

        }
        updateBoard(board, row-1, col-1);
        winCon = checkWinner();
        if(winCon != '.'){
            int option;
            printf("%c Won\n", winCon);
            printf("Would you like to play again?\n- If no enter 0\n- If yes enter any number\nYour option: ");
            scanf("%d", &option);
            if (option == 0){
                return 0;
            }else{
                resetBoard(board);
                
            }
        }
    }

    return 0;

}
