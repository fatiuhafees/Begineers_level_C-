// since strupr and strlwr dont work we have to get creative
#include <stdio.h>

int main(){
    int number = 0;
    int sum = 0; 
    
    do{
        printf("Enter a number above 10:");
        scanf("%d", &number);
        if(number < 10)
        {
            sum+=number;
        }
    }while(number < 10);
    
    printf("sum %d", sum);
    
}