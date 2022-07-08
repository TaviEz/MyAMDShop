#include "User.h"
#include <iostream>
#include <string>


const char* ToString(Role r)
{
	switch (r)
	{
	case admin: return "Admin";
	case client: return "Client";
	default: return "Unknown type of user";
	}

}

User::User()
{
	static int id = 0;
	_id = id++;
}

User::User(std::string username, std::string password, Role role)
{
	this->username = username;
	this->password = password;
	this->role = role;
}

Admin::Admin()
{
	role = admin;
}

Admin::Admin(std::string username, std::string password, Role role) : User(username, password, role)
{
}

void Admin::addProduct(Product& p)
{
	std::ofstream fout;
	fout.open("listaProduse.txt", std::ios::app);
	if (typeid(p).name() == "CPU" || typeid(p).name() == "GPU")
		fout << "yay" << std::endl;
	else
		fout << "nay" << std::endl;

	fout << "Type of product: " << typeid(p).name() << std::endl;
	fout << "Name: " << p.getName() << std::endl;
	fout << "Weight: " << p.getWeight() << " g" << std::endl;
	fout << "Height: " << p.getHeight() << " mm" << std::endl;
	fout << "TDP: " << p.getTDP() << " W" << std::endl;
	fout << "Nms: " << p.getNms() << std::endl;
	fout << "Memory: " << p.getMemory() << std::endl;
	fout << "Frequency: " << p.getFrequency() << " MHz" << std::endl;

	fout.close();
}


