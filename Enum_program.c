#include <stdio.h>
#include <string.h>

enum day {Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thr = 5, Fri = 6,Sat=7};

int main(){
    
    enum day Today = Sun;

    if(Today == Sun || Today == Sat) //is 1==1 or 1==7
    {
        printf("It's the weekend");
    }

    else
    {
        printf("It's a school day");
    }
      

    return 0; 
}