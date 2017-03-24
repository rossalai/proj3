#include "catch.hpp"
#include "planet.h"
#include "solver.h"
#include <fstream>
#include <iostream>
using namespace std;


TEST_CASE("Testing Binary Euler"){
    double h = 0.01;
    double n = 500;
    planet earth("earth",0.000003,1.,0.0,0.0,0.0,6.3,0.);
    planet sun ("sun",1.,0.,0.,0.,0.,0.,0.);
    
    solver euler("Euler");
    euler.add_planet(earth);
    euler.solve(n,h);
    
    //these are files output by code
    ifstream euler_x("euler_earth_x.txt");
    ifstream euler_y("euler_earth_y.txt");
    ifstream euler_z("euler_earth_z.txt");
    ifstream euler_dist("euler_earth_dist.txt");
    
    //test last value in each file
    double t,x,y,z,dist;
    while(euler_x>>t>>x){};
    REQUIRE(x==Approx(1.71371));
    while(euler_y>>t>>y){};
    REQUIRE(y==Approx(1.12968));
    while(euler_z>>t>>z){};
    REQUIRE(z==Approx(0.00));
    while(euler_dist>>t>>dist){};
    REQUIRE(dist==Approx(2.05256));
    
    euler_x.close();
    euler_y.close();
    euler_z.close();
    euler_dist.close();
}

TEST_CASE("Testing Binary VV"){
    double h = 0.01;
    double n = 500;
    
    planet earth("earth",0.000003,1.,0.0,0.0,0.0,6.3,0.);
    planet sun ("sun",1.,0.,0.,0.,0.,0.,0.);
    
    solver vv("VV");
    vv.add_planet(earth);
    vv.solve(n,h);
    
    //these are files output by code
    ifstream vv_x("vv_earth_x.txt");
    ifstream vv_y("vv_earth_y.txt");
    ifstream vv_z("vv_earth_z.txt");
    ifstream vv_dist("vv_earth_dist.txt");
    
    //test last value in each file
    double t,x,y,z,dist;
    while(vv_x>>t>>x){};
    REQUIRE(x==Approx(0.956633));
    while(vv_y>>t>>y){};
    REQUIRE(y==Approx(-0.292057));
    while(vv_z>>t>>z){};
    REQUIRE(z==Approx(0.00));
    while(vv_dist>>t>>dist){};
    REQUIRE(dist==Approx(1.00022));
    
    vv_x.close();
    vv_y.close();
    vv_z.close();
    vv_dist.close();
}

TEST_CASE("Testing Multi-planet Force"){
    planet sun ("sun",1.,0.,0.,0.,0.,0.,0.);
    planet earth("earth",0.000003,-0.9922,-5.2975E-2,-1.444E-4,0.25679,-6.292089,-0.0005);
    planet jupiter ("jupiter",0.00095,-5.21645,-1.58016,0.12322,0.76674,-2.505676,-0.0067);
    
    solver vv("VV");
    vv.add_planet(earth);
    vv.add_planet(jupiter);

    double force;
    force=vv.calc_force(earth);
    REQUIRE(force==Approx(39.4808).epsilon(0.001));
}

TEST_CASE("Testing Multi-planet Euler"){
    
}

TEST_CASE("Testing Multi-planet VV"){
    
}


