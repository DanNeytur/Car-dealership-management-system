#ifndef Pickup_Truck_H
#define Pickup_Truck_H
#include <string>
#include "Vehicle.h"
#define CARGO_RATIO 10000

class Pickup_Truck :public Vehicle
{
public:
	Pickup_Truck(string Comp, string M, string C, Tire* T, Engine E_V,unsigned long price, int tailer, int cargo, int payload);//cunstructor 
	Pickup_Truck(const Pickup_Truck &);// copy Constructor 
	Pickup_Truck(); //deafult 
	~Pickup_Truck();// destructor 
	int get_tailering()const;
	int get_cargo() const;
	int get_payload() const;
	double get_avg_cargo() const; //return avarge valume 
	void show_obj() const; 
	friend ostream& operator<<(ostream& os, const Pickup_Truck& P);
	bool operator==(const Pickup_Truck& others) const;
	void set_tailering(int);
	void set_cargo(int);
	void  set_payload(int);
	static void set_avg_cargo(double avg_cargo)//set the avarge valume of cargo
	{
		m_avg_cargo = avg_cargo;
	}
	double  final_price() const; //calculating the final price

	void serialize(fstream& file) const;
	void deserialize(fstream& file);


	int convert_str_to_num(string str) const;

protected :
	int m_max_tailering; //max weight the vehicle can tail. in lbs
	int m_max_cargo;//max volume of cargo the vehicle can fit. in cu/ft
	int m_max_payload;//max weight of the payload. in lbs
	static double m_avg_cargo;// avarge valume of cargo the Vehicle 

};
#endif 

