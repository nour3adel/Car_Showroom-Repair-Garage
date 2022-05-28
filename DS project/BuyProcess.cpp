#include "BuyProcess.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
BuyProcess::BuyProcess()
{
}

BuyProcess::~BuyProcess(void)
{
}

BuyProcess::BuyProcess(string id, string cust, string pr, string car, string date)
{
  
    Processid = id;
    Customerid = cust;
    
    chosencar = car;
    price = pr;
    Date = date;
    
}

void BuyProcess::buyCar()
{
}
