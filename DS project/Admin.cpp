#include "Admin.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;


bool Admin:: adminlogin() {
	for (int attempts = 1; attempts <= 3; ++attempts) {
		cout << "\n\t|-------------------- Admin Login --------------------|\n\n\n";
		string d;
		cout << "\n\t° -> Your ID is:-> "; cin >> d;
		string u;
		cout << "\n\t° -> Your Username is:-> "; cin >> u;

		string p;
		cout << "\n\t° -> Your Password is:-> "; cin >> p;




		if (username == u && password == p && adminid == d) {
			cout << "\n\n\n\t° Access granted. \n\n";
			system("pause");
			return true;
		}
			else {
			cout << "\n\n\n\t°Invalid Admin Login\n\n";
			system("pause");
			system("cls");
			}
	}

	
	cout << "\n\n\n\t°Too many invalid login attempts.\n\n\t°....Exiting.\n\n";
	system("pause");
	return false;

}

Admin::~Admin(void)
{
}