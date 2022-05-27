#pragma once
#include <iostream>
#include <vector>

////import classes 
#include "Showroom.h"
#include "BuyProcess.h"
#include "Garages.h"


void showall(vector<Showroom>& showroom);

void showshowrooms(vector<Showroom>& showroom);

void showcars(vector<Showroom>& showroom, int id);

void showGarages(vector<Garages>& vg);

void showservices(vector<Garages>& vg, int id);

void showbuy(vector<BuyProcess>& Vb, string naame);

void showGaragesDetails(vector<Garages>& gar);