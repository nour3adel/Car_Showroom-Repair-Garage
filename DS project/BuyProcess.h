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
    string price;
    string chosencar;
    string model;
    string Date;

    BuyProcess();
    ~BuyProcess(void);
    BuyProcess(string, string, string,string, string);
    void buyCar();

   



};
