#ifndef _CUSTOMER_H
#define CUSTOMER_H
#include "Vehicle.h"
#include <string>
#include <ostream>
using namespace std;

class Customer
{
private :
 string m_private_name;
 string m_last_name;
 unsigned int m_id;
 unsigned m_cell_number; 
 Vehicle* m_sold_car;
 int m_car_stock_index;
 string car_type;

public:
	Customer(string  private_name,string  last_name, int id, int cell_num);
	Customer(const Customer&);
	Customer();
	~Customer();

	string get_private_name()const;
	string get_last_name()const;
	int get_id()const;
	int get_car_stock_index()const;
	int get_cell_num() const;
	Vehicle* get_vehicle() const;
//	void serialize(); 
	//static void deserialize(Customer & C);

	void set_car_type(string);
	void set_private_name(string name);
	void set_last_name(string name);
	void set_id(int id);
	void set_cell_num(int cell_num);
	void set_Vehicle(Vehicle* v, int index);
	void show(void) const;				//print customer 
	friend ostream& operator<<(ostream& os, const Customer& C);	// print Customer 

	void serialize(fstream& file) const;
	void deserialize(fstream& file);


	int convert_str_to_num(string str) const;


};

#endif
