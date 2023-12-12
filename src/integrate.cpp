#pragma once
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "../include/integrate.hpp"
//#include <mpi.h>
# define PI  3.14159265358979323846



double findPi(double x){
    return 4.00/(1.00 + x*x);
}


double trapezoidalIntegrate(double (*func)(double), double start, double end, int npts){

    double range = end - start;
    double step = range / double(npts);
    double value = 0.00;
    double x = start;

    for(int i = 0 ; i < npts; i++){
        value += step * ( func(x) + func(x+step) )/ 2.00;
        x += step;
    }

    return value;
}

double trapezoidalIntegrate(double (*func)(double), double start, double end, double epsilon){

    int npts = 10000;
    int itr = 0;

    double val= 0.00;
    double prevVal = 1.00;

    if(epsilon < 1e-11){
        epsilon = 1e-11;
        printf("set epsilon to 1e-11\n");
    }

    while(!equal(val, prevVal, epsilon)){
        prevVal = val;
        val = trapezoidalIntegrate(func, start, end, npts);
        
        if(equal(val, prevVal, epsilon)){
            printf("--------------------\nCOMPLETED\n    val = %.16f\nprevVal = %.16f\n%d iterations\n--------------------\n",val, prevVal, itr);
            return val;
        }

        if(itr >= 20){
            printf("--------------------\nIntegration of required too many iterations\n--------------------\n");
            return val;
        }

        itr += 1;
        npts *= 2;
    }

    printf("--------------------\nval = %.10f\nprevVal = %.10f\n%d iterations\n--------------------\n",val, prevVal, itr);
    return -1.00;
}

bool equal(double a, double b, double epsilon){
    if(epsilon < 1e-11){
        epsilon = 1e-11;
        printf("set epsilon to 1e-11\n");
    }

    return std::abs(a - b) < epsilon;
}