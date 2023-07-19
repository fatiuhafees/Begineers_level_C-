#include <stdio.h>

    const double pi = 3.14159;
    double Radius;
    double Circumference;
    double Area;

int main(){

    printf("\nEntre the radius of the circle:");
    scanf("%lf",&Radius); //& and scanf allow us to recive inputs

    double Circumference = 2 * pi * Radius;
    printf("The circumference of the circle: %.2lf 2dp \n", Circumference);

    double Area = pi * Radius * Radius;
    printf("The area of the circle: %.2lf 2dp \n", Area);

    return 0;
}
