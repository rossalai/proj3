/* Project: 905 Project 3
 * File:   main.cpp
 * Author: alaina ross
 *
 * Created on March 14, 2017, 2:48 PM
 */

#include <cstdlib>
#include <map>
#include <utility>
#include <string>

#include "planet.h"
#include "solver.h"


using namespace std;

void initialize_planets(map<string,planet>&);

/*
 * 
 */
int main(int argc, char** argv) {
    double h = 0.01;
    double n = 500;
    double t_f=n*h;
    
    //initialize all planets in map of ("name", planet) pairs
    map<string,planet> solar_system;
    initialize_planets(solar_system);
    
    //earth/sun system (euler)
    solver binary_euler("Euler");
    binary_euler.add_planet(solar_system["earth"]);
    binary_euler.solve(n,h);
    
//    //earth/sun system (vv)
//    solver binary_vv("VV");
//    binary_vv.add_planet(solar_system["earth"]);
//    binary_vv.solve(n,h);
    
//    //earth/jupiter/sun system (vv)
//    solver threebody_vv("VV");
//    threebody_vv.add_planet(solar_system["earth"]);
//    threebody_vv.add_planet(solar_system["jupiter"]);
//    threebody_vv.solve(n,h);
    
    //all solar system (vv)
    solver vv("VV");
    for(auto element : solar_system){
        vv.add_planet(element.second);
    }
    vv.solve(n,h);
    
    

    
    return 0;
}

void initialize_planets(map<string,planet>& system){
    planet sun ("sun",1.0,
            3.137303325606177E-03,4.483475178057109E-03,-1.508511448592782E-04,
            -0.001266267226536104055,0.002402801570101757985,0.0000276711559511651086);
    system["sun"] = sun;
    planet mercury("mercury",1.65E-7,
            5.666407744278721E-02,3.067013184352099E-01,1.963346515611241E-02,
            -12.1720980711493124,2.173776624892818855,1.294027164734853765);
    system["mercury"] = mercury;
    planet venus("venus",2.45E-6,
            -7.152832287930488E-01,-2.576415475743124E-02,4.089080638421815E-02,
            0.2651635844731343065,-7.4062556378659788,-0.1169528340632723);
    planet earth("earth",3E-6,
            -9.921659045836120E-01,-5.297464688174806E-02,-1.444074140071765E-04,
            0.256790253188838299,-6.29207466280881475,0.000500268555676713355);
    system["earth"] = earth;
    planet mars("mars",3.3E-7,
            6.845118845443258E-01,1.343789057944218E+00,1.119273344632205E-02,
            -4.3599876134523615,2.7537357409899111,0.1646555933430269135);
    system["mars"] = mars;
    planet jupiter("jupiter",9.5E-4,
            -5.216449805254690E+00,-1.580162951996290E+00,1.232243010564932E-01,
            0.76674377434577883,-2.5056764652495431,-0.0067372069838469784);
    system["jupiter"] = jupiter;
    planet saturn("saturn",2.75E-4,
            -1.439005115786913E+00,-9.942481929104693E+00,2.301429649049684E-01,
            1.90349334065927597,-0.298391260638576401,-0.0704482712554306805);
    system["saturn"] = saturn;
    planet uranus("uranus",4.4E-5,
            1.821134439270002E+01,8.110741813064609E+00,-2.058078826220335E-01,
            -0.59456674142239926,1.24448505639554357,0.01234305121840310425);
    system["uranus"] = uranus;
    planet neptune("neptune",5.15E-5,
            2.841998057142785E+01,-9.444030557617360E+00,-4.604849856242147E-01,
            0.3538537210290212985,1.094240547363887455,-0.0307043180005010896);
    system["neptune"] = neptune;
    planet pluto("pluto",6.55E-9,
            9.914852642680707E+00,-3.177638018613578E+01,5.323159431958102E-01,
            1.120947953635603765,0.1039222287902140395,-0.3382662708928622185);
    system["pluto"] = pluto;
}

