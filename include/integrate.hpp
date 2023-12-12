#pragma once
#include <stdio.h>
#include <math.h>
#include <cmath>
//#include <mpi.h>
# define PI  3.14159265358979323846


double integrate(double (*func)(double), double start, double end, int steps = 1000);
double integrate(double (*func)(double), double start, double end, double epsilon = 1e-5);
bool equal( double a, double b, double epsilon = 1e-5);
double findPi(double x);
