#include "Dealership_system.h"
#include "Pickup_Truck.h"
#include <string>
#include "Sports_Car.h"
#include "Vehicle.h"
#include <ostream>
#include <iostream>
#include <fstream>

using std::vector;

using namespace std;


Dealership_system::Dealership_system()//default constructor
{
	//selected_index_car = 0;
	selected_stock = "Pickup_stock";
	m_tax_dealership_pickup = 3000;	// tax of the pickup sale 
	m_tax_import_pickup = 0.05;				// tax of the pickup import 
	m_tax_dealership_sports = 10000; // tax of the pickup sale 
	m_tax_import_sports = 0.1;				// tax of the pickup import 
	m_tax_roof = 10000;						// tax of Convertible roof
	system_running = 1;

	cnt_temp = 0;

	deserialize();

}
Dealership_system::~Dealership_system()//destructor
{

}

void Dealership_system::show_vect()const
{
	if (selected_stock == "sports_stock")
	{
		cout << " sports cars in dealership stock:" << endl;
		show_sel_vect(m_Sports_stock);
	}
	else  if (selected_stock == "sports_sold")
	{

		cout << "sports cars sold:" << endl;
		show_sel_vect(m_Sports_sold);

	}
	else if (selected_stock == "pickup_stock")
	{

		cout << "Pickup Truck  in dealership stock:" << endl;
		show_sel_vect(m_Pickup_stock);
	}

	else if (selected_stock == "pickup_sold")
	{

		cout << "Pickup Truck that we sold:" << endl;
		show_sel_vect(m_Pickup_sold);
	}

	cout << "---------------------------------------------------" << endl;
}


void Dealership_system::add_customer()
{
	cout << "Enter new customer: " << endl;
	cout << "Enter customer private name :" << endl; //enter customer's private name
	string private_name = enter_string();
	new_customer.set_private_name(private_name);
	cout << endl;

	cout << "Enter customer last name :" << endl; //enter customer's last name
	string last_name = enter_string();
	new_customer.set_last_name(last_name);
	cout << endl;

	cout << "Enter customer id :" << endl; //enter customer's id
	int id = enter_number();
	new_customer.set_id(id);
	cout << endl;

	cout << "Enter Customer cell phone number:" << endl; //enter customer's cell phone number
	int cell_num = enter_number();
	new_customer.set_cell_num(cell_num);
	cout << endl;

}

void Dealership_system::pick_a_car()
{
	this->select_stock(); //select a stock to show
	this->show_vect();//showing the selected stock

	int selected_index_car;

	//enter the selected car into customer and save the customer
	if (selected_stock == "sports_stock")
	{
		if (m_Sports_stock.empty())
			return;

		selected_index_car = select_index();
		new_customer.set_Vehicle(&m_Sports_stock[selected_index_car], selected_index_car);
		m_Sports_sold.push_back(new_customer);

		int left_new = m_Sports_stock[selected_index_car].get_left_stock() - 1;
		m_Sports_stock[selected_index_car].set_left_stock(left_new);

		int new_pop = m_Sports_stock[selected_index_car].get_popularity() + 1;
		m_Sports_stock[selected_index_car].set_popularity(new_pop);

	}
	else if (selected_stock == "pickup_stock")
	{
		if (m_Pickup_stock.empty())
			return;

		selected_index_car = select_index();
		new_customer.set_Vehicle(&m_Pickup_stock[selected_index_car], selected_index_car);
		m_Pickup_sold.push_back(new_customer);

		int left_new = m_Pickup_stock[selected_index_car].get_left_stock() - 1;
		m_Pickup_stock[selected_index_car].set_left_stock(left_new);

		int new_pop = m_Pickup_stock[selected_index_car].get_popularity() + 1;
		m_Pickup_stock[selected_index_car].set_popularity(new_pop);
	}

}

void  Dealership_system::show_menu()//show system's options
{
	cout << "The menu:" << endl
		<< "1. show stocks in dealership" << endl
		<< "2. show customers" << endl
		<< "3. add customer" << endl
		<< "4. show cars in stock by popularity" << endl
		<< "5. change stocks in dealership" << endl
		<< "6. change taxes" << endl
		<< "7. exit system " << endl;
}


