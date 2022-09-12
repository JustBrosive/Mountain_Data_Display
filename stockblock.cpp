#include "stockblock.h"
#include "date.h"

StockBlock::StockBlock(int _q, int _p, Date _bd) {
// implement the constructor
    quantity = _q;
    price = _p;
    buy_date = _bd;
}
StockBlock::StockBlock()
{
  
}

int StockBlock::sell(int _q, int _p,Date _sd) {
    sell_date = _sd;
    int gain = 0;
    if (this->quantity < _q)
    {
       
      // put the code for the gain calculation  here
        gain = (quantity * price) - (_p * _q);
      // and return the gain
      // also, make sure to set the quantity to 0
        this->quantity = 0;
        return gain;
    }
    else
    {
        // put the code for the gain calculation here and return the gain
        gain = (quantity * price) - (_p * _q);
        quantity = quantity - _q;
        return gain;
    }
}

bool StockBlock::isEmpty() {
      return (this->quantity == 0);
}
