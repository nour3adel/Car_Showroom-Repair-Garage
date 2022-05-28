#pragma once
#include<string>
#include <vector>
using namespace std;

struct car
{
public:
    string id;
    string make;
    string model;
    string year;
    string price;
    string Installment;

};
class Showroom

{
public:
    int posa = 1;
    string id;
    string name;
    string location;
    string number;
    vector <car> cars;

    Showroom();
    ~Showroom(void);
    Showroom(string, string, string, string, car, car);
    void addshowroom();

    void updateshowroommenu();

    void updatecarmenu();

   

};
