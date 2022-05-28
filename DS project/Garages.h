#pragma once
#include<string>
#include <vector>
using namespace std;

struct service
{
public:
    string id;
    string name;
    string price;


};
class Garages

{
    public:
        int posa = 1;
        string id;
        string name;
        string location;
        string number;
        vector <service> serv;

        Garages();
        ~Garages(void);
        Garages(string, string, string, string, service, service);
        void addGarages();
        void updateGaragesmenu();
        void updateservicemenu();

};