void Dealership_system::start()
{
	cout << "************************************************************" << endl
		<< "            Welcome To Dealership system " << endl
		<< "************************************************************" << endl;

	while (system_running)
	{
		this->show_menu();
		int option;
		do
		{
			cout << "please pick an optaion from the menu:" << endl;
			option = enter_number();
		} while ((option < 1) && (option > 7));

		switch (option)
		{
		case 1: //show stocks in dealership
		{
			this->select_stock();
			this->show_vect();//showing the selected stock
			break;
		}
		case 2: //show customers
		{
			this->select_sold();
			this->show_vect();//showing the selected stock
			break;
		}
		case 3: //add customer
		{
			this->add_customer();
			this->pick_a_car();
			break;
		}
		case 4: //show data
		{
			this->show_by_popularity();
			break;
		}
		case 5: // change stocks in dealership
		{
			this->changes();
			break;
		}
		case 6: // change taxes
		{
			this->change_taxes();
			break;
		}
		case 7: // serialize the data and exit program
		{
			this->serialize();//saving data
			system_running = 0;
			break;
		}
		}

	}
}

int Dealership_system::enter_number() const
{
	int out;
	cin >> out;
	getchar();
	return out;
}

string Dealership_system::enter_string() const
{
	string s;
	getline(cin, s);
	return s;
}

int Dealership_system::convert_str_to_num(string str) const
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0') {
		num = num * 10 + (str[i++] - '0');
	}
	return num;
}


void Dealership_system::select_stock()
{
	int option;
	do //user must pick 1 or 2
	{
		cout << "please pick 1 of the stocks in dealership:" << endl << "1.sports_stock" << endl << "2.pickup_stock" << endl;
		option = enter_number();
		if (option == 1)
			selected_stock = "sports_stock";
		else selected_stock = "pickup_stock";
	} while ((option != 1) && (option != 2));

}

void  Dealership_system::select_sold()//shows the diffrent sold options
{
	int option;
	do //user must pick 1 or 2
	{
		cout << "please pick 1 of the customer lists: " << endl << "1.sports_sold" << endl << "2.pickup_sold" << endl;
		option = enter_number();
		if (option == 1)
			selected_stock = "sports_sold";
		else selected_stock = "pickup_sold";
	} while ((option != 1) && (option != 2));

}




void Dealership_system::changes()// change the selected vector
{
	cout << "pick the change:" << endl
		<< "1. add a car" << endl
		<< "2. remove a car" << endl;

	int change;
	do //user must pick 1 or 2
	{
		cout << "please enter change's number:" << endl;
		change = enter_number();
	} while ((change != 1) && (change != 2));



	select_stock();

	if (change == 1)	//add a car to selected vector
		add_car();
	else //remove a car from selected vector
	{
		this->show_vect();//showing the selected stock
		this->remove_car();//removing selected car
	}

}

int Dealership_system::select_index() const
{
	int num_cars = 0;
	if (selected_stock == "sports_stock") //saving the size of the selected stock
		num_cars = this->m_Sports_stock.size();
	else
		num_cars = this->m_Pickup_stock.size();

	int selected_index_car;
	cout << "Please pick a car index:" << endl;
	do //the customer picks a car within the existing range of the selected stock
	{
		cout << "Please pick a car index from the selected stock" << endl;
		selected_index_car = enter_number();
	} while ((selected_index_car < 1) && (selected_index_car > num_cars));

	selected_index_car--;
	return selected_index_car;
}

void Dealership_system::remove_car()
{
	int selected_index;
	if (selected_stock == "sports_stock")
	{
		if (m_Sports_stock.empty())
			return;
		selected_index = this->select_index();
		vector<Sports_Car>::iterator it;
		it = find(m_Sports_stock.begin(), m_Sports_stock.end(), m_Sports_stock[selected_index]);
		if (it != m_Sports_stock.end())
			m_Sports_stock.erase(it);
	}
	else if (selected_stock == "pickup_stock")
	{
		if (m_Pickup_stock.empty())
			return;
		selected_index = this->select_index();
		vector<Pickup_Truck>::iterator it;
		it = find(m_Pickup_stock.begin(), m_Pickup_stock.end(), m_Pickup_stock[selected_index]);
		if (it != m_Pickup_stock.end())
			m_Pickup_stock.erase(it);
	}

}


