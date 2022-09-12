/*
File: main.cpp
Description: Final Project
Author: John Dorn
Email: dornj122324@student.vvc.edu
Date: 05/28/2022
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include "date.h"
#include "stockblock.h"
using std::string;
using std::fstream;

typedef std::queue<StockBlock> StockQueue;
typedef std::map<std::string,StockQueue> StockMap;
typedef std::map<std::string, StockQueue>::iterator Iter;

const int ZERO = 0;
const int TWO = 2;
/**
      Handle a user buying a given quantity of stock at a given price.
*/
void buy(StockMap &blocks,std::string symbol, int quantity, int price, Date buy_date) {
      // declare a queue of StockBlock call it stockqueue, probably should be pointer
      StockQueue* stockqueue;
      Iter it = blocks.find(symbol);
      if (it != blocks.end())  // please recognize that this is pseudocode, fill in what is being asked
      {
          // if so allocate a new stockQueue
          stockqueue = new StockQueue;

      }
      else
      {
          // get the stockQueue from the blocks map
          stockqueue = &it->second;
      }
      // add to the stockQueue a StockBlock with the quantity price and buy_date
     
      StockBlock newBlock(quantity, price, buy_date);
      stockqueue->push(newBlock);
      // update the blocks with the stockQueue keyed by the symbol
            
     // blocks.insert(std::pair<string, StockQueue>(symbol, *stockqueue));
}

/**
  Handle a user selling a given quantity of stock at a given price.
*/
void sell(StockMap &blocks,string symbol, int quantity, double price,Date sell_date) {
  Iter it = blocks.find(symbol);
  if (it != blocks.end())  // please recognize that this is pseudocode
  {
          // if so
        std::cout << "There are no stocks for " << symbol << " to sell" << std::endl;
        return;
  }
  // get the queue from the blocks StockMap
  // assign to stockQueue
  it->second.front().sell(quantity, price, sell_date);
  if (it->second.empty() ) 
  {
     // if so
     std::cout << "There are no stocks for " << symbol << " to sell" << std::endl;
     return;
  }
  // look at the head of the stockQueue and make sure to get the gain from the call to the sell method of the StockBlock
  if (it->second.front().isEmpty())
  {
      it->second.pop();
      // then remove the StockBlock from the stockQueue
  }
}

void scanner(string file_name, std::vector<string>& vect)
{
    std::fstream file;
    std::istringstream ist;
    string line;
    string word;
    string address;
    int count = 0;
    file.open(file_name, std::ios::in);
    if(file.is_open())
      {
        while(getline(file,line))
          {
              ist.clear();
              ist.str(line);
              while(ist.good())
                {
                    ist >> word;
                    vect.push_back(word);
                }
          }    
      }
    else
    {
        std::cout << "File failed to open. Exiting Program";
        exit(-1);
    }
    file.close();
}

bool isNumber(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while(it != s.end() && std::isdigit(*it)) it++;
    return !s.empty() && it == s.end();
}

std::ostream& operator<<(std::ostream& ost, Date& _dt)
{
    int day = _dt.getDay();
    int month = _dt.getMonth();
    int year = _dt.getYear();
    ost << month << '/' << day << '/' << year;
    return ost;
}

int main() {
       
//     blocks will need to be initialized
//     Then create a scanner using a File object with the data file
//     declare a map of string and a queue of StockBlock
      std::fstream file;
      std::vector<string> data;
      scanner("simulation.dat", data);
  
      StockMap blocks;  
      const int ONE = 1;
      const int TWO = 2;
      const int THREE = 3;
      const int FOUR = 4;
      const int EIGHT = 8;
      int numcount = 1;
      bool done = false;
      while (!done)
      {    
          
          for(auto e : data)
          {
            
            int symcount = 1;
            std::string action = "";
            std::string symbol = "";
            int quantity = 0;
            int price = 0;
            int month;
            int day;
            int year;
            if(e == "buy")
            {
              action = e;
              //std::cout << action << " ";
            }
            else if(e == "sell")
            {
              action = e;
              //std::cout << action << " ";
            }
            else if(e == "quit")
            {
              action = e;
              //std::cout << action;
            }
            
            if(!(isNumber(e)) && (e != "quit" || e != "sell" || e != "buy"))
            {
                symbol = e;
                //std::cout << symbol << " ";
    
            }
            if(isNumber(e) && numcount == ONE)
            {
                quantity = stoi(e);
                std::cout << quantity << " ";
                numcount++;
            }
            else if(isNumber(e) && numcount == TWO)
            {
                price = stoi(e);
                numcount--;
            }
            else
            {    
                string in = "";
                int scount = 0;
                for(auto c : e)
                  {
                     if(c != '/')
                     {
                       in += c;
                       scount++;
                       if(scount == TWO)
                       {
                         month = stoi(in);
                         in = "";
                       }
                       else if(scount == FOUR)
                       {
                         day = stoi(in);
                         in = "";
                       }
                       else if(scount == EIGHT)
                       {
                         year = stoi(in);
                         in = "";
                       }
                     }
                      
                  }
                numcount = 1;
            }
  
            Date date(month,day,year);
            Date date2(07,05,2000);

            //std::cout << date2;
            // get the action from the file
             if (action == "buy")
             {
                 // Write the code necessary to perform a buy order
                 // The buy method is in this class, but there is some code
                 // that needs to added here to properly call the buy order with the correct data items
               //buy(blocks, symbol, quantity, price, date);
             }
             else if (action == "sell")
             {
                 // Write the code necessary to perform a sell order
                 // The sell method is in this class, but there is some code
                 // that needs to added here to properly call the buy order with the correct data items
             }
             else if (action == "quit")
             {
                 // will quit
                return 0;
             }
        }
        
      }
}

