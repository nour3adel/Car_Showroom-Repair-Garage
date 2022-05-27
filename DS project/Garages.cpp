#include "Garages.h"
#include <iostream>
#include <string>
#include <vector>
#include<sstream>  
string y;

using namespace std;

Garages::Garages()
{
}

Garages::~Garages(void)
{
}

Garages::Garages(string idnu, string na, string loc, string nu, service c, service v)
{
    id = idnu;
    name = na;
    location = loc;
    number = nu;
    serv.push_back(c);
    serv.push_back(v);
}

void Garages::addGarages()
{
    cout << "\n\t° PLEASE ENTER THE Garage Name :-> ";
    cin >> name;
    cout << "\n\t° PLEASE ENTER THE Garage Location :-> ";
    cin >> location;
    cout << "\n\t° PLEASE ENTER THE Garage Phone :-> ";
    cin >> number;
    cout << "\n\n--------------------- Garages Services -------------------" << endl;

    do {
        
        service c;
        stringstream ss;
        int gg = posa;
        ss << gg;
        string k;
        ss >> k;

    
      
        c.id = k;
        cout << "\n\t° PLEASE ENTER THE Service name :-> ";
        cin >> c.name;
        cout << "\n\t° PLEASE ENTER THE Service Price :-> ";
        cin >> c.price;

        serv.push_back(c);

        posa++;
        cout << "\n\n\nTO ADD MORE ENTER (Y).. OR To Exit Enter (N) ";
        cin >> y;
       
    } while (y != "N" && y != "n");

    cout << "\n\t° Garages Is Added Succefully" << endl;
    system("pause");
}

void Garages::updateGaragesmenu()
{
    cout << "\n\t|-------------------- Update Menu --------------------|" << endl;
    cout << "\n\t° Enter >-[1]-> to:-> Update ID\n";
    cout << "\n\t° Enter >-[2]-> to:-> Update name\n";
    cout << "\n\t° Enter >-[3]-> to:-> Update Location\n";
    cout << "\n\t° Enter >-[4]-> to:-> Update Phone\n";
    cout << "\n\n\n*********\n";
    cout << "\n\t° -> Your Choise is:-> ";
}

void Garages::updateservicemenu()
{
    cout << "\n\t|-------------------- Update Menu --------------------|" << endl;
    cout << "\n\t° Enter >-[1]-> to:-> Update make\n";
    cout << "\n\t° Enter >-[2]-> to:-> Update price\n";

    cout << "\n\n\n*********\n";
    cout << "\n\t° -> Your Choise is:-> ";
}


