#include "Customer.h"
#include "Vehicle.h"
#include "Pickup_Truck.h"
#include "Sports_car.h"
#include <string>
#include <iostream>
using namespace std;


Customer::Customer(string  private_name, string  last_name, int id, int cell_num)
{
	m_private_name = private_name;
	m_last_name = last_name;
	m_id = id;
	m_cell_number = cell_num;
}
Customer::Customer(const Customer& other)
{
	m_private_name = other.get_private_name();
	m_last_name = other.get_last_name();
	m_id = other.get_id();
	m_cell_number = other.get_cell_num();
	m_sold_car = other.get_vehicle();
	m_car_stock_index = other.get_car_stock_index();
}

Customer::~Customer()
{
}
Customer::Customer()
{
	m_private_name = " ";
	m_last_name = " ";
	m_id = 0;
	m_cell_number = 0;
	car_type = " ";

}
string Customer::get_private_name()const
{
	return m_private_name;
}
string Customer::get_last_name()const
{
	return m_last_name;
}
int Customer::get_id()const
{

	return m_id;
}

int Customer::get_car_stock_index() const
{
	return m_car_stock_index;
}

int Customer::get_cell_num() const
{

	return m_cell_number;
}

void Customer::set_private_name(string name)
{
	m_private_name = name;
}

void Customer::set_last_name(string name)
{
	m_last_name = name;
}


void Customer::set_id(int id)
{
	m_id = id;
}
void  Customer::set_cell_num(int cell_num)
{
	m_cell_number = cell_num;
}
Vehicle* Customer::get_vehicle() const
{
	return m_sold_car;
}

void Customer::set_Vehicle(Vehicle* v, int index)
{
	m_sold_car = v;
	m_car_stock_index = index;
}

void Customer::set_car_type(string type)
{
	car_type = type;
}

void Customer::show() const//print customer 
{
	cout << " Customer:" << endl
		<< "private name:" << m_private_name << endl
		<< "last name:" << m_last_name << endl
		<< "id:" << m_id << endl
		<< "cell number:" << m_cell_number << endl << endl
		<< "sold car:" << endl;
	(*m_sold_car).show_obj();
}
ostream& operator<<(ostream& os, const Customer& C)// print Customer 
{
	os << " ";
	C.show();
	return os;
}

void Customer::serialize(fstream& file) const
{
	file << m_private_name << " " << m_last_name << " " << m_id << " " << m_cell_number << " " << m_car_stock_index << endl;
}

void Customer::deserialize(fstream& file)
{
	string str;
	file >> str;
	m_private_name = str;
	file >> str;
	m_last_name = str;
	file >> str;
	m_id = convert_str_to_num(str);
	file >> str;
	m_cell_number = convert_str_to_num(str);
	file >> str;
	m_car_stock_index = convert_str_to_num(str);
}


int Customer::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}

