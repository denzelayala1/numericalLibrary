#include "integrate.hpp"
#include <stdio.h>
# define PI  3.14159265358979323846


double findPi(double x);

int main(int argc, char* argv[]){

double test = trapezoidalIntegrate(&findPi, 0.00, 1.00, 10000);
double test2 = trapezoidalIntegrate(&std::sin, 0.00, PI, 10000);
double test3 = trapezoidalIntegrate(&findPi, 0.00, 1.00, 1e-12);

printf("v1 Pi =  %.10f\nint[sin(x)] =  %.10f\nself consistant Pi =  %.10f\n", test, test2, test3);


return 0;
}


double findPi(double x){
    return 4.00/(1.00 + x*x);
}