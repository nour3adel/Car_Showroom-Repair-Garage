#include "Showroom.h"
#include <iostream>
#include <string>
#include <vector>
#include<sstream>  


using namespace std;
Showroom::Showroom()
{
}
Showroom::Showroom(string idnu, string na, string loc, string nu, car c, car v)
{
    id = idnu;
    name = na;
    location = loc;
    number = nu;
    cars.push_back(c);
    cars.push_back(v);
}
Showroom::~Showroom(void)
{
}

void Showroom::addshowroom() {




    cout << "\n\t° PLEASE ENTER THE Showroom Name :-> ";
    cin >> name;
    cout << "\n\t° PLEASE ENTER THE Showroom Location :-> ";
    cin >> location;
    cout << "\n\t° PLEASE ENTER THE Showroom Phone :-> ";
    cin >> number;
   

    string x;
    do {
        system("cls");
        cout << "\t\n--------------------- ShowRoom Cars -------------------" << endl;
        car c;
        stringstream ss;
        int y = posa;
        ss << y;
        string k;
        ss >> k;

        c.id = k;
        cout << "\n\t° PLEASE ENTER THE Car Make :-> ";
        cin >> c.make;
        cout << "\n\t° PLEASE ENTER THE Car Model :-> ";
        cin >> c.model;
        cout << "\n\t° PLEASE ENTER THE Car Year :-> ";
        cin >> c.year;
        cout << "\n\t° PLEASE ENTER THE Car Price :-> ";
        cin >> c.price;
        cout << "\n\t° PLEASE ENTER THE Car Installment :-> ";
        cin >> c.Installment;
        cars.push_back(c);

        posa++;
        cout << "\n\n\t°TO ADD MORE ENTER ANY KEY ";
        cout << "\n\t°To Exit ENTER (N) ";
        cin >> x;
    } while (x != "N" && x != "n");

    cout << "\n\t° Showroom Is Added Succefully" << endl;
    system("pause");

}
void Showroom::updateshowroommenu() {
    cout << "\n\t|-------------------- Update Menu --------------------|" << endl;
    cout << "\n\t° Enter >-[1]-> to:-> Update ID\n";
    cout << "\n\t° Enter >-[2]-> to:-> Update name\n";
    cout << "\n\t° Enter >-[3]-> to:-> Update Location\n";
    cout << "\n\t° Enter >-[4]-> to:-> Update Phone\n";
    cout << "\n\n\n*********\n";
    cout << "\n\t° -> Your Choise is:-> ";


}
void Showroom::updatecarmenu() {
    cout << "\n\t|-------------------- Update Menu --------------------|" << endl;
    cout << "\n\t° Enter >-[1]-> to:-> Update make\n";
    cout << "\n\t° Enter >-[2]-> to:-> Update model\n";
    cout << "\n\t° Enter >-[3]-> to:-> Update year\n";
    cout << "\n\t° Enter >-[4]-> to:-> Update price\n";
    cout << "\n\t° Enter >-[5]-> to:-> Update installment\n";
    cout << "\n\n\n*********\n";
    cout << "\n\t° -> Your Choise is:-> ";


}



