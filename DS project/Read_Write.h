#pragma once
#include <iostream>
#include <vector>

////import classes 
#include "Showroom.h"
#include "BuyProcess.h"
#include "Garages.h"


//showroom
void writeshowrooms(vector<Showroom>& showroom_vec);
void readshowrooms(vector<Showroom>& showroom_vec);

//cars
void writecars(vector<car>& car_vec, string a);
void readcars(vector<car>& car_vec, string v);

//make cars in showrooms
void writec(vector<Showroom>& show_vec);
void reader(vector<Showroom>& show_vec);

//history
void readhistory(vector<BuyProcess>& buy_vec);
void writehistory(vector<BuyProcess>& buy_vec);

// garage
void readgarages(vector<Garages>& garages_vec);
void writegarages(vector<Garages>& garages_vec);

//service
void readservice(vector<service>& service_vec, string v);
void writeservice(vector<service>& service_vec, string a);

// service in garage
void readserv(vector<Garages>& Garage_vec);
void writeserv(vector<Garages>& garage_vec);


