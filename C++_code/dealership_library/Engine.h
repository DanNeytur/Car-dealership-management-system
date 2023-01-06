//#pragma once

#ifndef Engine_H
#define Engine_H
#include <string>
#include <ostream>
using std::string;
using namespace std;

class Engine {
private:
	string m_Engine_Type;
	int m_Engine_Horsepower;
	int m_Valve_num;
	int m_Engine_Capacity; //in cubic centimeters
	

public:
	Engine(string ET, int HP, int V_num, int CC);		// Constructor
	Engine(const  Engine&);				// copy Constructor
	Engine();							// default Constructor
	void show(void) const;			// print Engine
	~Engine();						// destructor

	string get_Engine_Type() const; //return the Engine Type
	int get_Engine_Horsepower() const; // return the Engine Horsepower
	int get_Valve_num() const; // return the number of Valves
	int get_Engine_Capacity() const; // return the Engine Capacity in cubic centimeters
	friend ostream& operator<<(ostream& os, const Engine& E);
	bool operator==(const Engine& others) const;
	void set_Engine_Type(string ET); //set the Engine Type
	void set_Engine_Horsepower(int HP); // set the Engine Horsepower
	void set_Valve_num(int V_num); // set the number of Valves
	void set_Engine_Capacity(int CC); // set Engine Capacity in cubic centimeters

	void serialize(fstream& file) const;
	void deserialize(fstream& file);
	int convert_str_to_num(string str) const;

};



#endif 