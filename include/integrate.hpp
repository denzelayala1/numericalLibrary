#pragma once
#include <stdio.h>
#include <math.h>
#include <cmath>
//#include <mpi.h>


double trapezoidalIntegrate(double (*func)(double), double start, double end, int steps = 1000);
double trapezoidalIntegrate(double (*func)(double), double start, double end, double epsilon = 1e-5);
bool equal( double a, double b, double epsilon = 1e-5);
