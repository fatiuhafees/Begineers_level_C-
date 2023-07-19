#include <stdio.h>
#include <math.h>

int main(){
    
    int grade = 2;
    printf("Enter grade:");
    scanf("%d",&grade);
    switch (grade){
        case 2:
        printf("perfect\n");
        break; 
        
        case 3:
        printf("Alright\n");
        break; 
        
        default:
        printf("Please enter valid grade\n"); 
    }
    return 0;
}