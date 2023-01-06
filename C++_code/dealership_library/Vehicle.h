//#pragma once

#ifndef Vehicle_H
#define Vehicle_H
#include <string>
#include "Tire.h"
#include "Engine.h"
#include <iostream>
#include <ostream>
#include <fstream>
#define m_num_tires 4
using namespace std;
using std::string;

class Vehicle {
private:
	string m_Company;
	string m_Model;
	string m_Color;
	Tire* m_Tires;
	Engine m_Engine;
	int m_left_in_stock;//how many cars from this specific car are left in dealership stock
	unsigned long  m_price;//starting price of te car
	unsigned int  m_tax_dealership; // tax of the Vehicle  sale 
	double m_tax_import; // tax of the Vehicle import 
	int popularity; //how many times the vehicle was sold
public:
	Vehicle(string Comp, string M, string C, Tire* T, Engine E_V, unsigned long price);// Constructor
	Vehicle(const  Vehicle&);				// copy Constructor
	Vehicle();							// default Constructor
	void show_v(void) const;				// print Vehicle
	friend ostream& operator<<(ostream& os, const Vehicle& V);	// print Vehicle
	bool operator==(const Vehicle& others) const;

	string get_company() const; // return the company 
	string get_model() const; // return the model
	string get_color() const; // return the color
	Tire* get_Tires() const; //return the array of tires
	unsigned int  get_tax_dealership()const; //return the tax dealership
	Engine get_Engine() const; //return the engine of vehicle
	unsigned long get_price()const; // return the price of the Vehicle
	double get_tax_import() const; // return the tax import 
	int get_left_stock() const; //return how many cars from this specific car are left
	int get_popularity() const;

	void set_company(string Comp); // set the company
	void set_model(string M); // set the model 
	void set_color(string C); // set the color
	void set_Tires(Tire* T); //set the array of tires
	void set_Engine(Engine E_V); //set the engine of vehicle
	void set_price(unsigned long  price); //set the price of vehicle

	void set_tax_import(double import_tax);
	void set_tax_dealership(int  tax_dealership);
	void set_left_stock(int);
	void set_popularity(int);

	void add_vehicle();//adding new vehicle by user
	int enter_number() const;
	string enter_string() const;


	virtual double final_price() const { return 0; }
	virtual void show() const {}
	~Vehicle();							// destructor

	void serialize_v(fstream& file) const;
	void deserialize_v(fstream& file);


	virtual void serialize(fstream& file) const {}
	virtual void deserialize(fstream& file) {}

	virtual void show_obj() const{}


	int convert_str_to_num(string str) const;

};
#endif