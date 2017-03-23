/* Project: 905 Project 3
 * File:   main.cpp
 * Author: alaina ross
 *
 * Created on March 14, 2017, 2:48 PM
 */

#include <cstdlib>
#include </opt/local/include/armadillo.h>

#include "planet.h"
#include "solver.h"


using namespace std;
using namespace arma;

/*
 * 
 */
int main(int argc, char** argv) {
    string method="Euler";
    double pi = acos(-1);
    double h = 0.1;
    double n = 100;
    double t_f=n*h;
    double old_x[3];
    double old_v[3];
    double old_a[3];
    double a[3];
    double old_dist;
    
    planet earth(0.000003,1.,0.0,0.0,0.0,6.3,0.);
    planet sun (1.,0.,0.,0.,0.,0.,0.);
    
    solver euler("Euler");
    euler.add_planet(earth);
    euler.solve(n,h);
    
    earth.x[0]=1;
    earth.x[1]=0;
    earth.x[2]=0;
    earth.v[0]=0;
    earth.v[1]=6.3;
    earth.v[2]=0;
    solver vv("VV");
    vv.add_planet(earth);
    vv.solve(n,h);
    
    
    return 0;
}

