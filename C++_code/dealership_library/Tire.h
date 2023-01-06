//#pragma once

#ifndef Tire_H
#define Tire_H
#include <string>

using std::string;
using namespace std;

class Tire {
private:
	string m_Brand;
	int m_Tread_Width;//width in milimeters
	int m_Diameter;//diameter in inches

public:
	Tire(string B, int W, int D);		// Constructor
	Tire(const  Tire&);				// copy Constructor
	Tire();							// default Constructor
	~Tire();						// destructor


	string get_Brand() const; // return the Brand
	int get_Width() const; // return the Tread Width
	int get_Diameter() const; // return the Diameter


	void set_Brand(string B); // set the Brand
	void set_Width(int W); // set the Tread Width
	void set_Diameter(int D); // set the Diameter
	void show(void) const;			// print Tire
	friend ostream& operator<<(ostream& os, const Tire& T);
	bool operator==(const Tire& others) const;

	void serialize(fstream& file) const;
	void deserialize(fstream& file);


	int convert_str_to_num(string str) const;

};



#endif 