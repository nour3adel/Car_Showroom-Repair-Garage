#pragma once
#include<string>
#include <vector>
using namespace std;


class BuyProcess

{
public:
    int posa = 1;
    string Processid;
    string Customerid;
    string Date;
    string price;
    string chosencar;

    BuyProcess();
    ~BuyProcess(void);
    BuyProcess(string, string, string,string, string);
    void buyCar();

   



};
