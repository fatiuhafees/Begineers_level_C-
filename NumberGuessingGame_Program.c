#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
//range will be from 10 - 100
    const int MIN = 10; 
    const int MAX = 100; 
   
    int guess;
    int guesses;
    int answer;
    
    answer = (rand() % MAX) - MIN;
    
    do {
        printf("\nEnter a guess:\t");
        scanf("%d",&guess);
        
        if (guess > answer){
            printf("\nAnswer is lower than guess!");
        }
        else if (guess < answer){
            printf("\nAnswer is higher than guess!");          
        }
        else{
            printf("Correct guess!\n");
        }
        guesses +=1; 
        
    } while(guess != answer ); 
    
    printf("**************************************\n");
    printf("Answer: \t%d \n", answer);
    printf("Guesses: \t%d \n", guesses);
    printf("**************************************\n");

    return 0; 
}