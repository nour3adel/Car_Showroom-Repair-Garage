#pragma once
#include <string>

using namespace std;


class Admin
{
public:
	/*     Admin Login     */
	string adminid = "1";
	string username = "admin";
	string password = "123";
	/************************/

	bool adminlogin();
	~Admin(void);

};

