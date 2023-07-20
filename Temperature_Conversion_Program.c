#include <stdio.h>
#include <ctype.h> //string functions library

char unit;
double temp;

int main(){
    printf("\nIs the temperature in (F) or (C): ");
    scanf("%c",&unit);
    
    unit= toupper(unit); //lets us upper case a letter
    
    if(unit == 'F'){
    printf("\nEntre temperature in farenheit:");
    scanf("%lf",&temp);
    temp = ((temp-32) * 5)/9;
    printf("\nThe temperature in celsius is %0.1lfC",temp);
    }
    
    else if(unit == 'C'){
    printf("\nEntre temperature in celsius:");
    scanf("%lf",&temp);
    temp = (temp*9/5) + 32;
    printf("\nThe temperature in farenheit is %0.1lfF",temp);
    }
    
    else {
        printf("\n%c is not an valid unit of measurement",unit);
    }
    return 0;
}