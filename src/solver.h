/* 
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
using namespace std;

class solver {
public:
    solver();
    solver(string method);
    void add_planet(planet p);
    virtual ~solver();
    void solve(int n, double h);
private:
    string method;
    vector<planet> planets;
};


#endif	/* FUNCTIONS_H */

