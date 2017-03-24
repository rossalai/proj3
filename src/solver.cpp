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
    this->num_planets=planets.size();
}

solver::solver(string method){
    this->method=method;
    this->planets.push_back(planet());
    this->num_planets=planets.size();
}

void solver::add_planet(planet p){
    this->planets.push_back(p);
    this->num_planets=planets.size();
}

double solver::calc_force(planet p){
    double pi= acos(-1);
    int num_planets=this->num_planets;
    if(num_planets==2){
        return 4*pi*pi;
    }
    
    string planet_name=p.name;
    double force=1;
    for(int p1=1;p1<=num_planets;p1++){
        //don't add force due to itself
        if(this->planets[p1].name==planet_name){
            continue;
        }
        //force += (Mp1/Ms)*(rs/rp)^2 (rp is distance between p and p1)
        force+=this->planets[p1].get_mass()*pow(p.distance(this->planets[0]),2)
                /(this->planets[0].get_mass()*pow(p.distance(this->planets[p1]),2));
    }
    
    force=4*pi*pi*force;
    return force;
}

void solver::solve(int n, double h){
        double old_x[3];
        double old_v[3];
        double old_dist;
        double pi= acos(-1);
        //loop through all planets in system and solve for each
        //start at index 1 because sun is always planets[0]
        for(int p=1;p<this->num_planets;p++){
            string planet_name=this->planets[p].name;
            double force=this->calc_force(this->planets[p]);
            if (this->method=="Euler"){
                string file="euler_"+planet_name;
                ofstream out_x(file+"_x.txt");
                ofstream out_y(file+"_y.txt");
                ofstream out_z(file+"_z.txt");
                ofstream dist(file+"_dist.txt");
                out_x<<"0   "<<this->planets[p].x[0]<<endl;
                out_y<<"0   "<<this->planets[p].x[1]<<endl;
                out_z<<"0   "<<this->planets[p].x[2]<<endl;
                dist<<"0   "<<this->planets[p].distance(this->planets[0])<<endl;

                for (int i=1; i<=n;i++){
                    //get distance from last iteration
                    old_dist=this->planets[p].distance(this->planets[0]);
                    //get values from last iteration and calculate new vals
                    for(int dim=0;dim<3;dim++){
                        old_x[dim]=this->planets[p].x[dim];
                        old_v[dim]=this->planets[p].v[dim];
                        this->planets[p].x[dim]=old_x[dim]+h*old_v[dim];
                        this->planets[p].v[dim]=old_v[dim]-h*force*old_x[dim]/pow(old_dist,3);
                    }
                    //write positions to files
                    out_x<<i*h<<"   "<<this->planets[p].x[0]<<endl;
                    out_y<<i*h<<"   "<<this->planets[p].x[1]<<endl;
                    out_z<<i*h<<"   "<<this->planets[p].x[2]<<endl;
                    dist<<i*h<<"   "<<this->planets[p].distance(this->planets[0])<<endl;
                }
                out_x.close();
                out_y.close();
                out_z.close();
                dist.close();
            }

            if (this->method=="VV"){
                double old_a[3];
                double a[3];
                string file="vv_"+planet_name;
                ofstream out_x(file+"_x.txt");
                ofstream out_y(file+"_y.txt");
                ofstream out_z(file+"_z.txt");
                ofstream dist(file+"_dist.txt");
                out_x<<"0   "<<this->planets[p].x[0]<<endl;
                out_y<<"0   "<<this->planets[p].x[1]<<endl;
                out_z<<"0   "<<this->planets[p].x[2]<<endl;
                dist<<"0   "<<this->planets[p].distance(this->planets[0])<<endl;
                for (int i=1; i<=n;i++){
                    //get distance from last iteration
                    old_dist=this->planets[p].distance(this->planets[0]);
                    //get values from last iteration and calculate new values
                    for(int dim=0;dim<3;dim++){
                        old_x[dim]=this->planets[p].x[dim];
                        old_v[dim]=this->planets[p].v[dim];
                        old_a[dim]=-force*old_x[dim]/pow(old_dist,3);
                        this->planets[p].x[dim]=old_x[dim]+h*old_v[dim]+h*h*old_a[dim]/2;          
                    }
                    for(int dim=0;dim<3;dim++){
                        a[dim]=-force*this->planets[p].x[dim]/pow(this->planets[p].distance(this->planets[0]),3);
                        this->planets[p].v[dim]=old_v[dim]+h*(a[dim]+old_a[dim])/2;
                    }
                    //write positions to files
                    out_x<<i*h<<"   "<<this->planets[p].x[0]<<endl;
                    out_y<<i*h<<"   "<<this->planets[p].x[1]<<endl;
                    out_z<<i*h<<"   "<<this->planets[p].x[2]<<endl;
                    dist<<i*h<<"   "<<this->planets[p].distance(this->planets[0])<<endl;
                }
                out_x.close();
                out_y.close();
                out_z.close();
                dist.close();
            }
        }
}

solver::~solver() {
}

