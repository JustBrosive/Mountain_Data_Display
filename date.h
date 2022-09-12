#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

class Date
{
  private:
  int month = 0;
  int day = 0;
  int year = 0;
  std::string date;
  
  public:
    //getters for month, day, and year
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    Date(int _month, int _day, int _year);
    Date();
    //overloaded operator for printing the date
};



#endif