//#pragma once

#ifndef Sports_Car_H
#define Sports_Car_H
#include <string>
#include "Vehicle.h"

using std::string;

class Sports_Car : public Vehicle {
private:
	bool m_Convertible_Roof;	//Convertible roof flag- 0=not Convertible, 1=Convertible
	static unsigned m_door_num;	//number of doors
	static unsigned m_seat_num; //number of seats
	//unsigned long m_final_price; // final Price 
	unsigned  m_tax_roof; // tax of roof 
public:
	Sports_Car(/*unsigned int LP, */string Comp, string M, string C, Tire* T/*, unsigned int num_t*/, Engine E_V,unsigned long price, bool CR);	// Constructor
	Sports_Car(const  Sports_Car&);		// copy Constructor
	Sports_Car();						// default Constructor
	~Sports_Car();						// destructor

	unsigned get_tax_roof() const; //return the tax roof 
	unsigned get_door_num() const; // return the number of doors
	unsigned get_seat_num() const; // return the number of seats
	bool get_Convertible_Roof() const; // return Convertible roof flag
	double final_price() const ; //  callculate  the final price of sport Car
	friend ostream& operator<<(ostream& os, const Sports_Car& S);
	bool operator ==(const Sports_Car& others) const;
	static void set_door_num(unsigned DN) // set return the number of doors
	{
		m_door_num = DN;
	}
	static void set_seat_num(unsigned SN) // set the number of seats
	{
		m_seat_num = SN;
	}
	void set_Convertible_Roof(bool CR); // set the return Convertible roof flag
	//static void set_tax_roof(unsigned int tax_roof) //set the tax roof 
	//{
	//	m_tax_roof = tax_roof;
	//}
	void set_tax_roof(unsigned int tax_roof); //set the tax roof 
	void show_obj(void) const;			// print sports car

	void serialize(fstream& file) const;
	void deserialize(fstream& file);

	int convert_str_to_num(string str) const;

};
#endif 