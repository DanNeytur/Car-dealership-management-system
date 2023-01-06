#include <iostream>
#include "Sports_Car.h"
#include <string>
#include "Vehicle.h"

using namespace std;

unsigned Sports_Car::m_door_num = 2;
unsigned Sports_Car::m_seat_num = 2;
//unsigned Sports_Car::m_tax_roof =10000;

Sports_Car::Sports_Car(/*unsigned int LP, */string Comp, string M, string C, Tire* T/*, unsigned int num_t*/, Engine E_V,unsigned long price,bool CR) :Vehicle(/*LP, */Comp, M, C, T/*, num_t*/, E_V , price) // Constructor
{
	m_Convertible_Roof = CR;
	//set_tax_import(0.1);
	//set_tax_dealership(10000);
	
}

Sports_Car::Sports_Car(const Sports_Car& other) :Vehicle(other) // copy Constructor
{
	m_Convertible_Roof = other.get_Convertible_Roof();
	m_tax_roof = other.get_tax_roof();
	//set_tax_import(other.get_tax_import());
	//set_tax_dealership(other.get_tax_dealership());
}

Sports_Car::Sports_Car() // default Constructor
{
	m_Convertible_Roof = 0;
	//this->set_tax_dealership(10000);
	//this->set_tax_import(0.1);
	//this->set_tax_roof(10000);
}

Sports_Car::~Sports_Car() // destructor
{
}

void Sports_Car::show_obj(void) const
{
	cout << " Sports Car:" << endl<<endl;
	show_v();
	cout << "Convertible Roof:" << m_Convertible_Roof << '\n'
		<< "number of seats:" << m_seat_num << '\n'
		<< "number of doors:" << m_door_num << '\n'
		<< " tax of roof :" << m_tax_roof << '\n'
	<< "final price sports car:       " << this->final_price() << endl;
}

unsigned  Sports_Car::get_tax_roof() const 
{
	return m_tax_roof;
}
unsigned Sports_Car::get_door_num() const // return the number of doors
{
	return m_door_num;
}
unsigned Sports_Car::get_seat_num() const // return the number of seats
{
	return m_seat_num;
}
bool Sports_Car::get_Convertible_Roof() const // return Convertible roof flag
{
	return m_Convertible_Roof;
}


void Sports_Car::set_Convertible_Roof(bool CR) // set the return Convertible roof flag
{
	m_Convertible_Roof = CR;
}

  double Sports_Car::final_price() const// callculate  the final price after tax 
{
	return(m_Convertible_Roof * get_tax_roof() + get_tax_import() * get_price() + get_tax_dealership());
}

ostream& operator<<(ostream& os, const Sports_Car& S)
{
	os << "";
	S.show_obj();
	return os;
}

bool Sports_Car::operator ==(const Sports_Car&others) const
{
	if((m_tax_roof == others.get_tax_roof()) && (m_door_num == others.get_door_num() && (m_seat_num == others.get_seat_num()) && (m_Convertible_Roof == others.get_Convertible_Roof()) && (Vehicle::operator==(others))))
	{
		return true;
	}
	return false; 
}


void Sports_Car::set_tax_roof(unsigned int tax_roof) //set the tax roof 
{
	m_tax_roof = tax_roof;
}


void Sports_Car::serialize(fstream& file) const
{
	file << m_Convertible_Roof << " " << m_door_num << " " << m_seat_num << " " << m_tax_roof << endl;
	Vehicle::serialize_v(file);

}
void Sports_Car::deserialize(fstream& file)
{
	bool convertible_roof;
	string str;
	file >> convertible_roof;
	m_Convertible_Roof = convertible_roof;
	file >> str;
	m_door_num = convert_str_to_num(str);
	file >> str;
	m_seat_num = convert_str_to_num(str);
	file >> str;
	m_tax_roof = convert_str_to_num(str);
	Vehicle::deserialize_v(file);

}

int Sports_Car::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}