#include <iostream>
#include "Vehicle.h"
#include <string>
#include "Tire.h"
#include "Engine.h"

using namespace std;
using std::string;

ostream& operator<<(ostream& os, const Vehicle& V)
{
	V.show();
	os << "";
	return os;
}

bool Vehicle::operator==(const Vehicle& others) const
{
	bool result;
	if ((this->m_Company == others.get_company()) &&
		(this->m_Model == others.get_model()) &&
		(this->m_Color == others.get_color()) &&
		(this->popularity == others.get_popularity()) &&
		(this->m_Tires[0] == (others.get_Tires())[0]) &&
		(this->m_Engine == others.get_Engine()) &&
		(this->m_left_in_stock == others.get_left_stock()) &&
		(this->m_price == others.get_price()) &&
		(this->m_tax_dealership == others.get_tax_dealership()) &&
		(this->m_tax_import == others.get_tax_import()))
		result = true;
	else
		result = false;

		return result;
}


Vehicle::Vehicle(string Comp, string M, string C, Tire* T, Engine E_V, unsigned long price) // Constructor
{
	//m_License_Plate = LP;
	m_Company = Comp;
	m_Model = M;
	m_Color = C;
	m_Engine = E_V;
	//this->set_num_tires(num_t);
	m_price = price;
	try
	{
		m_Tires = new Tire[m_num_tires];
		for (int i = 0; i < m_num_tires; i++)
			m_Tires[i] = T[i];
	}
	catch (const std::exception&)
	{
		std::cout << "Error occured: add tires to vehicle";
		throw;
	}
}

Vehicle::Vehicle(const  Vehicle& other) // copy Constructor
{
	m_Company = other.get_company();
	m_Model = other.get_model();
	m_Color = other.get_color();
	m_Engine = other.get_Engine();	
	m_left_in_stock = other.get_left_stock();
	m_price = other.get_price();
	m_tax_dealership = other.get_tax_dealership();
	m_tax_import = other.get_tax_import();
	popularity = other.popularity;

	try
	{
		m_Tires = new Tire[m_num_tires];
		for (int i = 0; i < m_num_tires; i++)
			m_Tires[i] = other.m_Tires[i];
	}
	catch (const std::exception&)
	{
		std::cout << "Error occured: add tires to vehicle";
		throw;
	}
}

Vehicle::Vehicle()// default Constructor
{
	m_Company = '0';
	m_Model = '0';
	m_Color = '0';
	m_Tires = new Tire[m_num_tires];
	m_Engine.set_Engine_Type("00");
	m_Engine.set_Engine_Horsepower(0);
	m_Engine.set_Valve_num(0);
	m_Engine.set_Engine_Capacity(0);
	m_tax_dealership = 0;
	m_tax_import = 0; 
	m_price = 0;
	m_left_in_stock=0;
	popularity = 0;
}


void Vehicle::show_v(void) const
{
	cout <<  endl
		<< "Company: " << m_Company << endl
		<< "Model: " << m_Model << endl
		<< "Color: " << m_Color << endl
		<< "Popularity: " << popularity << endl
		<<"Left in stock: "<<m_left_in_stock<<endl
		<< "number of Tires: " << m_num_tires << endl
		<<endl<< "Engine:" << endl;
	m_Engine.show();
	cout <<endl<< "x"<< m_num_tires<<" Tires:" << endl;
	m_Tires[0].show();
	cout <<endl<< "Price: " << m_price << endl
		<< "tax dealership: " << m_tax_dealership << endl
		<< "tax  import: " << m_tax_import << endl;
}

string Vehicle::get_company() const// return the company 
{
	return m_Company;
}

string Vehicle::get_model() const // return the model
{
	return  m_Model;
}

string Vehicle::get_color() const// return the color
{
	return  m_Color;
}

Tire* Vehicle::get_Tires() const //return the array of tires
{
	return m_Tires;
}

Engine Vehicle::get_Engine() const //return the engine of vehicle
{
	return m_Engine;
}

unsigned long  Vehicle::get_price()const //return the price of Vehicle 
{
	return m_price;
}

double Vehicle ::get_tax_import()const 
{
	return m_tax_import;
}

unsigned int Vehicle::get_tax_dealership() const 
{
	return m_tax_dealership;
}

int Vehicle::get_left_stock() const
{
	return m_left_in_stock;
}
int Vehicle::get_popularity() const
{
	return popularity;

}


void Vehicle::set_company(string Comp) // set the company
{

	m_Company = Comp;
}

void Vehicle::set_model(string M) // set the model 
{

	m_Model = M;
}

void Vehicle::set_color(string C) // set the color 
{

	m_Color = C;
}

