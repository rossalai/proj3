/* 
 * File:   planet.h
 * Author: alaina
 *
 * Created on March 14, 2017, 3:27 PM
 */

#ifndef PLANET_H
#define	PLANET_H

#include<string>
using namespace std;

class planet {
public:
    planet();
    planet(string name,double M,double x,double y,double z,double vx, double vy,double vz);
    virtual ~planet();
    double get_mass();
    double* get_position();
    double* get_velocity();
    double distance(planet other_planet);
    
    double x[3];
    double v[3];
    string name;
private:
    double mass;
};

#endif	/* PLANET_H */

