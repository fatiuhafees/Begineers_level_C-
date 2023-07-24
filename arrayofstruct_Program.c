// Array of structs
#include <stdio.h>
#include <string.h>

struct student{
    char name[25];
    char Alevel[25];
};

int main(){
    
    struct student student1= {"Josh","BBC"};
    struct student student2= {"Sam","A*AB"};
    struct student student3= {"Joe","EEF"};
    
//struct array: 
    struct student student[]= {student1,student2,student3};
    int size = sizeof(student)/sizeof(student[0]);
    
    for (int i = 0; i < size ;i++)
    {
// \t, creates some white space
        printf("%-4s\tresults:\t",student[i].name);
        printf("%-4s\n",student[i].Alevel);
    }

    return 0; 
}