#include <stdio.h>
int main() {

//making file 
    FILE *pF = fopen("testfile.text","w");
    
//sending text to file
    fprintf(pF, "hello there");

//closing file
    fclose(pF);

//deleting the file
    remove("testfile.text");

    return 0;
}