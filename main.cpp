/*
File: main.cpp
Description: 202-Final-Exam
Author: John Dorn
Email: dornj122324@student.vvc.edu
Date: 06/NT/2022
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "mountain.h"
using std::vector;

//finds and returns lowest elevation
int minElevation(std::vector<Mountain> &vect)
{
    int min = vect[0].getElevation();
    int a = 0;
    for(auto x : vect)
      {
          if(min > x.getElevation())
          {
              min = x.getElevation();
          }
      }
    return min;
}

//print the mountain name a value of lowest mounain
void isLowest(std::vector<Mountain> &vect)
{
    bool low = false;
    int min = minElevation(vect);
    for(auto e : vect)
      {
        if(min == e.getElevation())
        {
            std::cout << "Lowest Mountain:\n";
            std::cout << e.getName() << ":    " << e.getElevation();
        }    
      }
}

//print the Mountain objects in vector in a grid-like layout
void printMountains(std::vector<Mountain> &vect)
{
    const int NT = 19;
    const int ONE = 1;
    for(auto e : vect)
      {
          
          std::cout << e.getName();
          if(e.getName().length() == NT)
          {
              for(int i = 1; i < NT + ONE; i++)
              {
                std::cout << " ";
              }
          }
          else if(e.getName().length() < NT)
          {
              for(int i = 1 - (NT - e.getName().length()); i < NT + ONE; i++)
              {
                std::cout << " ";
              }
          }
          else
          {
              for(int i = (e.getName().length() - NT); i < NT; i++)
              std::cout << " ";
          }
        
        std::cout << e.getCountry();
        
        if(e.getCountry().length() == NT)
        {
            for(int i = 1; i < NT; i++)
            {
              std::cout << " ";
            }
        }
        else if(e.getName().length() < NT)
        {
            for(int i = 1 - (NT - e.getCountry().length()); i < NT; i++)
            {
              std::cout << " ";
            }
        }
        else
        {
            for(int i = (e.getCountry().length() - (NT - ONE)); i < NT; i++)
            std::cout << " ";
        }
        std::cout << e.getElevation() << "ft" << "\n";
      }
}

int main() {
    //declare and intialize Mountain objects
    Mountain chimborazo("Chimborazo", "Ecuador", 20549);
    Mountain matterhorn("Matterhorn", "Switzerland", 14692);
    Mountain greece("Olympus", "Greece(Macedonia)", 20549);
    Mountain everest("Everest", "Nepal", 29029);
    Mountain marcy("Mount Marcy - Adirondacks", "United States", 5344);
    Mountain mitchell("Mount Mitchell - Blue Ridge", "United States", 6684);
    Mountain zugspitze("Zugpitze", "Switzerland", 9719);

    //place objects in a vector 
    vector<Mountain> mvect;
    mvect.push_back(chimborazo);
    mvect.push_back(matterhorn);
    mvect.push_back(greece);
    mvect.push_back(everest);
    mvect.push_back(marcy);
    mvect.push_back(mitchell);
    mvect.push_back(zugspitze);

    /*for(auto e : mvect)
      {
          std::cout << e.getElevation() << "\n";
      }*/
  
  int min = minElevation(mvect);
  //std::cout << min;
  std::cout << "Mountain" << "                              " << "Country" << "                              " << "Elevation\n\n";
  printMountains(mvect);
  std::cout << "\n";

  std::cout << "*******************************************************\n";
  
  isLowest(mvect);

  std::cout << "\n*******************************************************";
  
  std::cout << "\n\nConversion of Mt.Everest's elevation to meters:\n";
  double n = mvect[3].toMeters();
  std::cout << n;
  return 0;
}