void Dealership_system::add_car()
{
	cout << "enter the details of the car:" << endl;
	if (selected_stock == "pickup_stock") //adding a pickup truck
	{
		Pickup_Truck Pickup;
		string name;
		int number;

		
		Pickup.add_vehicle();

		Pickup.set_tax_dealership(this->m_tax_dealership_pickup);
		Pickup.set_tax_import(this->m_tax_import_pickup);

		cout << "please enter vehicle's max payload:" << endl;
		number = this->enter_number();
		Pickup.set_payload(number);

		cout << "please enter vehicle's max cargo:" << endl;
		number = this->enter_number();
		Pickup.set_cargo(number);

		cout << "please enter vehicle's max tailering:" << endl;
		number = this->enter_number();
		Pickup.set_tailering(number);

		cout << Pickup;
		cout << "***********************************************************************" << endl;


		m_Pickup_stock.push_back(Pickup);

	}
	else if (selected_stock == "sports_stock") //adding a sports car
	{
		Sports_Car Sports;
		int  roof;
		
		Sports.add_vehicle();
		Sports.set_tax_dealership(m_tax_dealership_sports);
		Sports.set_tax_import(m_tax_import_sports);
		Sports.set_tax_roof(m_tax_roof);

		do
		{
			cout << "please enter if the vehicle has a roof:" << endl;
			cout << "For Convertible type- '1'" << endl << "For Not type Convertible- '0'" << endl;
			roof = enter_number();
		} while ((roof != 0) && (roof != 1));

		Sports.set_Convertible_Roof(roof);
		

		cout << Sports;

		m_Sports_stock.push_back(Sports);

		cout << "****************************************************************************************" << endl;

	}

	show_vect();

}

void Dealership_system::change_taxes()//change the taxes
{
	int option;
	do
	{
		cout << "pick tax to change:" << endl
			<< "1. dealership tax for pickup:" << this->m_tax_dealership_pickup << endl
			<< "2. dealership tax for sports:" << this->m_tax_dealership_sports << endl
			<< "3. tax for import pickup:" << this->m_tax_import_pickup << endl
			<< "4. tax for import sports:" << this->m_tax_import_sports << endl
			<< "5. tax for Convertible roof:" << this->m_tax_roof << endl;
		option = enter_number();
	} while ((option < 1) && (option > 5));

	cout << "enter new tax:" << endl;
	int new_tax = enter_number();

	switch (option)
	{
	case 1: //dealership tax for pickup
	{
		this->set_tax_dealership_pickup(new_tax);
		break;
	}

	case 2: //dealership tax for sports
	{
		this->set_tax_dealership_sports(new_tax);
		break;
	}

	case 3: //tax for import pickup
	{
		this->set_tax_import_pickup(new_tax);
		break;
	}

	case 4: //tax for import sports
	{
		this->set_tax_import_sports(new_tax);
		break;
	}

	case 5: //tax of Convertible roof
	{
		this->set_tax_roof(new_tax);
		break;
	}
	}

}


void Dealership_system::set_tax_dealership_pickup(int new_tax)	//set  tax of the pickup sale
{
	this->m_tax_dealership_pickup = new_tax;
}
void  Dealership_system::set_tax_import_pickup(int new_tax)	// set tax of the pickup import 
{
	this->m_tax_import_pickup = new_tax;
}
void  Dealership_system::set_tax_dealership_sports(int new_tax) // set tax of the pickup sale 
{
	this->m_tax_dealership_sports = new_tax;
}
void  Dealership_system::set_tax_import_sports(int new_tax)	//set tax of the pickup import 
{
	this->m_tax_dealership_sports = new_tax;
}
void  Dealership_system::set_tax_roof(int new_tax)	// tax of Convertible roof
{
	this->m_tax_roof = new_tax;

}

