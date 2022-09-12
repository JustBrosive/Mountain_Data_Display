#ifndef STOCKBLOCK_H
#define STOCKBLOCK_H
#include "date.h"

class StockBlock
{
    private: 
        int price = 0;
        int quantity = 0;
        Date buy_date;
        Date sell_date;

    public: 
        StockBlock(int quantity, int price, Date buy_date);
        StockBlock();

        int sell(int quantity, int price, Date sell_date);
        bool isEmpty();
};
#endif