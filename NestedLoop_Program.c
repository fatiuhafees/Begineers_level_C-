//nested loop, A loop inside another loop
#include <stdio.h>
int main()
{
   int rows;
   int columns;
   char symbol;

   printf("\nEnter # of rows: ");
   scanf("%d", &rows); //input 4

   printf("Enter # of columns: ");
   scanf("%d", &columns); //input 5

   scanf("%c", &symbol); 

   printf("Enter a symbol to use: ");
   scanf("%c", &symbol); //input $

   for(int i = 1; i <= rows; i++)
   {
      for(int j = 1; j <= columns; j++)
      {
         printf("%c",symbol );
      }
      printf("\n"); // final output: $$$$$
                                     
   }
   return 0;
}