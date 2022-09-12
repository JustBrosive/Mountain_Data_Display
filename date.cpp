// implement the Date class
#include "date.h"

Date::Date(int _m, int _d, int _y)
:month(_m), day(_d), year(_y)
{
    date = std::to_string(_m) + '/' + std::to_string(_d) + '/' + std::to_string(_y);
};

Date::Date()
{
  
};

int Date::getMonth() const{return month;}
int Date::getDay() const{return day;}
int Date::getYear() const{return year;}



