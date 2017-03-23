/* 
 * File:   planet.h
 * Author: alaina
 *
 * Created on March 14, 2017, 3:27 PM
 */

#ifndef PLANET_H
#define	PLANET_H

class planet {
public:
    planet();
    planet(double M,double x,double y,double z,double vx, double vy,double vz);
    virtual ~planet();
    double get_mass();
    double* get_position();
    double* get_velocity();
    double distance(planet other_planet);
    double x[3];
    double v[3];
private:
    double mass;
};

#endif	/* PLANET_H */

