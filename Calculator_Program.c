#include <stdio.h>
#include <ctype.h> //string functions library

char operator;
double num1;
double num2;
double result;

int main(){

  printf("\nWhat operator would you like to use (/,+,-,*):");
  scanf("\n%c",&operator);
 
  printf("\nEnter number 1:");
  scanf("%lf",&num1);
 
  printf("\nEnter number 2:");
  scanf("\n%lf",&num2);
  
  switch(operator){
      
      case '/':
      result = num1 / num2;
      printf("\n%0.2lf / %0.2lf is: %0.2lf",num1 , num2 , result);
      break;
      
      case '-':
      result = num1 - num2;
      printf("\n%0.2lf - %0.2lf is: %0.2lf",num1 , num2 , result);
      break;
      
      case '+':
      result = num1 + num2;
      printf("\n%0.2lf + %0.2lf is: %0.2lf \n",num1 , num2 , result);
      break;
      
      case '*':
      result = num1 * num2;
      printf("\n%0.2lf x %0.2lf is: %0.2lf",num1 , num2 , result);
      break;
     
      default:
      printf("\n%c is an invalid operator",operator);
      
  }
    return 0;
}