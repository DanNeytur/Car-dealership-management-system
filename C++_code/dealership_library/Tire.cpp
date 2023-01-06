#include <iostream>
#include "Tire.h"
#include <string>
#include "Vehicle.h"

using namespace std;

ostream& operator<<(ostream& os, const Tire& T)
{
	//T.show();
	os << T.get_Brand() << T.get_Diameter() << T.get_Width() << endl; 
	return os;
}
bool Tire::operator==(const Tire& others) const
{
	if ((this->m_Brand == others.get_Brand()) &&
		(this->m_Tread_Width == others.get_Width()) &&
		(this->m_Diameter == others.get_Diameter()))
		return true;

	return false;
}


Tire::Tire(string B, int W, int D) // Constructor
{
	m_Brand = B;
	m_Tread_Width = W;//width in milimeters
	m_Diameter = D;//diameter in inches

}

Tire::Tire(const Tire& other) // copy Constructor
{
	m_Brand = other.m_Brand;
	m_Tread_Width = other.m_Tread_Width;
	m_Diameter = other.m_Diameter;

}

Tire::Tire()// default Constructor
{
	m_Brand = '0';
	m_Tread_Width = 0;
	m_Diameter = 0;
}


Tire::~Tire() // destructor
{
}

void Tire::show(void) const
{
	cout << "Tire Brand:" << m_Brand << endl
		<< "Tread Width:" << m_Tread_Width << endl
		<< "Diameter:" << m_Diameter << endl;
}


string Tire::get_Brand() const // return the Brand
{
	return m_Brand;
}

int Tire::get_Width() const // return the Tread_Width
{
	return m_Tread_Width;
}

int Tire::get_Diameter() const // return the Diameter
{
	return m_Diameter;
}


void Tire::set_Brand(string B) // set the Brand
{
	m_Brand = B;
}

void Tire::set_Width(int W) // set the Tread Width
{
	m_Tread_Width = W;
}

void Tire::set_Diameter(int D) // set the Diameter
{
	m_Diameter = D;
}


void Tire::serialize(fstream& file) const
{
	file << m_Brand << " " << m_Tread_Width << " " << m_Diameter << endl;


}
void Tire::deserialize(fstream& file)
{
	string str;
	file >> str;
	m_Brand = str;
	file >> str;
	m_Tread_Width = convert_str_to_num(str);
	file >> str;
	m_Diameter = convert_str_to_num(str);

}

int Tire::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}
