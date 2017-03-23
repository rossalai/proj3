/* Project: 905 Project 3
 * File:   solver.cpp
 * Author: alaina ross
 *
 * Created on March 14, 2017, 2:55 PM
 */

#include "solver.h"
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

solver::solver(){
    this->method="Euler";
    this->planets.push_back(planet());
}

solver::solver(string method){
    this->method=method;
    this->planets.push_back(planet());
}

void solver::add_planet(planet p){
    this->planets.push_back(p);
}

void solver::solve(int n, double h){
        double old_x[3];
        double old_v[3];
        double old_dist;
        double pi= acos(-1);
        if (this->method=="Euler"){
            ofstream out_x("euler_earth_x.txt");
            ofstream out_y("euler_earth_y.txt");
            ofstream out_z("euler_earth_z.txt");
            ofstream dist("euler_earth_dist.txt");
            out_x<<"0   "<<this->planets[1].x[0]<<endl;
            out_y<<"0   "<<this->planets[1].x[1]<<endl;
            out_z<<"0   "<<this->planets[1].x[2]<<endl;
            dist<<"0   "<<this->planets[1].distance(this->planets[0])<<endl;

            for (int i=1; i<=n;i++){
                //get distance from last iteration
                old_dist=this->planets[1].distance(this->planets[0]);
                //get values from last iteration and calculate new vals
                for(int dim=0;dim<3;dim++){
                    old_x[dim]=this->planets[1].x[dim];
                    old_v[dim]=this->planets[1].v[dim];
                    this->planets[1].x[dim]=old_x[dim]+h*old_v[dim];
                    this->planets[1].v[dim]=old_v[dim]-h*4*pi*pi*old_x[dim]/pow(old_dist,3);

                }
                //write positions to files
                out_x<<i*h<<"   "<<this->planets[1].x[0]<<endl;
                out_y<<i*h<<"   "<<this->planets[1].x[1]<<endl;
                out_z<<i*h<<"   "<<this->planets[1].x[2]<<endl;
                dist<<i*h<<"   "<<this->planets[1].distance(this->planets[0])<<endl;
            }
            out_x.close();
            out_y.close();
            out_z.close();
            dist.close();
        }
        
        if (method=="VV"){
            double old_a[3];
            double a[3];
            ofstream out_x("vv_earth_x.txt");
            ofstream out_y("vv_earth_y.txt");
            ofstream out_z("vv_earth_z.txt");
            ofstream dist("vv_earth_dist.txt");
            out_x<<"0   "<<this->planets[1].x[0]<<endl;
            out_y<<"0   "<<this->planets[1].x[1]<<endl;
            out_z<<"0   "<<this->planets[1].x[2]<<endl;
            dist<<"0   "<<this->planets[1].distance(this->planets[0])<<endl;
            for (int i=1; i<=n;i++){
                //get distance from last iteration
                old_dist=this->planets[1].distance(this->planets[0]);
                //get values from last iteration and calculate new vals
                for(int dim=0;dim<3;dim++){
                    old_x[dim]=this->planets[1].x[dim];
                    old_v[dim]=this->planets[1].v[dim];
                    old_a[dim]=-4*pi*pi*old_x[dim]/pow(old_dist,3);
                    this->planets[1].x[dim]=old_x[dim]+h*old_v[dim]+h*h*old_a[dim]/2;          
                }
                for(int dim=0;dim<3;dim++){
                    a[dim]=-4*pi*pi*this->planets[1].x[dim]/pow(this->planets[1].distance(this->planets[0]),3);
                    this->planets[1].v[dim]=old_v[dim]+h*(a[dim]+old_a[dim])/2;
                }
                //write positions to files
                out_x<<i*h<<"   "<<this->planets[1].x[0]<<endl;
                out_y<<i*h<<"   "<<this->planets[1].x[1]<<endl;
                out_z<<i*h<<"   "<<this->planets[1].x[2]<<endl;
                dist<<i*h<<"   "<<this->planets[1].distance(this->planets[0])<<endl;
            }
            out_x.close();
            out_y.close();
            out_z.close();
            dist.close();
        }
}

solver::~solver() {
}

