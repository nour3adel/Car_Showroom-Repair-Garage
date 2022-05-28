#include "Show.h"

void showall(vector<Showroom>& showroom) {
	bool cc = false;
	do {
		showshowrooms(showroom);
		string ch;
		cout << "\n\t° Enter ID of Showroom To View Its Cars :-> ";
		cin >> ch;
		bool t = true;

		for (int i = 0; i < showroom.size(); i++) {
			if (ch == showroom[i].id) {
				system("cls");
				int loc = i;
				cout << "ShowRooms Details :" << "\n\n";
				cout << "ShowroomID  ---->  " << showroom[loc].id << endl << "Showroom Name  ---->  " << showroom[loc].name << endl << "Showroom Location  ---->  " << showroom[loc].location << endl << "Showroom PhoneNumber  ---->  " << showroom[loc].number << endl;
				cout << "\n";
				cout << "          |--------------------------------------------------------------| " << endl;
				cout << "          |                            CARS                              | " << endl;
				cout << "          |--------------------------------------------------------------| " << endl;
				cout << "\n";
				cout << "---------------------------------------------------------------------------------------------------" << endl;
				cout << "      CarID      " << "     Make  " << "          Model  " << "         Price     " << "       Year     " << "       Installment     " << "\t  " << "\t  " << endl;
				cout << "---------------------------------------------------------------------------------------------------" << endl;



				for (int j = 0; j < showroom[loc].cars.size(); j++) {

					cout << "\t" << showroom[loc].cars[j].id << " \t|" << showroom[loc].cars[j].make << "\t\t |" << showroom[loc].cars[j].model << "\t\t |" << showroom[loc].cars[j].year << "\t\t |" << showroom[loc].cars[j].price << "\t\t |" << showroom[loc].cars[j].Installment << endl;

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
}

void showshowrooms(vector<Showroom>& showroom) {
	system("cls");
	cout << "\n";
	cout << "          |--------------------------------------------------------------| " << endl;
	cout << "          |                            Showrooms                         | " << endl;
	cout << "          |--------------------------------------------------------------| " << endl;
	cout << "\n";
	cout << "      ShowroomID      " << "     Showroom Name  " << "          Showroom Location  " << "         Showroom PhoneNumber     " << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < showroom.size(); i++) {

		cout << "\t" << showroom[i].id << " \t\t    |" << showroom[i].name << "\t\t |" << showroom[i].location << "\t\t |" << showroom[i].number << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

void showcars(vector<Showroom>& showroom, int id) {
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "      CaID      " << "      Make  " << "           Model  " << "          Year     " << "         price     " << "          installmect     " << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;


	for (int j = 0; j < showroom[id].cars.size(); j++) {

		cout << "\t" << showroom[id].cars[j].id << " \t|" << showroom[id].cars[j].make << "\t\t |" << showroom[id].cars[j].model << "\t\t |" << showroom[id].cars[j].year << "\t\t |" << showroom[id].cars[j].price << "\t\t |" << showroom[id].cars[j].Installment << endl;

	}
	cout << "--------------------------------------------------------------------------------------------------------" << endl << endl << endl;

}

void showGarages(vector<Garages>& gar) {
	system("cls");
	cout << "\n";
	cout << "          |--------------------------------------------------------------| " << endl;
	cout << "          |                            Garages                           | " << endl;
	cout << "          |--------------------------------------------------------------| " << endl;
	cout << "\n";
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "      GarageID      " << "     Garage Name  " << "          Garage Location  " << "         Garage PhoneNumber     " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < gar.size(); i++) {

		cout << "\t" << gar[i].id << " \t\t    |" << gar[i].name << "\t\t |" << gar[i].location << "\t\t |" << gar[i].number << endl;
	}
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
}

void showservices(vector<Garages>& gar, int id) {
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "      Service ID      " << "      Service Name  " << "           Service Price  " << endl;
	cout << "---------------------------------------------------------------------------------" << endl;

	for (int j = 0; j < gar[id].serv.size(); j++) {

		cout << "\t" << gar[id].serv[j].id << " \t\t|" << gar[id].serv[j].name << "\t\t |" << gar[id].serv[j].price << endl;

	}
	cout << "----------------------------------------------------------------------------------------" << endl << endl << endl;

}

void showbuy(vector<BuyProcess>& Vb, string naame) {

	system("cls");
	cout << "\n";
	cout << "          |--------------------------------------------------------------| " << endl;
	cout << "          |                       Historical Service                     | " << endl;
	cout << "          |--------------------------------------------------------------| " << endl;
	cout << "\n\n";


	for (int j = 0; j < Vb.size(); j++) {
		if (naame == Vb[j].Customerid) {
			cout << "\n   ° PROCESS-ID :-> " << Vb[j].Processid << "\n\n   ° CUSTOMER ID :-> " << Vb[j].Customerid << "\n\n   ° CHOSEN CAR :-> " << Vb[j].chosencar <<" "<< Vb[j].model << "\n\n   ° CAR PRICE :-> " << Vb[j].price << "\n\n   ° DATE :-> " << Vb[j].Date << endl;

			cout << "----------------------------------------------------------------------------------------" << endl << endl << endl;
		}
	}

	system("pause");

}

void showGaragesDetails(vector<Garages>& gar) {
	bool cc = false;
	do {
		showGarages(gar);
		string ch;
		cout << "\n\t° Enter ID of Garage To View Its Service :-> ";
		cin >> ch;
		bool t = true;
		for (int i = 0; i < gar.size(); i++) {
			if (ch == gar[i].id) {
				system("cls");
				int loc = i;
				cout << "Garage Details :" << "\n\n";
				cout << "GarageID  ---->  " << gar[loc].id << endl << "Garage Name  ---->  " << gar[loc].name << endl << "Garage Location  ---->  " << gar[loc].location << endl << "Garage PhoneNumber  ---->  " << gar[loc].number << endl;
				cout << "\n";
				cout << "          |--------------------------------------------------------------| " << endl;
				cout << "          |                            Services                          | " << endl;
				cout << "          |--------------------------------------------------------------| " << endl;
				cout << "\n";
				cout << "--------------------------------------------------------------------------" << endl;
				cout << "      Service ID      " << "      Service Name  " << "           Service Price  " << endl;
				cout << "------------------------------------------------------------------------" << endl;



				for (int j = 0; j < gar[loc].serv.size(); j++) {

					cout << "\t" << gar[loc].serv[j].id << " \t\t|" << gar[loc].serv[j].name << "\t\t |" << gar[loc].serv[j].price << endl;

				}
				cout << "--------------------------------------------------------------------------" << endl << endl << endl;
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
			cout << "\n\t ==> Garage ID Not Exist, Try Again <== \n\n";
			system("pause");
			system("cls");

		}
	} while (cc == true);

}