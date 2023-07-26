#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
// seed-rand allows us to say that the generator will start from 0
    srand(time(0));
    
    int sum = 0;
    
    for (int i = 0; i < 5; i++)
    {

//rand will give us a random number between 0 - 32,767
// modulus (%) allows us to determine the highest posible number       
        int dice = (rand()%6)+1;
        printf("Rolled: %d\n",dice);
        sum += dice;
    }
    
    printf("\nScore: %d\n",sum);

    return 0; 
}