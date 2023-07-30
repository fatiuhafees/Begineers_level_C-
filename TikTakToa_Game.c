#include <stdio.h> 
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
//global varibles 
char board[3][3];
const char PLAYER ='x';
const char COMPUTER ='o';

//fuction prototype 
void restBoard();
void printBoard();
int  checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);


int main()
{
    char winner =' ';
    char response=' ';
    do
    {
        char winner =' ';
        char response = ' ';
        restBoard(); 
        while( winner == ' ' && checkFreeSpaces() != 0) //if there is no winner and free space
        {
            printBoard();
            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces==0 )
                {
                    break; 
                }
            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces==0 )
                {
                    break; 
                }
        }
     printBoard();
     printWinner(winner);

     printf("Would you like to play again? (Y/N): ");
     scanf("%c");
     scanf("%c" , &response);
     response = toupper(response);
    } while(response == 'Y');

    printf ("Thanks for playing! :)\n");
    
    return 0; 
}


void restBoard()
{
    for (int i = 0; i < 3 ; i++)
    {
        for(int j = 0; j < 3 ; j++ )
        {
            board[i][j]=' ';

        }
       
    }

}
void printBoard()
{
    
    printf(" %c | %c | %c",board[0][0],board[0][1],board[0][2] );
    printf("\n...|...|...\n");
    printf(" %c | %c | %c",board[1][0],board[1][1],board[1][2] );
    printf("\n...|...|...\n");
    printf(" %c | %c | %c",board[2][0],board[2][1],board[2][2] );
    printf("\n");

}
int  checkFreeSpaces()
//this will tell the prgram how meany free spaces they are from the orginal 9
{
    int freespaces = 9;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freespaces--; 

            }

        }
  

    }
    return freespaces;
}
void playerMove()
{
    int x; //row number
    int y; //colums number

    do 
    {
    printf("Enter row number (1-3):");
    scanf("%d",&x);
    x--; // computer sees 0 - 2 and not 1 - 3 
    printf("Enter colum number (1-3):");
    scanf("%d",&y);
    y--; 

    //checking if user input coordinate are occupied or not
    if (board[x][y] != ' ')
    {
        printf("invalid input");
    }
    else 
    {
        board[x][y] = PLAYER; 
        break; 
    }

    } while(board[x][y] !=' '); //if player chosen spot occupied loop


}
void computerMove()
{//will need a seed to create a computer that randomly picks number
    srand(time(0)); 
    int x; 
    int y; 

    if(checkFreeSpaces > 0)
    {
        do
        {
            x = rand()%3;
            y= rand()%3;

        } while (board[x][y] !=' ');

        board[x][y] = COMPUTER; 

    }
    else
    {
        printWinner(' '); 
    }
}
char checkWinner()
{
    //check each row 
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
         //returns a charecter, whether computer or player (x or y).
            return board[i][0];

        }
    }
    //check each colums 
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];

        }
    }
    //check each diagnols 
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];

    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];

    }
    return ' ';
    
}
void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("YOU LOSE!\n");
    }
    else 
    {
        printf("IT'S A TIE!\n");
    }
    
}