void Dealership_system::serialize()
{
	fstream file;
	file.open("my_file.txt", std::ios::out | std::ios::trunc);
	if (!file) {
		cout << "File not created" << endl;
	}
	else {
		if (!m_Pickup_stock.empty()) {
			file << "m_Pickup_stock" << endl;
			for (int i = 0; i < m_Pickup_stock.size(); i++) {
				m_Pickup_stock[i].serialize(file);
			}
			file << "end_m_Pickup_stock" << endl;
		}

		if (!m_Pickup_sold.empty()) {
			file << "m_Pickup_sold" << endl;
			for (int i = 0; i < m_Pickup_sold.size(); i++) {
				m_Pickup_sold[i].serialize(file);
			}
			file << "end_m_Pickup_sold" << endl;
		}

		if (!m_Sports_stock.empty()) {
			file << "m_Sports_stock" << endl;
			for (int i = 0; i < m_Sports_stock.size(); i++) {
				m_Sports_stock[i].serialize(file);
			}
			file << "end_m_Sports_stock" << endl;
		}

		if (!m_Sports_sold.empty()) {
			file << "m_Sports_sold" << endl;
			for (int i = 0; i < m_Sports_sold.size(); i++) {
				m_Sports_sold[i].serialize(file);
			}
			file << "end_m_Sports_sold" << endl;
		}

		file << "end";
		file.close();
	}
}

void Dealership_system::deserialize()
{
	fstream file;
	file.open("my_file.txt", ios::in);
	if (!file)
	{
		cout << "File not found!" << endl;
	}
	else
	{
		cout << "File was opened successfully!" << endl;
		Customer customer;
		string str;
		int type = -1;
		while (!file.eof())
		{
			file >> str;
			if (str == "end") {
				break;
			}
			if (str == "m_Pickup_stock") {
				while (true)
				{
					Pickup_Truck p;
					p.deserialize(file);
					m_Pickup_stock.push_back(p);
					p.~Pickup_Truck();

					std::streampos position = file.tellg();
					file >> str;
					if (str != "end_m_Pickup_stock") {
						file.seekp(position);
					}
					else {
						break;
					}
				}
			}
			else if (str == "m_Pickup_sold") {
				while (true)
				{
					Customer c;
					c.deserialize(file);
					int selected_car_index = c.get_car_stock_index();
					c.set_Vehicle(&m_Pickup_stock[selected_car_index], selected_car_index);
					m_Pickup_sold.push_back(c);
					c.~Customer();

					std::streampos position = file.tellg();
					file >> str;
					if (str != "end_m_Pickup_sold") {
						file.seekp(position);
					}
					else {
						break;
					}
				}
			}
			else if (str == "m_Sports_stock") {
				while (true)
				{
					Sports_Car c;
					c.deserialize(file);
					m_Sports_stock.push_back(c);
					c.~Sports_Car();

					std::streampos position = file.tellg();
					file >> str;
					if (str != "end_m_Sports_stock") {
						file.seekp(position);
					}
					else {
						break;
					}
				}
			}
			else if (str == "m_Sports_sold") {
				while (true)
				{
					Customer c;
					c.deserialize(file);
					int selected_car_index = c.get_car_stock_index();
					c.set_Vehicle(&m_Sports_stock[selected_car_index], selected_car_index);
					m_Sports_sold.push_back(c);
					c.~Customer();

					std::streampos position = file.tellg();
					file >> str;
					if (str != "end_m_Sports_sold") {
						file.seekp(position);
					}
					else {
						break;
					}
				}
			}
		}
	}

}


void Dealership_system::show_by_popularity()
{
	this->select_stock();

	if (selected_stock == "sports_stock")
	{
		for (int i = 1; i < m_Sports_stock.size(); i++)
		{
			if (m_Sports_stock[i - 1].get_popularity() > m_Sports_stock[i].get_popularity())
				swap(m_Sports_stock[i - 1], m_Sports_stock[i]);
		}
		reverse(m_Sports_stock.begin(), m_Sports_stock.end());
		cout << "sports stock sorted by popularity:" << endl;
	}
	else
	{
		for (int i = 1; i < m_Pickup_stock.size(); i++)
		{
			if (m_Pickup_stock[i - 1].get_popularity() > m_Pickup_stock[i].get_popularity())
				swap(m_Pickup_stock[i - 1], m_Pickup_stock[i]);
		}
		reverse(m_Pickup_stock.begin(), m_Pickup_stock.end());
		cout << "pickup stock sorted by popularity:" << endl;
	}
	this->show_vect();
}


