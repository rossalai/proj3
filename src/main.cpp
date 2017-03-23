/* Project: 905 Project 3
 * File:   main.cpp
 * Author: alaina ross
 *
 * Created on March 14, 2017, 2:48 PM
 */

#include <cstdlib>
#include </opt/local/include/armadillo.h>

#include "planet.h"


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
    
    //Euler method
    if (method=="Euler"){
        ofstream out_x("euler_earth_x.txt");
        ofstream out_y("euler_earth_y.txt");
        ofstream out_z("euler_earth_z.txt");
        ofstream dist("euler_earth_dist.txt");
        out_x<<"0   "<<earth.x[0]<<endl;
        out_y<<"0   "<<earth.x[1]<<endl;
        out_z<<"0   "<<earth.x[2]<<endl;
        dist<<"0   "<<earth.distance(sun)<<endl;
        
        for (int i=1; i<=n;i++){
            //get distance from last iteration
            old_dist=earth.distance(sun);
            //get values from last iteration and calculate new vals
            for(int dim=0;dim<3;dim++){
                old_x[dim]=earth.x[dim];
                old_v[dim]=earth.v[dim];
                earth.x[dim]=old_x[dim]+h*old_v[dim];
                earth.v[dim]=old_v[dim]-h*4*pi*pi*old_x[dim]/(old_dist*old_dist*old_dist);
                
            }
            //write positions to files
            out_x<<i*h<<"   "<<earth.x[0]<<endl;
            out_y<<i*h<<"   "<<earth.x[1]<<endl;
            out_z<<i*h<<"   "<<earth.x[2]<<endl;
            dist<<i*h<<"   "<<earth.distance(sun)<<endl;
        }
        out_x.close();
        out_y.close();
        out_z.close();
        dist.close();
    }
    
    method="VV";
    earth.x[0]=1;
    earth.x[1]=0;
    earth.x[2]=0;
    earth.v[0]=0;
    earth.v[1]=6.3;
    earth.v[2]=0;
    
    //Velocity Verlet method
    if (method=="VV"){
        ofstream out_x("vv_earth_x.txt");
        ofstream out_y("vv_earth_y.txt");
        ofstream out_z("vv_earth_z.txt");
        ofstream dist("vv_earth_dist.txt");
        out_x<<"0   "<<earth.x[0]<<endl;
        out_y<<"0   "<<earth.x[1]<<endl;
        out_z<<"0   "<<earth.x[2]<<endl;
        dist<<"0   "<<earth.distance(sun)<<endl;
        for (int i=1; i<=n;i++){
            //get distance from last iteration
            old_dist=earth.distance(sun);
            //get values from last iteration and calculate new vals
            for(int dim=0;dim<3;dim++){
                old_x[dim]=earth.x[dim];
                old_v[dim]=earth.v[dim];
                //old_a[dim]=-4*pi*pi*old_x[dim]/pow(sqrt(old_x[0]*old_x[0]+
                //        old_x[1]*old_x[1]+old_x[2]*old_x[2]),3);
                old_a[dim]=-4*pi*pi*old_x[dim]/pow(old_dist,3);
                earth.x[dim]=old_x[dim]+h*old_v[dim]+h*h*old_a[dim]/2;          
            }
            for(int dim=0;dim<3;dim++){
               // a[dim]=-4*pi*pi*earth.x[dim]/pow(sqrt(earth.x[0]*earth.x[0]+
                //        earth.x[1]*earth.x[1]+earth.x[2]*earth.x[2]),3);
                a[dim]=-4*pi*pi*earth.x[dim]/pow(earth.distance(sun),3);
                earth.v[dim]=old_v[dim]+h*(a[dim]+old_a[dim])/2;
            }
            //write positions to files
            out_x<<i*h<<"   "<<earth.x[0]<<endl;
            out_y<<i*h<<"   "<<earth.x[1]<<endl;
            out_z<<i*h<<"   "<<earth.x[2]<<endl;
            dist<<i*h<<"   "<<earth.distance(sun)<<endl;
        }
        out_x.close();
        out_y.close();
        out_z.close();
        dist.close();
    }
    
    
    return 0;
}

