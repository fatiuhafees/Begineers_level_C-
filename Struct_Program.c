#include <stdio.h>
#include <string.h>
struct Player{
    char title[10];
    int score; 
}; //dont forget ';' after struct function
int main()
{
    struct Player Player1; 
    struct Player Player2; 
    
    Player1.score = 2;
    strcpy(Player1.title,"Loser ");
    printf("%s",Player1.title);
    printf("With %d points: Player 1\n",Player1.score);
    
    Player2.score = 5;
    strcpy(Player2.title,"Winner ");
    printf("%s",Player2.title);
    printf("With %d points: Player 2\n",Player2.score);
   
    return 0;

}