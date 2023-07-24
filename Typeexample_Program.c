#include <stdio.h>
#include <string.h>

int main(){
//exsample 1:
    typedef char user[25];
    user user1 = "bra";
    
//exsample 2 (applied struct):
    typedef struct {
        char name[25];
        int year;
    } car; //nickname for struct must go after the curly brackets 

    car car1 ={"Bugati Chiron", 2016};
     
    printf("Model: %s\n", car1.name);
    printf("Released: %d", car1.year);
    
    return 0; 
}