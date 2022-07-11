#include "User.h"
#include <iostream>
#include <string>
#include <map>
#include <boost/assign/list_of.hpp>
#include <boost/assert.hpp>

using namespace boost::assign;


const char* ToString(Role r)
{
	switch (r)
	{
	case admin: return "Admin";
	case client: return "Client";
	default: return "Unknown type of user";
	}

}

const Technology stringToEnum(std::string str)
{
	std::map < std::string, Technology> xmap = map_list_of("OpenGL", OpenGL)("DirectX", DirectX);
	for (const auto& tech : xmap)
	{
		if (tech.first == str)
			return tech.second;
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

void Admin::addProduct(Product* p)
{
	std::ofstream fout;
	fout.open("listaProduse.txt", std::ios::app);

	fout << "Type of product: " << p->getVar() << std::endl;
	fout << "Name: " << p->getName() << std::endl;
	fout << "Weight: " << p->getWeight() << " g" << std::endl;
	fout << "Height: " << p->getHeight() << " mm" << std::endl;
	fout << "TDP: " << p->getTDP() << " W" << std::endl;
	fout << "Nms: " << p->getNms() << std::endl;
	fout << "Memory: " << p->getMemory() << std::endl;
	fout << "Frequency: " << p->getFrequency() << " MHz" << std::endl;
	
	if (p->getVar() == "class CPU")
	{
		fout << "Cores: " << p->getCores() << std::endl;
		fout << "Threads: " << p->getThreads() << std::endl;
		fout << "Socket: " << p->getSocket() << std::endl << std::endl;
	}

	if (p->getVar() == "class GPU")
	{
		fout << "Maximum Resolution: " << p->getMaxRes() << std::endl;
		fout << "Technology supported: " << ToString(p->getTech()) << std::endl << std::endl;
	}

	if (p->getVar() == "class APU")
	{
		fout << "Cores: " << p->getCores() << std::endl;
		fout << "Threads: " << p->getThreads() << std::endl;
		fout << "Socket: " << p->getSocket() << std::endl;
		fout << "Maximum Resolution: " << p->getMaxRes() << std::endl;
		fout << "Technology supported: " << ToString(p->getTech()) << std::endl << std::endl;

	}
	

	fout.close();
}

void Admin::selectProduct()
{

}

Client::Client()
{
}

Client::Client(std::string username, std::string password, Role role): User(username, password, role)
{
}

void Client::selectProduct()
{

	std::ifstream fin;
	std::ofstream fout;
	std::string line;
	std::string aux;

	size_t pos;
	size_t auxpos;
	Product* choice = nullptr;
	
	fin.open("listaProduse.txt");
	fout.open("ShoppingCart.txt", std::ios::app);


	while (fin)
	{
		getline(fin, line);

		for (int i = line.find_first_of("s") + 3; i < line.length(); i++)
			aux += line[i];

		if (aux == "CPU")
		{
			choice = new CPU(0, 0, "");
		}
		else if (aux == "GPU")
		{
			choice = new GPU("0x0", OpenGL);

		}
		else if (aux == "APU")
		{
			choice = new APU();
		}
		

		pos = line.find_first_of(':');
		aux = line.substr(0, pos);
		fout << aux << ": ";

		if (aux == "Type of product")
		{
			fout << choice->getVar() << std::endl;
		}

		// adaugam campurile comune in fisier
		if (aux == "Name")
		{
			choice->setName(line.substr(pos + 2));
			fout << choice->getName() << std::endl;
		}

		if (aux == "Weight")
		{
			//stof= convert string to float
			choice->setWeight(std::stof(line.substr(pos + 2, 5)));
			fout << choice->getWeight() << std::endl;
		}

		if (aux == "Height")
		{
			choice->setHeight(std::stoi(line.substr(pos + 2, 3)));
			fout << choice->getHeight() << std::endl;
		}

		if (aux == "TDP")
		{
			choice->setTDP(std::stoi(line.substr(pos + 2, 2)));
			fout << choice->getTDP() << std::endl;
		}

		if (aux == "Nms")
		{
			choice->setNms(std::stoi(line.substr(pos + 2, 2)));
			fout << choice->getNms() << std::endl;
		}

		if (aux == "Memory")
		{
			choice->setMemory(std::stoi(line.substr(pos + 2, 2)));
			fout << choice->getMemory() << std::endl;
		}

		if (aux == "Frequency")
		{
			choice->setFrequency(std::stof(line.substr(pos + 2, 5)));
			fout << choice->getFrequency() << std::endl;
		}

		// daca produsul este CPU
		if(choice->getVar() == "class CPU")
		{
			if (aux == "Cores")
			{
				choice->setCores(std::stof(line.substr(pos + 2, 1)));
				fout << choice->getCores() << std::endl;
			}

			if (aux == "Threads")
			{
				choice->setThreads(std::stof(line.substr(pos + 2, 2)));
				fout << choice->getThreads() << std::endl;
			}

			if(aux == "Socket")
			{
				choice->setSocket(line.substr(pos + 2, 3));
				fout << choice->getSocket() << std::endl << std::endl;
			}
		}

		// daca produsul este GPU
		if (choice->getVar() == "class GPU")
		{
			if (aux == "Maximum Resolution")
			{
				choice->setMaxRes(line.substr(pos + 2, 10));
				fout << choice->getMaxRes() << std::endl;
			}

			if (aux == "Technology supported")
			{
				choice->setTech(stringToEnum(line.substr(pos + 2, 7)));
				fout << ToString(choice->getTech()) << std::endl << std::endl;
			}
		}

		if (choice->getVar() == "class APU")
		{
			if (aux == "Cores")
			{
				choice->setCores(std::stof(line.substr(pos + 2, 1)));
				fout << choice->getCores() << std::endl;
			}

			if (aux == "Threads")
			{
				choice->setThreads(std::stof(line.substr(pos + 2, 2)));
				fout << choice->getThreads() << std::endl;
			}

			if (aux == "Socket")
			{
				choice->setSocket(line.substr(pos + 2, 3));
				fout << choice->getSocket() << std::endl;
			}

			if (aux == "Maximum Resolution")
			{
				choice->setMaxRes(line.substr(pos + 2, 10));
				fout << choice->getMaxRes() << std::endl;
			}

			if (aux == "Technology supported")
			{
				choice->setTech(stringToEnum(line.substr(pos + 2, 7)));
				fout << ToString(choice->getTech()) << std::endl << std::endl;
			}
		}
		
	}

	fin.close();
	fout.close();
}

void Client::addProduct(Product* p)
{
	std::string line;
	std::ofstream fout;
	fout.open("ShoppingCart.txt", std::ios::app);
	fout << p->getName() << std::endl;
	fout << p->getVar() << std::endl;
	fout.close();
}
