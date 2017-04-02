/* Project: 905 Project 3
 * File:   solver.h
 * Author: alaina
 *
 * Created on March 14, 2017, 2:56 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <string>
#include "planet.h"
#include  <vector>
#include <map>
using namespace std;

class solver {
public:
    solver();
    solver(string method,string origin);
    void add_planet(planet p);
    virtual ~solver();
    void solve(int n, double h);
    double calc_acc(planet p);
    double calc_ang_momentum();
    double calc_energy();
    void write(double h, planet p);
private:
    string method;
    string origin;
    vector<planet> planets;
    int num_planets;
    map<string,vector<shared_ptr<ofstream>>> output;
};


#endif	/* FUNCTIONS_H */

