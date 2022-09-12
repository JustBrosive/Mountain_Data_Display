#include<string>


#ifndef MOUNTAIN_H
#define MOUNTAIN_H

class Mountain
{
    private:
       std::string name; 
       std::string country; 
      // elevation in feet
       int elevation; 
    public:
      //empty constructor and value based costructor
      Mountain();
      Mountain(std::string _name, std::string _country, int _elevation);

      //getters
      std::string getName();
      std::string getCountry();
      int getElevation();

      //function to convert feet to meters
      double toMeters();
};

#endif