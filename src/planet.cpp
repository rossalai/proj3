/* Project: 905 Project 3
 * File:   planet.cpp
 * Author: alaina
 * 
 * Created on March 14, 2017, 3:27 PM
 */

#include "planet.h"

planet::planet() {
    this->mass=1;
    this->x[0]=0;
    this->x[1]=0;
    this->x[2]=0;
    this->v[0]=0;
    this->v[1]=0;
    this->v[2]=0;
}

planet::planet(double M,double x,double y,double z,double vx, double vy,double vz) {
    this->mass=M;
    this->x[0]=x;
    this->x[1]=y;
    this->x[2]=z;
    this->v[0]=vx;
    this->v[1]=vy;
    this->v[2]=vz;
          
}

double planet::distance(planet other_planet){
    double x1,y1,z1,x2,y2,z2,xx,yy,zz;
    
    x1=this->x[0];
    y1=this->x[1];
    z1=this->x[2];
    
    x2=other_planet->get_position()[0];
    y2=other_planet->get_position()[1];
    z2=other_planet->get_position()[2];
    
    xx=x1-x2;
    yy=y1-y2;
    zz=z1-z2;
    
    return sqrt(xx*xx+yy*yy+zz*zz);
    
}

planet::~planet() {
}

double planet::get_mass(){
    return this->mass;
}

double* planet::get_position(){
    return this->x;
}
    
double* planet::get_velocity(){
    return this->v;
}

