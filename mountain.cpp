#include "mountain.h"
#include <string>
using std::string;

Mountain::Mountain()
{
  
};
Mountain::Mountain(string na, string co, int ele)
:name(na), country(co), elevation(ele)
{
  
};

//getters
string Mountain::getName(){return name;}
string Mountain::getCountry(){return country;}
int Mountain::getElevation(){return elevation;}

double Mountain::toMeters()
{
    double const conv = 3.2808;
    double result;
    return result = this->elevation/conv;
}