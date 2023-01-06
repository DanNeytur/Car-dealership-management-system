#ifndef DEALERSHIP_SYSTEM_H
#define DEALERSHIP_SYSTEM_H
#include <string>
#include <ostream>
#include <vector>
#include <algorithm>
#include "Customer.h"
#include "Tire.h"
#include "Engine.h"
#include "Vehicle.h"
#include "Sports_car.h"
#include "Pickup_Truck.h"
using namespace std;
using std::string;

template<class T>
void show_sel_vect(const vector<T>& p)
{ 
	int cnt = 1;
	if (p.size() == 0)
	{
		cout << "this stock is empty!" << endl << endl;
		return;
	}

	for (int i=0; i< p.size(); i++, cnt++) 
	{
		cout << "---------------------------------------------------" << endl;
		cout <<cnt<< p[i] << " ";
	}
	cout << endl;
}

class Dealership_system
{
private:
	Customer new_customer; 
	string selected_stock;
	bool system_running; //'1' while system is on

	int cnt_temp;/////////////////temporary

	unsigned int  m_tax_dealership_pickup;	// tax of the pickup sale 
	double m_tax_import_pickup;				// tax of the pickup import 
	unsigned int  m_tax_dealership_sports; // tax of the pickup sale 
	double m_tax_import_sports;				// tax of the pickup import
	unsigned  m_tax_roof;					// tax of Convertible roof

	string stocks[6] = { "sports_stock","sports_net","sports_sold","pickup_stock","pickup_net","pickup_sold" };  
	vector <Sports_Car>    m_Sports_stock; //array for the sports cars in dealership stock
	vector <Customer>      m_Sports_sold;//array for sports cars that we sold
	vector <Pickup_Truck>  m_Pickup_stock; //array for the Pickup Truck  in dealership stock
	vector <Customer >     m_Pickup_sold;//array for Pickup Truck that we sold

public:
	Dealership_system(); //constructor 
	~Dealership_system();//destructor
	void show_vect()const;//print selected vector

	void show_by_popularity();

	void show_menu();//show system's options

	void add_customer();
	void pick_a_car();
	void start();

	int enter_number() const;
	string enter_string() const;
	int convert_str_to_num(string str) const;
	int select_index() const;

	void select_stock();//select a stock
	void select_sold();//shows the diffrent sold options
	void changes();//change the selected vector

	void add_car();//add new car
	void remove_car();//remove a car from stock

	void change_taxes();//change the taxes 

	void set_tax_dealership_pickup(int);	//set  tax of the pickup sale 
	void set_tax_import_pickup(int);			// set tax of the pickup import 
	void set_tax_dealership_sports(int); // set tax of the pickup sale 
	void set_tax_import_sports(int);	//set tax of the pickup import 
	void set_tax_roof(int);					// tax of Convertible roof

	void serialize(); 
	void deserialize();

};
#endif