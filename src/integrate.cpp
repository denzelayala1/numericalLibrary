#pragma once
#include <stdio.h>
#include <math.h>
#include <cmath>
#include "../include/integrate.hpp"
//#include <mpi.h>
# define PI  3.14159265358979323846


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
        printf("The function 'trapezoidalIntegrate' set epsilon to 1e-11\n");
    }

    while(!equal(val, prevVal, epsilon)){
        prevVal = val;
        val = trapezoidalIntegrate(func, start, end, npts);
        
        if(equal(val, prevVal, epsilon)){
            return val;
        }

        if(itr >= 2){
            printf("--------------------\nIntegration of required too many iterations\nValue   = %.12f\nPrevVal = %.12f\n--------------------\n", val, prevVal);
            return val;
        }

        itr += 1;
        npts *= 2;
    }

    return -1.00;
}

bool equal(double a, double b, double epsilon){
    return std::abs(a - b) < epsilon;
}