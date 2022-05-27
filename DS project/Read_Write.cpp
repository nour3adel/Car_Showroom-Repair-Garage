#include <iostream>
#include <string>
#include <vector>
#include<fstream>

#include "Read_Write.h"

//showroom
void readshowrooms(vector<Showroom>& showroom_vec) {
	// read showroom
	ifstream shows;
	Showroom S;
	shows.open("SHOWROOMS.txt", ios::out);
	while (!shows.eof()) {
		getline(shows, S.id);
		getline(shows, S.name);
		getline(shows, S.location);
		getline(shows, S.number);
		showroom_vec.push_back(S);
	}
	shows.close();
}
void writeshowrooms(vector<Showroom>& showroom_vec) {
	// write showroom
	ofstream shows;
	shows.open("SHOWROOMS.txt");
	if (!shows.is_open())
		cout << "couldn't open the file";
	else {
		for (int i = 0; i < showroom_vec.size(); i++) {
			shows << showroom_vec[i].id << "\n";
			shows << showroom_vec[i].name << "\n";
			shows << showroom_vec[i].location << "\n";
			shows << showroom_vec[i].number << "\n";
		}
		shows.close();
	}
}

//cars
void readcars(vector<car>& car_vec, string v) {
	// read cars
	ifstream cars;
	string dir = "Show " + v + ".txt";
	cars.open(dir);
	car c;
	while (!cars.eof()) {

		getline(cars, c.id);
		getline(cars, c.make);
		getline(cars, c.model);
		getline(cars, c.year);
		getline(cars, c.price);
		getline(cars, c.Installment);

		car_vec.push_back(c);
	}
	cars.close();
}
void writecars(vector<car>& car_vec, string a) {
	// write car
	string dic;
	dic = "Show " + a + ".txt";
	ofstream cars;
	cars.open(dic);

	if (!cars.is_open())
		cout << "couldn't open the file";
	else {
		for (int i = 0; i < car_vec.size(); i++) {
			cars << car_vec[i].id << "\n";
			cars << car_vec[i].make << "\n";
			cars << car_vec[i].model << "\n";
			cars << car_vec[i].year << "\n";
			cars << car_vec[i].price << "\n";
			cars << car_vec[i].Installment << "\n";

		}
		cars.close();
	}
}

//cars in showrooms
void writec(vector<Showroom>& show_vec) {
	for (int i = 0; i < show_vec.size(); i++)
	{
		writecars(show_vec[i].cars, show_vec[i].id);
	}
}
void reader(vector<Showroom>& show_vec) {
	for (int i = 0; i < show_vec.size(); i++)
	{
		readcars(show_vec[i].cars, show_vec[i].id);
	}
}

//history
void readhistory(vector<BuyProcess>& buy_vec) {
	// read history
	ifstream shows;
	BuyProcess B;
	shows.open("BuyHistory.txt", ios::out);
	while (!shows.eof()) {
		getline(shows, B.Processid);
		getline(shows, B.Customerid);
		getline(shows, B.Date);
		getline(shows, B.chosencar);
		getline(shows, B.price);

		buy_vec.push_back(B);
	}
	shows.close();
}
void writehistory(vector<BuyProcess>& buy_vec) {
	// write history
	ofstream shows;
	shows.open("BuyHistory.txt");
	if (!shows.is_open())
		cout << "couldn't open the file";
	else {
		for (int i = 0; i < buy_vec.size(); i++)
		{
			shows << buy_vec[i].Processid << "\n";
			shows << buy_vec[i].Customerid << "\n";
			shows << buy_vec[i].Date << "\n";
			shows << buy_vec[i].chosencar << "\n";
			shows << buy_vec[i].price << "\n";
		}
		shows.close();
	}
}

// garage
void readgarages(vector<Garages>& garages_vec) {
	// read garage
	ifstream shows;
	Garages gar;
	shows.open("GARAGES.txt", ios::out);
	while (!shows.eof()) {
		getline(shows, gar.id);
		getline(shows, gar.name);
		getline(shows, gar.location);
		getline(shows, gar.number);

		garages_vec.push_back(gar);
	}
	shows.close();
}
void writegarages(vector<Garages>& garages_vec) {
	// write garage
	ofstream shows;
	shows.open("GARAGES.txt");
	if (!shows.is_open())
		cout << "couldn't open the file";
	else {
		for (int i = 0; i < garages_vec.size(); i++)
		{
			shows << garages_vec[i].id << "\n";
			shows << garages_vec[i].name << "\n";
			shows << garages_vec[i].location << "\n";
			shows << garages_vec[i].number << "\n";
		}
		shows.close();
	}
}

// service
void readservice(vector<service>& service_vec, string v) {
	// read service
	ifstream serv;
	string dir = "Garage " + v + ".txt";
	serv.open(dir);
	service gar;
	while (!serv.eof()) {
		getline(serv, gar.id);
		getline(serv, gar.name);
		getline(serv, gar.price);

		service_vec.push_back(gar);
	}
	serv.close();

}
void writeservice(vector<service>& service_vec, string a) {
	// write car
	string dic;
	dic = "Garage " + a + ".txt";
	ofstream service;
	service.open(dic);
	if (!service.is_open())
		cout << "couldn't open the file";
	else {
		for (int i = 0; i < service_vec.size(); i++)
		{
			service << service_vec[i].id << "\n";
			service << service_vec[i].name << "\n";
			service << service_vec[i].price << "\n";
		}
		service.close();
	}
}

// service in garage
void readserv(vector<Garages>& Garage_vec) {
	for (int i = 0; i < Garage_vec.size(); i++)
	{
		readservice(Garage_vec[i].serv, Garage_vec[i].id);
	}
}
void writeserv(vector<Garages>& garage_vec) {
	for (int i = 0; i < garage_vec.size(); i++)
	{
		writeservice(garage_vec[i].serv, garage_vec[i].id);
	}
}