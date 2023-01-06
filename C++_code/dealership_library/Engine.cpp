#include <iostream>
#include <fstream>
#include "Engine.h"
#include <string>
#include "Vehicle.h"

using namespace std;

ostream& operator<<(ostream& os, const Engine& E) 
{
	os << "";
	E.show();
	return os;
}

bool Engine::operator==(const Engine& others) const
{
	if ((this->m_Engine_Type == others.get_Engine_Type()) &&
		(this->m_Engine_Horsepower == others.get_Engine_Horsepower()) &&
		(this->m_Valve_num == others.get_Valve_num()) &&
		(this->m_Engine_Capacity == others.get_Engine_Capacity()))
		return true;

	return false;
}

Engine::Engine(string ET, int HP, int V_num, int CC) // Constructor
{
	m_Engine_Type = ET;
	m_Engine_Horsepower = HP;
	m_Valve_num = V_num;
	m_Engine_Capacity = CC; //in cubic centimeters
}

Engine::Engine(const  Engine& E) // copy Constructor
{
	m_Engine_Type = E.m_Engine_Type;
	m_Engine_Horsepower = E.m_Engine_Horsepower;
	m_Valve_num = E.m_Valve_num;
	m_Engine_Capacity = E.m_Engine_Capacity; //in cubic centimeters

}


Engine::Engine()// default Constructor
{
	m_Engine_Horsepower = 0;
	m_Valve_num = 0;
	m_Engine_Capacity = 0;
	m_Engine_Type = '0';
}


Engine::~Engine()	// destructor
{
}

void Engine::show(void) const
{
	cout << "Engine Type:" << m_Engine_Type << '\n'
		<< "Engine Horsepower:" << m_Engine_Horsepower << '\n'
		<< "number of Valves:" << m_Valve_num << '\n'
		<< "Engine Capacity in CC:" << m_Engine_Capacity << endl;
}


string Engine::get_Engine_Type() const //return the Engine Type
{
	return m_Engine_Type;
}
int Engine::get_Engine_Horsepower() const // return the Engine Horsepower
{
	return m_Engine_Horsepower;
}

int  Engine::get_Valve_num() const // return the number of Valves
{
	return m_Valve_num;
}
int  Engine::get_Engine_Capacity() const // return the Engine Capacity in cubic centimeters
{
	return m_Engine_Capacity;
}
void Engine::set_Engine_Type(string ET) //set the Engine Type
{
	m_Engine_Type = ET;
}
void  Engine::set_Engine_Horsepower(int HP) // set the Engine Horsepower
{
	m_Engine_Horsepower = HP;
}
void  Engine::set_Valve_num(int V_num) // set the number of Valves
{
	m_Valve_num = V_num;
}
void Engine::set_Engine_Capacity(int CC) // set Engine Capacity in cubic centimeters
{
	m_Engine_Capacity = CC;
}

void Engine::serialize(fstream& file) const
{
	file << m_Engine_Type << " " << m_Engine_Horsepower << " " << m_Valve_num << " " << m_Engine_Capacity << endl;


}
void Engine::deserialize(fstream& file)
{
	string str;
	file >> str;
	m_Engine_Type = str;
	file >> str;
	m_Engine_Horsepower = convert_str_to_num(str);
	file >> str;
	m_Valve_num = convert_str_to_num(str);
	file >> str;
	m_Engine_Capacity = convert_str_to_num(str);

}

int Engine::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}
