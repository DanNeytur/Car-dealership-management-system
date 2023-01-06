#include "Pickup_Truck.h"
#include "Vehicle.h"
using namespace std;

double Pickup_Truck::m_avg_cargo(70.0);

Pickup_Truck::Pickup_Truck(/*unsigned int LP, */string Comp, string M, string C, Tire* T/*, unsigned int num_t*/, Engine E_V,unsigned long price,int tailer, int cargo , int payload) : Vehicle(/*LP, */Comp, M, C, T/*, num_t*/, E_V,price) // Constructor
{
	m_max_tailering = tailer;
	m_max_cargo = cargo;
	m_max_payload = payload;
	//set_tax_import(0.05);
	//set_tax_dealership(3000);
	//m_avg_cargo =70.0;
}

Pickup_Truck::Pickup_Truck() //deafult 
{
	m_max_tailering = 0;
	m_max_cargo = 0;
	m_max_payload = 0;
	//m_avg_cargo = 70.0;
	//this->set_tax_dealership(3000);
	//this->set_tax_import(0.05);
}

Pickup_Truck::Pickup_Truck(const Pickup_Truck& other):Vehicle(other)
{
	m_max_tailering = other.get_tailering();
	m_max_cargo = other.get_cargo();
	m_max_payload = other.get_payload();
	//set_tax_import(other.get_tax_import());
	//set_tax_dealership(other.get_tax_dealership());
	set_avg_cargo(other.get_avg_cargo());
}

Pickup_Truck::~Pickup_Truck() // destructor 
{
}  
int Pickup_Truck::get_tailering() const 
{
	return m_max_tailering;
}
int Pickup_Truck::get_cargo() const 
{
	return m_max_cargo;
}
int Pickup_Truck::get_payload() const 
{
	return m_max_payload;
}
double Pickup_Truck::get_avg_cargo() const 
{
	return m_avg_cargo;
}

void Pickup_Truck ::set_tailering(int tailering)
{
	m_max_tailering = tailering;
}

void Pickup_Truck::set_cargo(int cargo)
{
	m_max_cargo = cargo;
}
void Pickup_Truck::set_payload(int payload)
{
	m_max_payload = payload;
}

//void Pickup_Truck::set_avg_cargo(double avg_cargo)//set the avarge valume of cargo 
//{
//	this->m_avg_cargo = avg_cargo;
//}

double   Pickup_Truck::final_price() const
{
	return(((double)m_max_cargo/get_avg_cargo()) * CARGO_RATIO + get_tax_import()*get_price() + get_tax_dealership());

}

void Pickup_Truck::show_obj(void) const
{
	cout << " Pickup_Truck:" << endl << endl;
	show_v();
	cout <<endl<< "max tailering :" << m_max_tailering << endl
		<< "max_cargo :" << m_max_cargo << endl
		<< "max_payload:" << m_max_payload << endl
		<< "avarge cargo :" << m_avg_cargo << endl
		<<endl<< "final price Pickup Truck:       " << this->final_price() <<endl<< endl;
}

ostream& operator<<(ostream& os, const Pickup_Truck& P)
{
	os << "";
	P.show_obj();
	return os;
}

bool Pickup_Truck:: operator ==(const Pickup_Truck&others) const
{
	if((m_max_tailering==others.get_tailering())&&(m_max_cargo==others.get_cargo())&&
		(m_max_payload==others.get_payload())&&(m_avg_cargo==others.get_avg_cargo())&&(Vehicle::operator==(others)))
	{
		return true;
	}
	return false;
}

void Pickup_Truck::serialize(fstream& file) const
{
	file << m_max_tailering << " " << m_max_cargo << " " << m_max_payload << " " << m_avg_cargo << endl;
	Vehicle::serialize_v(file);

}
void Pickup_Truck::deserialize(fstream& file)
{
	string str;
	file >> str;
	m_max_tailering = convert_str_to_num(str);
	file >> str;
	m_max_cargo = convert_str_to_num(str);
	file >> str;
	m_max_payload = convert_str_to_num(str);
	file >> str;
	m_avg_cargo = stod(str);
	Vehicle::deserialize_v(file);
}


int Pickup_Truck::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}
