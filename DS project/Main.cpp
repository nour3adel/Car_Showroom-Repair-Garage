#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime> 
#include<sstream> 

#include "Customer.h"
#include "Read_Write.h"
#include "Admin.h"
#include "Show.h"
using namespace std;

///************************************************///
Customer C;
Admin A;
Showroom S;
Garages g3;
BuyProcess B;

///************************************************///
vector<Showroom> Vshowroom;
vector<Garages> Vgar;
vector<BuyProcess> Vb;
vector<car> Vtime;

void CustomerMenu();

string usn;
int tm;
void valid(string str) //function declaration for keeping records   
{
	string dir, user;
	ifstream file;
	dir = str + ".txt";
	file.open(dir.c_str());
	if (!file.is_open() && file.fail())
	{
		//file.close();
		return;
	}
	else
	{
		tm++;
		if (tm == 3)
		{
			cout << "\n\n\n\t°Too many invalid Register attempts.\n\n\t°....Exiting.\n\n";
			system("pause");
			//file.close();
			return;
		}
		cout << "\nThis username already exists!\n\n\t° Create Your Username : ";
		cin >> usn;
		//file.close();
		valid(usn);
	}
}
string naame;
int position;

int main() {

	//////--> Initializing <--//////
	int cschoice = 1;    // ----> for customer (login or register)
	int subchoice = 0;
	int subsubchoice = 0;
	int choice = 0;
	int out = 1;

	readhistory(Vb);
	Vb.erase(Vb.begin() + Vb.size() - 1);

	readshowrooms(Vshowroom);
	Vshowroom.erase(Vshowroom.begin() + Vshowroom.size() - 1);
	reader(Vshowroom);
	for (int i = 0; i < Vshowroom.size(); i++)
	{
		Vshowroom[i].cars.erase(Vshowroom[i].cars.begin() + Vshowroom[i].cars.size() - 1);
	}

	readgarages(Vgar);
	Vgar.erase(Vgar.begin() + Vgar.size() - 1);
	readserv(Vgar);
	for (int i = 0; i < Vgar.size(); i++)
	{
		Vgar[i].serv.erase(Vgar[i].serv.begin() + Vgar[i].serv.size() - 1);
	}



	system("color 06");
	cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\n\t\t@@@@ ----------> WELCOME to: <---------- @@@@";
	cout << "\n\t\t@@@@-> Car ShowRooms & Repair Shops <-@@@@";
	cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << "\n\n";


	cout << "| \t\t TA ->> Engy Abdullah <<-- |\n" << endl;

	cout << "\t\t >>>---- Project Implemented By GEN_031 ---<<<" << endl << endl;

	cout << "\t\t  1- Nour Adel  " << endl;
	cout << "\t\t  2- Ahmed Osama " << endl;
	cout << "\t\t  3- Ahmed Abdelwahab " << endl;
	cout << "\t\t  4- Ahmed Awad " << endl;
	cout << "\t\t  5- Omnia Khaled " << endl;
	cout << "\t\t  6- Amera Khaled " << endl;
	cout << "\t\t  7- Ahmed Rabiee  " << endl << endl;

	system("pause");
	system("cls");
	do {
		system("cls");
		cout << "\n\t|-------------------- Main Menu --------------------|" << endl;
		cout << "\n\t° Enter >-[1]-> to:-> be Customer\n";
		cout << "\n\t° Enter >-[2]-> to:-> Administration\n";
		cout << "\n\t° Enter >-[0]-> to:-> Exit\n\n";
		cout << "\n\n\n*********\n";

		cout << "\n\t° -> Your Choise is:-> ";
		cin >> choice;
		////////////////////////////////////////////////////////////////////////////////
		if (choice == 1) {

			int cschoice, exit = 0;
			string ans, psd, name, fname, bio, usern, pw, line, nusn;
			ofstream fileo;
			ifstream filei;
			system("cls");


			while (exit == 0)
			{
				system("cls");
				cout << "\n\t|-------------------- Customer --------------------|" << endl;
				system("color 09");
				cout << "\n\t° Enter >-[1]-> to:-> Login\n";
				cout << "\n\t° Enter >-[2]-> to:-> Register\n";
				cout << "\n\t° Enter >-[0]-> to:->  Return Main-Menu\n\n";
				cout << "\n\n\n*********\n";

				cout << "\n\t° -> Your Choise is:-> ";
				cin >> cschoice;
				if (cschoice == 1)
				{
					system("cls");
					cout << "\n\t|-------------------- Customer Login --------------------|" << endl;

					cout << "\n\t° Enter Your Username : ";
					cin >> usn;

					cout << "\n\t° Enter Your Password : ";
					cin >> psd;
					fname = usn + ".txt";
					filei.open(fname.c_str());
					if (!filei.is_open() && filei.fail())
					{
						system("cls");

						cout << "\n\t°You are not registered, please register before logging in.\n" << endl;
						system("pause");
						filei.close();
						continue;


					}
					getline(filei, usern);
					getline(filei, line);
					getline(filei, pw);
					if (usn == usern && psd == pw)
					{


						cout << "\n\n\t°You are successfully logged in:)\n\n\t°YOUR PROFILE Daetails:\n";
						cout << "\n\t° User-name:" << usern << endl;
						naame = usern;

						cout << "\n\t° Name:" << line << endl;
						getline(filei, line);
						cout << "\n\t° Bio:" << line << "\n\n";
						filei.close();

						system("pause");
						system("cls");
						CustomerMenu();




					}
					else {
						system("cls");

						cout << "\n\n\t°Wrong username or password!\n\n\t°Please try Again.\n" << endl;
						system("pause");
					}
					cout << endl;
				}
				else if (cschoice == 2)
				{
					system("cls");
					cout << "\n\t|-------------------- Customer Register --------------------|" << endl;

					cout << "\n\t° Enter Your Name : ";
					cin.ignore();
					getline(cin, name);
					cout << "\n\t° Enter Your Username : ";
					cin >> usn;
					naame = usn;
					tm = 0;
					valid(usn);
					if (tm >= 3)
					{
						continue;
					}
					cout << "\n\t° Enter Your Password : ";
					cin >> psd;
					fname = usn + ".txt";
					//cout<<fname;
					fileo.open(fname);
					fileo << usn << endl << name << endl << psd << endl;
					cout << "\n\n\t°You are successfully registered:)" << endl;
					cout << "\n\n\t°Add to your bio and press enter when you are done:";
					cin.ignore();
					getline(cin, bio);
					fileo << bio << endl;
					cout << "\nYour bio is saved as: " << bio << endl;
					fileo.close();

					system("pause");
					system("cls");
					CustomerMenu();
				}
				else
				{
					exit = 1;
				}
			}



		}
		////////////////////////////////////////////////////////////////////////////////
		else if (choice == 2) {
			system("cls");
			system("color 0A");
			if (A.adminlogin()) {
				
				do {
					system("cls");
					cout << "\n\t|-------------------- Hello Admin --------------------|" << endl;
					////////////////////--> Options <--////////////////////
					cout << "\n\t° Enter >-[1]-> to:-> Add\n";
					cout << "\n\t° Enter >-[2]-> to:-> Update\n";
					cout << "\n\t° Enter >-[3]-> to:-> Delete\n";
					cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";
					cout << "\n\n\n*********\n";
					cout << "\n\t° -> Your Choise is:-> ";
					cin >> subchoice;

					while (subchoice != 0 && subchoice != 1 && subchoice != 2 && subchoice != 3) {
						cout << "\t\tInvalid ";
						cout << "\n\t° -> Your Choise is:-> ";
						cin >> subchoice; cout << endl;

					}
					if (subchoice == 1) { //Add
							system("cls");
							cout << "\n\t|-------------------- Add (Addmin)--------------------|" << endl;
							////////////////////--> Options <--////////////////////
							cout << "\n\t° Enter >-[1]-> to:-> Add Showroom\n";
							cout << "\n\t° Enter >-[2]-> to:-> Add Garage\n";
							cout << "\n\t° Enter >-[3]-> to:-> Add Car\n";
							cout << "\n\t° Enter >-[4]-> to:-> Add Service\n";
							cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";
							cout << "\n\n\n*********\n";
							cout << "\n\t° -> Your Choise is:-> ";
							cin >> subsubchoice;
							while (subsubchoice != 0 && subsubchoice != 1 && subsubchoice != 2 && subsubchoice != 3 && subsubchoice != 4) {
								cout << "\t\tInvalid ";
								cout << "\n\t° -> Your Choise is:-> ";
								cin >> subsubchoice; cout << endl;

							}
							if (subsubchoice == 1) {
								system("cls");
								bool ee = true;
								do {
									system("cls");
									cout << "\n\t|-------------------- Add ShowRoom --------------------|" << endl;

									cout << "\n\t° PLEASE ENTER THE Showroom ID :-> ";

									cin >> S.id;
									for (int i = 0; i < Vshowroom.size(); i++)
									{
										if (S.id != Vshowroom[i].id)
										{
											ee = false;
										}
										if (S.id == Vshowroom[i].id)
										{
											cout << "\n\t° THE ShowroomID IS EXIST, TRY AGAIN\n\n";

											ee = true;
											system("pause");
											break;
										}

									}


								} while (ee);


								S.addshowroom();
								Vshowroom.push_back(S);
								writec(Vshowroom);
								writeshowrooms(Vshowroom);

							}
							if (subsubchoice == 2) {
								system("cls");
								bool ee = true;
								do {
									system("cls");
									cout << "\n\t|-------------------- Add Garage --------------------|" << endl;

									cout << "\n\t° PLEASE ENTER THE Garage ID :-> ";

									cin >> g3.id;
									for (int i = 0; i < Vgar.size(); i++)
									{
										if (g3.id != Vgar[i].id)
										{
											ee = false;
										}
										if (g3.id == Vgar[i].id)
										{
											cout << "\n\t\t THE Garage ID IS EXIST, TRY AGAIN\n";
											ee = true;
											system("pause");
											break;
										}

									}

								} while (ee);

								g3.addGarages();
								Vgar.push_back(g3);
								writeserv(Vgar);
								writegarages(Vgar);

							}
							if (subsubchoice == 3) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Showroom ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Add Cars --------------------|" << endl;
									cout << "\n\t°Enter Showroom ID To Add Cars to it :-> ";
									cin >> S.id;
									for (int i = 0; i < Vshowroom.size(); i++)
									{
										if (S.id == Vshowroom[i].id) {

											S.posa = i;
											int num = Vshowroom[S.posa].cars.size();
											string kr;
											do {
												car r;
												int x = ++num;
												stringstream ss;
												ss << x;
												string k;
												ss >> k;

												r.id = k;
												system("cls");
												cout << "\n\t|--------------------  Cars Details --------------------|" << endl;
												cout << "\n\t° PLEASE ENTER THE Car Make :-> ";
												cin >> r.make;
												cout << "\n\t° PLEASE ENTER THE Car Model :-> ";
												cin >> r.model;
												cout << "\n\t° PLEASE ENTER THE Car Year :-> ";
												cin >> r.year;
												cout << "\n\t° PLEASE ENTER THE Car Price :-> ";
												cin >> r.price;
												cout << "\n\t° PLEASE ENTER THE Car Installment :-> ";
												cin >> r.Installment;
												Vshowroom[S.posa].cars.push_back(r);
												
												cout << "-------------------------------------------------------------" << endl;
												cout << "\n\n\n\t°TO ADD MORE Cars ENTER -> (Y)";
												cout << "\n\n\t°To Exit Enter -> (N) ";
												cin >> kr;

											} while (kr != "N" && kr != "n");
											cout << "-------------------------------------------------------------" << endl;
											cout << "\n\t° Cars are Added Succefully" << endl;
											system("pause");
											writec(Vshowroom);
											writeshowrooms(Vshowroom);
											rr = false;
											f = false;
											break;

										}
										if (S.id != Vshowroom[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);

							}
							if (subsubchoice == 4) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Garage ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Add Service --------------------|" << endl;
									cout << "\n\t°Enter Garage ID To Add Service to it :-> ";
									cin >> g3.id;
									for (int i = 0; i < Vgar.size(); i++)
									{
										if (g3.id == Vgar[i].id) {

											g3.posa = i;

											int num = Vgar[g3.posa].serv.size();
											string yt;
											do {
												service r;
												int x = ++num;
												stringstream ss;
												ss << x;
												string k;
												ss >> k;

												r.id = k;
												system("cls");
												cout << "\n\t° PLEASE ENTER THE Service Name :-> ";
												cin >> r.name;
												cout << "\n\t° PLEASE ENTER THE Service Price :-> ";
												cin >> r.price;

												Vgar[g3.posa].serv.push_back(r);
												
												cout << "-------------------------------------------------------------" << endl;
												cout << "\n\n\n\t°TO ADD MORE Services ENTER -> (Y)";
												cout << "\n\n\t°To Exit Enter -> (N) ";
												cin >> yt;
											} while (yt != "N" && yt != "n");
											cout << "-------------------------------------------------------------" << endl;
											cout << "\n\t° Services are Added Succefully" << endl;
											system("pause");
											writeserv(Vgar);
											writegarages(Vgar);
											rr = false;
											f = false;
											break;

										}
										if (g3.id != Vgar[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);

							}
							if (subsubchoice == 0) {
								system("cls");
							}
							//Returns to Menu
					}          
					
                    else if (subchoice == 2) { //Update
							system("cls");
							cout << "\n\t|-------------------- Update (Addmin)--------------------|" << endl;

							////////////////////--> Options <--////////////////////

							cout << "\n\t° Enter >-[1]-> to:-> Update Showroom\n";
							cout << "\n\t° Enter >-[2]-> to:-> Update Garages\n";
							cout << "\n\t° Enter >-[3]-> to:-> Update Car\n";
							cout << "\n\t° Enter >-[4]-> to:-> Update Service\n";
							cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";
							cout << "\n\n\n*********\n";
							cout << "\n\t° -> Your Choise is:-> ";
							cin >> subsubchoice;

							while (subsubchoice != 0 && subsubchoice != 1 && subsubchoice != 2 && subsubchoice != 3 && subsubchoice != 4) {
								cout << "\t\tInvalid ";
								cout << "\n\t° -> Your Choise is:-> ";
								cin >> subsubchoice; cout << endl;

							}
							if (subsubchoice == 1) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Showroom ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Update Showroom --------------------|" << endl;
									showshowrooms(Vshowroom);
									cout << "\n\t°Enter Showroom ID To Update :-> ";
									cin >> S.id;
									for (int i = 0; i < Vshowroom.size(); i++)
									{
										if (S.id == Vshowroom[i].id) {
											system("cls");
											S.posa = i;
											S.updateshowroommenu();
											int subsubchoice;
											cin >> subsubchoice;
											while (subsubchoice != 1 && subsubchoice != 2 && subsubchoice != 3 && subsubchoice != 4) {
												cout << "\t\tInvalid ";
												cout << "\n\t° -> Your Choise is:-> ";
												cin >> subsubchoice; cout << endl;

											}
											if (subsubchoice == 1) {
												system("cls");
												string newid;
												bool ee = true;
												do {
													system("cls");
													cout << "\n\t°Enter Showroom New ID :-> ";

													cin >> newid;

													for (int i = 0; i < Vshowroom.size(); i++)
													{
														if (newid != Vshowroom[i].id)
														{
															ee = false;
														}
														if (newid == Vshowroom[i].id)
														{
															cout << "\n\t\t°ID IS EXIST, Enter Another ID\n";
															ee = true;
															system("pause");
															break;
														}

													}


												} while (ee);



												Vshowroom[S.posa].id = newid;
												cout << "\n\t° Showroom ID is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 2) {
												system("cls");
												cout << "\n\t°Enter Showroom New Name :-> ";
												string newname;
												cin >> newname;
												Vshowroom[S.posa].name = newname;
												cout << "\n\t° Showroom Name is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 3) {
												system("cls");
												cout << "\n\t°Enter Showroom New Location :-> ";
												string newloc;
												cin >> newloc;
												Vshowroom[S.posa].location = newloc;
												cout << "\n\t° Showroom location is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 4) {
												system("cls");
												cout << "\n\t°Enter Showroom New Phone Number :-> ";
												string newPhone;
												cin >> newPhone;
												Vshowroom[S.posa].number = newPhone;
												cout << "\n\t° Showroom PhoneNumber is Updated" << endl;
												system("pause");


											}
											writec(Vshowroom);
											writeshowrooms(Vshowroom);
											rr = false;
											f = false;
											break;


										}
										if (S.id != Vshowroom[i].id) {
											rr = true;
											f = true;
										}



									}
								} while (rr);

							}
							if (subsubchoice == 2) {
								system("cls");
								bool rr = true;
								bool f = false;


								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Garage ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Update Garage --------------------|" << endl;
									showGarages(Vgar);
									cout << "\n\t°Enter Garage ID To Update :-> ";
									cin >> g3.id;
									for (int i = 0; i < Vgar.size(); i++)
									{
										if (g3.id == Vgar[i].id) {
											system("cls");
											g3.posa = i;
											g3.updateGaragesmenu();
											int subsubchoice;
											cin >> subsubchoice;
											while (subsubchoice != 1 && subsubchoice != 2 && subsubchoice != 3 && subsubchoice != 4) {
												cout << "\t\tInvalid ";
												cout << "\n\t° -> Your Choise is:-> ";
												cin >> subsubchoice; cout << endl;

											}
											if (subsubchoice == 1) {
												system("cls");
												string newid;
												bool ee = true;
												do {
													system("cls");
													cout << "\n\t°Enter Garage New ID :-> ";

													cin >> newid;

													for (int i = 0; i < Vgar.size(); i++)
													{
														if (newid != Vgar[i].id)
														{
															ee = false;
														}
														if (newid == Vgar[i].id)
														{
															cout << "\n\t\t°ID IS EXIST, Enter Another ID\n";
															ee = true;
															system("pause");
															break;
														}

													}


												} while (ee);



												Vgar[g3.posa].id = newid;
												cout << "\n\t° Garage ID is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 2) {
												system("cls");
												cout << "\n\t°Enter Garage New Name :-> ";
												string newname;
												cin >> newname;
												Vgar[g3.posa].name = newname;
												cout << "\n\t° Garage Name is Updated" << endl;
												system("pause");
											}
											if (subsubchoice == 3) {
												system("cls");
												cout << "\n\t°Enter Garage New Location :-> ";
												string newloc;
												cin >> newloc;
												Vgar[g3.posa].location = newloc;
												cout << "\n\t° Garage location is Updated" << endl;
												system("pause");
											}
											if (subsubchoice == 4) {
												system("cls");
												cout << "\n\t°Enter Garage New Phone Number :-> ";
												string newPhone;
												cin >> newPhone;
												Vgar[g3.posa].number = newPhone;
												cout << "\n\t° Garage PhoneNumber is Updated" << endl;
												system("pause");

											}
											writeserv(Vgar);
											writegarages(Vgar);
											rr = false;
											f = false;
											break;

										}
										if (g3.id != Vgar[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);


							}
							if (subsubchoice == 3) {
								system("cls");
								bool rr = true;
								bool f = false;


								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Showroom ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Update Showroom Cars --------------------|" << endl;
									showshowrooms(Vshowroom);

									cout << "\n\t°Enter Showroom ID you want to Update Car of it :->";
									cin >> S.id;
									for (int i = 0; i < Vshowroom.size(); i++)
									{

										if (S.id == Vshowroom[i].id) {
											system("cls");
											S.posa = i;
											showcars(Vshowroom,S.posa);
											cout << "Enter ID of Car you want to update" << endl;
											string carid;
											cin >> carid;

											int num = stoi(carid);
											system("cls");
											S.updatecarmenu();
											int subsubchoice;
											cin >> subsubchoice;
											while (subsubchoice != 1 && subsubchoice != 2 && subsubchoice != 3 && subsubchoice != 4 && subsubchoice != 5) {
												cout << "\t\tInvalid ";
												cout << "\n\t° -> Your Choise is:-> ";
												cin >> subsubchoice; cout << endl;

											}

											if (subsubchoice == 1) {
												system("cls");

												cout << "\n\t°Enter New Make :-> ";
												string newmake;
												cin >> newmake;



												Vshowroom[S.posa].cars[num - 1].make = newmake;

												cout << "\n\t° Showroom Car Make is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 2) {
												system("cls");

												cout << "\n\t°Enter New Model :-> ";
												string newmodel;
												cin >> newmodel;

												Vshowroom[S.posa].cars[num - 1].model = newmodel;

												cout << "\n\t° Showroom Car Model is Updated" << endl;
												system("pause");


											}
											if (subsubchoice == 3) {
												system("cls");

												cout << "\n\t°Enter New Year :-> ";
												string newYear;
												cin >> newYear;

												Vshowroom[S.posa].cars[num - 1].year = newYear;

												cout << "\n\t° Showroom Car Year is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 4) {
												system("cls");

												cout << "\n\t°Enter New Price :-> ";
												double newprice;
												cin >> newprice;

												Vshowroom[S.posa].cars[num - 1].price = newprice;

												cout << "\n\t° Showroom Car Price is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 5) {
												system("cls");

												cout << "\n\t°Enter New Installment :-> ";
												double newinstall;
												cin >> newinstall;

												Vshowroom[S.posa].cars[num - 1].Installment = newinstall;

												cout << "\n\t° Showroom Car Installment is Updated" << endl;
												system("pause");

											}
											writec(Vshowroom);
											writeshowrooms(Vshowroom);
											rr = false;
											f = false;
											break;

										}
										if (S.id != Vshowroom[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);



							}
							if (subsubchoice == 4) {
								system("cls");
								bool rr = true;
								bool f = false;


								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Garage ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Update Garage Service --------------------|" << endl;
									showGarages(Vgar);
									cout << "\n\t°Enter Garage ID To Update Services of it :-> ";

									cin >> g3.id;
									for (int i = 0; i < Vgar.size(); i++)
									{
										if (g3.id == Vgar[i].id) {
											system("cls");
											g3.posa = i;
											showservices(Vgar,g3.posa);
											cout << "\n\t°Enter ID of Service you want to update:->";
											string serviceid;
											cin >> serviceid;
											int num = stoi(serviceid);
											system("cls");
											g3.updateservicemenu();
											int subsubchoice;
											cin >> subsubchoice;
											while (subsubchoice != 1 && subsubchoice != 2) {
												cout << "\t\tInvalid ";
												cout << "\n\t° -> Your Choise is:-> ";
												cin >> subsubchoice; cout << endl;

											}

											if (subsubchoice == 1) {
												system("cls");


												cout << "\n\t°Enter New Service Name :-> ";
												string newname;
												cin >> newname;

												Vgar[g3.posa].serv[num - 1].name = newname;

												cout << "\n\t° Garage service name is Updated" << endl;
												system("pause");

											}
											if (subsubchoice == 2) {
												system("cls");

												cout << "\n\t°Enter New Service Price :-> ";
												double newprice;
												cin >> newprice;

												Vgar[g3.posa].serv[num - 1].price = newprice;

												cout << "\n\t° Garage service Price is Updated" << endl;
												system("pause");


											}
											writeserv(Vgar);
											writegarages(Vgar);
											rr = false;
											f = false;
											break;
										}

										if (g3.id != Vgar[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);


							}

							if (subsubchoice == 0) {
								system("cls");
							}

						}

				    else if (subchoice == 3) { //Delete
							system("cls");
							cout << "\n\t|-------------------- Delete (Addmin)--------------------|" << endl;
							////////////////////--> Options <--////////////////////
							cout << "\n\t° Enter >-[1]-> to:-> Delete Showroom\n";
							cout << "\n\t° Enter >-[2]-> to:-> Delete Garage\n";
							cout << "\n\t° Enter >-[3]-> to:-> Delete Car\n";
							cout << "\n\t° Enter >-[4]-> to:-> Delete Service\n";

							cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

							cout << "\n\n\n*********\n";
							cout << "\n\t° -> Your Choise is:-> ";
							cin >> subsubchoice;

							while (subsubchoice != 0 && subsubchoice != 1 && subsubchoice != 2 && subsubchoice != 3 && subsubchoice != 4) {
								cout << "\t\tInvalid ";
								cout << "\n\t° -> Your Choise is:-> ";
								cin >> subsubchoice; cout << endl;

							}
							if (subsubchoice == 1) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Showroom ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Delete Showroom --------------------|" << endl;
									showshowrooms(Vshowroom);
									cout << "\n\t°Enter Showroom ID you want to Delete :-> ";

									cin >> S.id;
									for (int i = 0; i < Vshowroom.size(); i++)
									{
										if (S.id == Vshowroom[i].id) {
											system("cls");
											S.posa = i;
											Vshowroom.erase(Vshowroom.begin() + S.posa);
											cout << "\n\t° Showroom  is Deleted" << endl;
											writec(Vshowroom);
											writeshowrooms(Vshowroom);
											system("pause");
											rr = false;
											f = false;
											break;

										}
										if (S.id != Vshowroom[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);
							}
							if (subsubchoice == 2) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Garage ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Delete Garage --------------------|" << endl;
									showGarages(Vgar);
									cout << "\n\t°Enter Garage ID you want to Delete :-> ";
									cin >> g3.id;
									for (int i = 0; i < Vgar.size(); i++)
									{
										if (g3.id == Vgar[i].id) {
											system("cls");
											g3.posa = i;
											Vgar.erase(Vgar.begin() + g3.posa);
											cout << "\n\t° Garage   is Deleted" << endl;
											writeserv(Vgar);
											writegarages(Vgar);
											system("pause");
											rr = false;
											f = false;
											break;
										}
										if (g3.id != Vgar[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);

							}
							if (subsubchoice == 3) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Showroom ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Delete Cars --------------------|" << endl;
									showshowrooms(Vshowroom);
									cout << "\n\t°Enter Showroom ID you want to Delete car from it :-> ";

									cin >> S.id;
									for (int i = 0; i < Vshowroom.size(); i++)
									{
										if (S.id == Vshowroom[i].id) {
											system("cls");
											S.posa = i;
											showcars(Vshowroom,S.posa);
											cout << "\n\t°Enter ID of Car you want to delete :-> ";

											string carid;
											cin >> carid;
											int num = stoi(carid);

											Vshowroom[S.posa].cars.erase(Vshowroom[S.posa].cars.begin() + (num - 1));

											cout << "\n\t° Car  is Deleted" << endl;
											writec(Vshowroom);
											writeshowrooms(Vshowroom);
											system("pause");
											rr = false;
											f = false;
											break;

										}
										if (S.id != Vshowroom[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);
							}
							if (subsubchoice == 4) {
								system("cls");
								bool rr = true;
								bool f = false;
								do {

									if (f == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Garages ID Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
									cout << "\n\t|-------------------- Delete Services --------------------|" << endl;
									showGarages(Vgar);
									cout << "\n\t°Enter Garages ID you want to Delete Services from it :-> ";
									cin >> g3.id;
									for (int i = 0; i < Vgar.size(); i++)
									{
										if (g3.id == Vgar[i].id) {
											system("cls");
											g3.posa = i;
											showservices(Vgar,g3.posa);
											cout << "\n\t°Enter ID of Service you want to delete :-> ";
											string servID;
											cin >> servID;
											int num = stoi(servID);


											Vgar[g3.posa].serv.erase(Vgar[g3.posa].serv.begin() + (num - 1));

											cout << "\n\t° Service  is Deleted" << endl;

											writeserv(Vgar);
											writegarages(Vgar);
											system("pause");
											rr = false;
											f = false;
											break;

										}
										if (S.id != Vshowroom[i].id) {
											rr = true;
											f = true;
										}

									}
								} while (rr);





							}
							if (subsubchoice == 0) {
								system("cls");
							}

						}

				} while (subchoice !=0);
			}

		}

		////////////////////////////////////////////////////////////////////////////////
		if (choice != 1 && choice != 2 && choice != 0) {
			cout << "\n\t° Invalid Choice \n\n";
			system("pause");

		}
		////////////////////////////////////////////////////////////////////////////////
	} while (choice != 0);

	system("cls");

	cout << "\n\n\n\n\n\t\t\t Thanks\n\n\n\t\t\tGood Bye\n\n\n\n\n\n";

}

void CustomerMenu() {
	int subchoice = 0;
	int out = 1;
	int ew = 1;
	do {
		system("cls");
		cout << "\n\t|-------------------- Hello Customer --------------------|" << endl;

		////////////////////--> Options <--////////////////////
		cout << "\n\t° Enter >-[1]-> to:-> Buy New Car         \n";
		cout << "\n\t° Enter >-[2]-> to:-> View Showrooms      \n";
		cout << "\n\t° Enter >-[3]-> to:-> View Garages        \n";
		cout << "\n\t° Enter >-[4]-> to:-> Historical Service  \n";
		cout << "\n\t° Enter >-[5]-> to:-> Reserve A Car       \n";
		cout << "\n\t° Enter >-[6]-> to:-> Search              \n";
		cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

		cout << "\n\n\n*********\n";

		cout << "\n\t° -> Your Choise is:-> ";
		cin >> subchoice;

		while (subchoice != 0 && subchoice != 1 && subchoice != 2 && subchoice != 3 && subchoice != 4 && subchoice != 5 && subchoice != 6) {
			cout << "\t\tInvalid ";

			cout << "\n\t° -> Your Choise is:-> ";
			cin >> subchoice; cout << endl;
		}

		{
			if (subchoice == 1) { //Buy New Car
				system("cls");
				bool cc = false;
				do {
					showshowrooms(Vshowroom);
					string ch;
					cout << "\n\t° Enter ID of Showroom To View Its Cars :-> ";
					cin >> ch;
					bool t = true;

					for (int i = 0; i < Vshowroom.size(); i++) {
						if (ch == Vshowroom[i].id) {
							system("cls");
							int loc = i;
							cout << "ShowRooms Details :" << "\n\n";
							cout << "ShowroomID  ---->  " << Vshowroom[loc].id << endl << "Showroom Name  ---->  " << Vshowroom[loc].name << endl << "Showroom Location  ---->  " << Vshowroom[loc].location << endl << "Showroom PhoneNumber  ---->  " << Vshowroom[loc].number << endl;
							cout << "\n";
							cout << "          |--------------------------------------------------------------| " << endl;
							cout << "          |                            CARS                              | " << endl;
							cout << "          |--------------------------------------------------------------| " << endl;
							cout << "\n";
							cout << "---------------------------------------------------------------------------------------------------" << endl;
							cout << "      CarID      " << "     Make  " << "          Model  " << "         Price     " << "       Year     " << "       Installment     " << "\t  " << "\t  " << endl;
							cout << "---------------------------------------------------------------------------------------------------" << endl;



							for (int j = 0; j < Vshowroom[loc].cars.size(); j++) {

								cout << "\t" << Vshowroom[loc].cars[j].id << " \t|" << Vshowroom[loc].cars[j].make << "\t\t |" << Vshowroom[loc].cars[j].model << "\t\t |" << Vshowroom[loc].cars[j].year << "\t\t |" << Vshowroom[loc].cars[j].price << "\t\t |" << Vshowroom[loc].cars[j].Installment << endl;

							}
							cout << "---------------------------------------------------------------------------------------------------" << endl;
							cout << "\n\t° Enter ID Of Car you Want To Buy :-> ";

							string idcar;
							cin >> idcar;


							for (int j = 0; j < Vshowroom[loc].cars.size(); j++) {

								if (idcar == Vshowroom[loc].cars[j].id)
								{
									// current date and time on the current system
									time_t now = time(0);

									// convert now to string form
									string date_time = ctime(&now);

									int num = Vb.size();
									int xx = ++num;
									stringstream ss;
									ss << xx;
									string k;
									ss >> k;
									int buypos = j;
									B.Customerid = naame;
									B.chosencar = Vshowroom[loc].cars[buypos].make;
									B.Date = date_time;
									B.Processid = k;
									B.price = Vshowroom[loc].cars[buypos].price;
									Vb.push_back(B);

									Vshowroom[loc].cars.erase(Vshowroom[loc].cars.begin() + buypos);
									writehistory(Vb);
									writec(Vshowroom);
									writeshowrooms(Vshowroom);
									cout << "\n\t° CAR BUY SUCCEDDED" << endl;

									system("pause");



								}
							}

							cout << "--------------------------------------------------------------------------------------------------------" << endl << endl << endl;
							t = true;
							cc = false;
							break;
						}
						else {
							t = false;
							cc = true;
						}

					}
					if (t == false) {
						cout << "\n\t ==> Showroom ID Not Exist, Try Again <== \n\n";
						system("pause");
						system("cls");

					}
				} while (cc == true);

				ew = 5;

			}

			if (subchoice == 2) { //View Showrooms
				system("cls");


				showall(Vshowroom);

				system("pause");
				ew = 5;
			}

			if (subchoice == 3) { //View Garages
				system("cls");
				showGaragesDetails(Vgar);
				system("pause");
				ew = 5;
			}

			if (subchoice == 4) {
				system("cls");
				cout << "\n\t|-------------------- Historical Service --------------------|" << endl;
				showbuy(Vb,naame);
				ew = 5;

			}

			if (subchoice == 5) { //Reserve Car
				system("cls");
				bool cc = false;
				do {
					showshowrooms(Vshowroom);
					string ch;
					cout << "\n\t° Enter ID of Showroom To View Its Cars :-> ";
					cin >> ch;
					bool t = true;

					for (int i = 0; i < Vshowroom.size(); i++) {
						if (ch == Vshowroom[i].id) {
							system("cls");
							int loc = i;
							position = loc;
							cout << "ShowRooms Details :" << "\n\n";
							cout << "ShowroomID  ---->  " << Vshowroom[loc].id << endl << "Showroom Name  ---->  " << Vshowroom[loc].name << endl << "Showroom Location  ---->  " << Vshowroom[loc].location << endl << "Showroom PhoneNumber  ---->  " << Vshowroom[loc].number << endl;
							cout << "\n";
							cout << "          |--------------------------------------------------------------| " << endl;
							cout << "          |                            CARS                              | " << endl;
							cout << "          |--------------------------------------------------------------| " << endl;
							cout << "\n";
							cout << "---------------------------------------------------------------------------------------------------" << endl;
							cout << "      CarID      " << "     Make  " << "          Model  " << "         Price     " << "       Year     " << "       Installment     " << "\t  " << "\t  " << endl;
							cout << "---------------------------------------------------------------------------------------------------" << endl;



							for (int j = 0; j < Vshowroom[loc].cars.size(); j++) {

								cout << "\t" << Vshowroom[loc].cars[j].id << " \t|" << Vshowroom[loc].cars[j].make << "\t\t |" << Vshowroom[loc].cars[j].model << "\t\t |" << Vshowroom[loc].cars[j].year << "\t\t |" << Vshowroom[loc].cars[j].price << "\t\t |" << Vshowroom[loc].cars[j].Installment << endl;

							}
							cout << "---------------------------------------------------------------------------------------------------" << endl;
							cout << "\n\t° Enter ID Of Car you Want To Reserve :-> ";

							string idcar;
							cin >> idcar;


							for (int j = 0; j < Vshowroom[loc].cars.size(); j++) {

								if (idcar == Vshowroom[loc].cars[j].id)
								{

									int buypos = j;
									Vtime.push_back(Vshowroom[loc].cars[buypos]);
									Vshowroom[loc].cars.erase(Vshowroom[loc].cars.begin() + buypos);

									writec(Vshowroom);
									writeshowrooms(Vshowroom);

									cout << "\n\t° Car Reservation Succedded" << endl;
									system("pause");



								}
							}

							cout << "--------------------------------------------------------------------------------------------------------" << endl << endl << endl;
							t = true;
							cc = false;
							break;
						}
						else {
							t = false;
							cc = true;
						}

					}
					if (t == false) {
						cout << "\n\t ==> Showroom ID Not Exist, Try Again <== \n\n";
						system("pause");
						system("cls");

					}
				} while (cc == true);

				ew = 5;


			}

			if (subchoice == 6) { //Search
				system("cls");
				int searchindex = 0;

				cout << "\n\t|-------------------- Search Menu --------------------|" << endl;
				cout << "\n\t° Enter >-[1]-> to:->  Search Showrooms\n";
				cout << "\n\t° Enter >-[2]-> to:->  Search Garages\n";
				cout << "\n\t° Enter >-[3]-> to:->  Search Cars\n";
				cout << "\n\t° Enter >-[4]-> to:->  Search Service\n";
				cout << "\n\t° Enter >-[0]-> to:->  Return Main-Menu\n\n";
				cout << "\n\n\n*********\n";

				cout << "\n\t° -> Your Choise is:-> ";
				cin >> searchindex;
				while (searchindex != 0 && searchindex != 1 && searchindex != 2 && searchindex != 3 && searchindex != 4) {
					cout << "\t\tInvalid ";
					cout << "\n\t° -> Your Choise is:-> ";
					cin >> searchindex; cout << endl;

				}
				if (searchindex == 1)
				{
					system("cls");
					cout << "\n\t|-------------------- Search Showrooms --------------------|" << endl;
					bool ee = true;
					bool f = false;
					do {

						system("cls");
						if (f == true) {
							cout << "---------------------------------------------------" << endl;
							cout << "\n\t°Showrooms ID Not Exist,Try Again" << endl << endl;
							cout << "---------------------------------------------------" << endl;
							system("pause");
						}
						system("cls");
						cout << "\n\t°Enter Showroom ID you want to Search : ";
						cin >> S.id;
						for (int i = 0; i < Vshowroom.size(); i++)
						{
							if (S.id != Vshowroom[i].id) {
								ee = true;
								f = true;
							}
							if (S.id == Vshowroom[i].id)
							{

								S.posa = i;
								cout << endl;
								cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
								cout << "      ShowroomID      " << "     Showroom Name  " << "          Showroom Location  " << "         Showroom PhoneNumber     " << endl;
								cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
								cout << "\t" << Vshowroom[S.posa].id << "\t\t| " << Vshowroom[S.posa].name << "\t\t| " << Vshowroom[S.posa].location << "\t\t| " << Vshowroom[S.posa].number << endl << endl;
								ee = false;
								f = false;
								system("pause");
								break;
							}




						}

					} while (ee);

				}
				if (searchindex == 2)
				{

					system("cls");
					cout << "\n\t|-------------------- Search Garages --------------------|" << endl;
					bool ee = true;
					bool f = false;
					do {

						system("cls");
						if (f == true) {
							cout << "---------------------------------------------------" << endl;
							cout << "\n\t°Garage ID Not Exist,Try Again" << endl << endl;
							cout << "---------------------------------------------------" << endl;
							system("pause");
						}
						system("cls");
						cout << "\n\t°Enter Garage ID you want to Search : ";
						cin >> g3.id;
						for (int i = 0; i < Vgar.size(); i++)
						{
							if (g3.id != Vgar[i].id) {
								ee = true;
								f = true;
							}
							if (g3.id == Vgar[i].id)
							{

								g3.posa = i;
								cout << endl;
								cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
								cout << "      GarageID      " << "     Garage Name  " << "          Garage Location  " << "         Garage PhoneNumber     " << endl;
								cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
								cout << "\t" << Vgar[g3.posa].id << "\t\t| " << Vgar[g3.posa].name << "\t\t| " << Vgar[g3.posa].location << "\t\t| " << Vgar[g3.posa].number << endl << endl;
								ee = false;
								f = false;
								system("pause");
								break;
							}




						}

					} while (ee);


				}
				if (searchindex == 3)
				{
					system("cls");
					bool rr = true;
					bool f = false;
					do {

						if (f == true) {
							system("cls");
							cout << "-------------------------------------------------------------" << endl;
							cout << "\n\t°Showroom ID Not Exist,Try Again" << endl << endl;
							cout << "-------------------------------------------------------------" << endl;
							system("pause");
							system("cls");
						}
						cout << "\n\t|-------------------- Search Cars --------------------|" << endl;
						showshowrooms(Vshowroom);
						cout << "\n\t°Enter Showroom ID you want to Search car from it :-> ";

						cin >> S.id;
						for (int i = 0; i < Vshowroom.size(); i++)
						{
							if (S.id == Vshowroom[i].id) {
								system("cls");
								S.posa = i;
								bool oo = true;
								bool r = false;
								do {

									cout << "\n\t°Enter Car Model you want to Search :-> ";

									string carname;
									cin >> carname;


									for (int j = 0; j < Vshowroom[S.posa].cars.size(); j++)
									{
										if (carname == Vshowroom[S.posa].cars[j].model) {

											int carpos = j;
											cout << "\n\n";
											cout << "-------------------------------------------------------------------------------------------------------" << endl;
											cout << "      CaID      " << "      Make  " << "           Model  " << "          Year     " << "         price     " << "          installmect     " << endl;
											cout << "-------------------------------------------------------------------------------------------------------" << endl;
											cout << "\t" << Vshowroom[S.posa].cars[carpos].id << " \t|" << Vshowroom[S.posa].cars[carpos].make << "\t\t |" << Vshowroom[S.posa].cars[carpos].model << "\t\t |" << Vshowroom[S.posa].cars[carpos].year << "\t\t |" << Vshowroom[S.posa].cars[carpos].price << "\t\t |" << Vshowroom[S.posa].cars[j].Installment << endl;
											cout << "--------------------------------------------------------------------------------------------------------" << endl << endl << endl;

											system("pause");
											oo = false;
											r = false;
											break;
										

										}
										if (carname != Vshowroom[S.posa].cars[j].make) {
											oo = true;
											r = true;
										}

									}
									if (r == true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Car Make Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
								} while (oo);
								rr = false;
								f = false;
								break;
							}
							if (S.id != Vshowroom[i].id) {
								rr = true;
								f = true;
							}

						}

					} while (rr);




				}
				if (searchindex == 4)
				{
					system("cls");
					bool rr = true;
					bool f = false;
					do {

						if (f == true) {
							system("cls");
							cout << "-------------------------------------------------------------" << endl;
							cout << "\n\t°Garage ID Not Exist,Try Again" << endl << endl;
							cout << "-------------------------------------------------------------" << endl;
							system("pause");
							system("cls");
						}
						cout << "\n\t|-------------------- Search Service --------------------|" << endl;
						showGarages(Vgar);
						cout << "\n\t°Enter Gargae ID you want to Search Service from it :-> ";

						cin >> g3.id;
						for (int i = 0; i < Vgar.size(); i++)
						{
							if (g3.id == Vgar[i].id) {
								system("cls");
								g3.posa = i;
								bool oo = true;
								bool r = false;
								do {

									cout << "\n\t°Enter Service Name you want to Search :-> ";

									string servname;
									cin >> servname;


									for (int j = 0; j < Vgar[g3.posa].serv.size(); j++)
									{
										if (servname == Vgar[g3.posa].serv[j].name) {

											int servpos = j;
											cout << "\n\n";
											cout << "----------------------------------------------------------------------------------" << endl;
											cout << "      Service ID      " << "      Service Name  " << "           Service Price  " << endl;
											cout << "---------------------------------------------------------------------------------" << endl;
											cout << "\t" << Vgar[g3.posa].serv[servpos].id << " \t|" << Vgar[g3.posa].serv[servpos].name << "\t\t |" << Vgar[g3.posa].serv[servpos].price << endl;
											cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;

											system("pause");
											oo = false;
											r = false;
											break;

										}
										if (servname != Vgar[g3.posa].serv[j].name) {
											oo = true;
											r = true;
										}

									}
									if (r = true) {
										system("cls");
										cout << "-------------------------------------------------------------" << endl;
										cout << "\n\t°Service Name Not Exist,Try Again" << endl << endl;
										cout << "-------------------------------------------------------------" << endl;
										system("pause");
										system("cls");
									}
								} while (oo);
								rr = false;
								f = false;
								break;
							}
							if (g3.id != Vgar[i].id) {
								rr = true;
								f = true;
							}

						}

					} while (rr);



				}

				if (searchindex == 0)
				{
					system("cls");
					ew = 5;
				}



			}


			if (subchoice == 0) {
				ew = 1;
				system("cls");
				if (Vtime.size() != 0) {
					cout << "---------------------------------------------------------------------------------------------------" << endl;
					cout << "\n\t° Do You Want To Buy Your Researved Car :-> \n";

					cout << "\n\t Enter Y --------> For Buy";
					cout << "\n\t Enter N --------> For Not";

					string ch1;
					cin >> ch1;
					if (ch1 == "Y" || ch1 == "y") {
						for (int i = 0; i < Vtime.size(); i++) {
							// current date and time on the current system
							time_t now = time(0);

							// convert now to string form
							string date_time = ctime(&now);

							int num = Vb.size();
							int xx = ++num;
							stringstream ss;
							ss << xx;
							string k;
							ss >> k;
							B.Customerid = naame;
							B.chosencar = Vtime[i].make;
							B.Date = date_time;
							B.Processid = k;
							B.price = Vtime[i].price;
							Vb.push_back(B);
							writehistory(Vb);
							cout << "\n\t° RESRVED CAR BUY SUCCEDDED" << endl;
							system("pause");
							Vtime.erase(Vtime.begin());
						}
					}
					if (ch1 == "N" || ch1 == "n") {
						Vshowroom[position].cars.push_back(Vtime[0]);
						Vtime.erase(Vtime.begin());
						writec(Vshowroom);
						writeshowrooms(Vshowroom);
					}
					ew = 1;

				}

				if (Vtime.size() != 0) {
					ew = 1;
				}

			}
		}
	} while (ew == 5);
}
