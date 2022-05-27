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

BuyProcess::BuyProcess(string id, string cust, string date, string car, string pr)
{
  
    Processid = id;
    Customerid = cust;
    Date = date;
    chosencar = car;
    price = pr;
    
}

void BuyProcess::buyCar()
{
}