void Vehicle::set_Tires(Tire* T) //set the array of tires
{

	if (m_Tires)
	{
		for (int i = 0; i < m_num_tires; i++)
			m_Tires[i].~Tire();
	}
	try
	{
		m_Tires = new Tire[m_num_tires];
		for (int i = 0; i < m_num_tires; i++)
			m_Tires[i] = T[i];
	}
	catch (const std::exception&)
	{
		std::cout << "Error occured: add tires to vehicle";
		throw;
	}
}

void Vehicle::set_Engine(Engine E_V) //set the engine of vehicle
{
	m_Engine = E_V;
}
void  Vehicle::set_price( unsigned long  price) 
{
	m_price = price;
}


Vehicle::~Vehicle()	// destructor
{
	for (int i = 0; i < m_num_tires; i++)
		m_Tires[i].~Tire();
	//delete[] m_Tires;
	//m_num_tires = 0;
	m_Engine.~Engine();
}


void Vehicle::set_tax_import(double import_tax)
{
	m_tax_import = import_tax;
}
void Vehicle::set_tax_dealership(int  tax_dealership)
{
	m_tax_dealership = tax_dealership;
}
void Vehicle::set_left_stock(int new_left)
{
	m_left_in_stock = new_left;
}

void Vehicle::set_popularity(int new_pop)
{
	popularity = new_pop;
}

void Vehicle::add_vehicle()//add new vehicle by user
{
	Engine E;
	Tire T;
	string name;
	int number;

	cout << "please enter company's name:" << endl;
	name = this->enter_string();
	this->set_company(name);

	cout << "please enter vehicle's model:" << endl;
	name = this->enter_string();
	this->set_model(name);

	cout << "please enter vehicle's color:" << endl;
	name = this->enter_string();
	this->set_color(name);

	cout << "please enter vehicle's starting price:" << endl;
	number = this->enter_number();
	this->set_price(number);

	cout << "please enter vehicle's stock:" << endl;
	number = this->enter_number();
	this->set_left_stock(number);

	cout << "please enter vehicle's engine details:" << endl;
	cout << "please enter Engine Type:" << endl;
	name = this->enter_string();
	E.set_Engine_Type(name);

	cout << "please enter Engine Horsepower:" << endl;
	number = this->enter_number();
	E.set_Engine_Horsepower(number);

	cout << "please enter Engine's number of Valves:" << endl;
	number = this->enter_number();
	E.set_Valve_num(number);

	cout << "please enter Engine's Capacity:" << endl;
	number = this->enter_number();
	E.set_Engine_Capacity(number);

	cout << "please enter vehicle's Tires details:" << endl;

	cout << "please enter Tires brand:" << endl;
	name = this->enter_string();
	T.set_Brand(name);

	cout << "please enter Tires Tread Width :" << endl;
	number = this->enter_number();
	T.set_Width(number);

	cout << "please enter Tires Diameter:" << endl;
	number = this->enter_number();
	T.set_Diameter(number);

	Tire* arr_tires = new Tire[m_num_tires];
	for (int i = 0; i < m_num_tires; i++)
		arr_tires[i] = T;

	this->set_Engine(E);
	this->set_Tires(arr_tires);
}


int Vehicle::enter_number() const
{
	int out;
	cin >> out;
	getchar();
	return out;
}

string Vehicle::enter_string() const
{
	string s;
	getline(cin, s);
	return s;
}

void Vehicle::serialize_v(fstream& file) const
{
	file << m_Company << " " << m_Model << " " <<m_left_in_stock<<" "<<popularity << " " <<
		m_Color << " " << m_price << " " << m_tax_dealership << " " << m_tax_import << " " << m_num_tires << endl;
	m_Engine.serialize(file);
	for (int i = 0; i < m_num_tires; i++) {
		m_Tires[i].serialize(file);
	}

}

void Vehicle::deserialize_v(fstream& file)
{
	string str;
	file >> str;
	m_Company = str;
	file >> str;
	m_Model = str;
	file >> str;
	m_left_in_stock = convert_str_to_num(str);
	file >> str;
	popularity = convert_str_to_num(str);
	file >> str;
	m_Color = str;
	file >> str;
	m_price = convert_str_to_num(str);
	file >> str;
	m_tax_dealership = convert_str_to_num(str);
	file >> str;
	m_tax_import = stod(str);
	file >> str;

	m_Engine.deserialize(file);
	 Tire *T= new Tire[m_num_tires];
	for (int i = 0; i < m_num_tires; i++) 
	{
		T[i].deserialize(file);
	}
	m_Tires = T;
}


int Vehicle::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}