//arguments 
#include <stdio.h>
void lyrics(char x[],char y[]){
    printf("\nI came, I saw, I %s, I saw",x);
    printf("\nI %s the Lord, then break the law",y);
    printf("\nI take what's mine, then take some more");
    printf("\nIt rains, it pours, it rains, it pours\n");
}
int main(){
    
    char x[]= "came";  //dont put numbers in [] for char type
    char y[]= "praise";  
    
    lyrics(x,y); //allows void function to read varibles
    return 0;
    
}