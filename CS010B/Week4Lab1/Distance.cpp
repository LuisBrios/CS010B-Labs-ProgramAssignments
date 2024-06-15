#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance(){
    _feet = 0;
    _inches = 0;
}

Distance::Distance(unsigned userFt, double userInches){
    _feet = userFt;
    _inches = userInches; 
    init(); 
}

Distance::Distance(double userInches){
    _feet = 0; 
    _inches = userInches;
    init();
}

unsigned Distance::getFeet() const{
    return _feet; 
}

double Distance::getInches() const{
    return _inches; 
}

double Distance::distanceInInches() const{
    double amntOfInches = 0; 

    amntOfInches = _inches + (_feet * 12);
    return amntOfInches; 
}

double Distance::distanceInFeet() const{
    double feetButSigned = _feet;

    feetButSigned += (_inches / 12);
    return feetButSigned; 
}

double Distance::distanceInMeters() const{
    double meteredVal = 0.0; 
    const double INCH_TO_METERS = 0.0254; 

    meteredVal = distanceInInches();
    meteredVal *= INCH_TO_METERS; 
    return meteredVal;
}

Distance Distance::operator+(const Distance &rhs) const{
    Distance totalDist; 

    totalDist._feet = _feet + rhs._feet; 
    totalDist._inches = _inches + rhs._inches;
    totalDist.init(); 

    return totalDist; 
}

Distance Distance::operator-(const Distance &rhs) const{
    Distance totalDist; 
    double distChecker = distanceInInches();
    double distChecker2 = rhs.distanceInInches(); 

    if (distChecker < distChecker2){
        totalDist._feet = 0;
        totalDist._inches = distChecker2 - distChecker; 
        totalDist.init(); 
    }
    else {
        totalDist._feet = 0; 
        totalDist._inches = distChecker - distChecker2;
        totalDist.init(); 
    }
    return totalDist; 
}

ostream& operator<<(ostream &out, const Distance &rhs){
    out << rhs._feet << "' " << rhs._inches << "\""; 
    return out; 
}

void Distance::init(){
    if (_inches < 0){ 
        _inches *= -1; 
    }

    while (_inches >= 12){
        _feet += 1;
        _inches -= 12; 
    }
}