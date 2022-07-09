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

Product* Admin::selectProduct()
{
	return nullptr;
}

Client::Client()
{
}

Client::Client(std::string username, std::string password, Role role): User(username, password, role)
{
}

Product* Client::selectProduct()
{

	std::ifstream fin;
	std::string line;
	std::string aux;
	std::string word;
	int integer;
	float floating;
	size_t pos;
	int stoi;
	float stof;
	

	Product* choice1 = new CPU(0, 0, "");
	Product* choice2 = new GPU("0x0", OpenGL);
	Product* choice3 = new APU();
	int c1 = 0, c2 = 0, c3 = 0;

	fin.open("listaProduse.txt");
	getline(fin, line);
	std::cout << line << std::endl;

	if (line[line.length() - 3] == 'C')
	{
		c1 = 1;
	}
	else if (line[line.length() - 3] == 'G')
	{
		c2 = 1;
	}
	else
	{
		c3 = 1;
	}

	
	while (fin)
	{
		getline(fin, line);
		std::cout << line << std::endl;


		if (line == "")
			break;
		else
		{
			pos = line.find_first_of(':');
			aux = line.substr(0, pos);
			std::cout << aux << std::endl;
			/*for (pos = 0; pos < line.length(); pos++)
			{
				if (line[pos] == ':')
				{
					pos += 2;
					break;
				}
				aux += line[pos];
			}*/
			
			// if the choice is a CPU
			if(c1 == 1)
			{
				if (aux == "Name")
				{
					choice1->setName(line.substr(pos + 2));
					//std::cout << choice1->getName();
				}

				if (aux == "Weight")
				{
					//stof= convert string to float
					choice1->setWeight(std::stof(line.substr(pos + 2, 3)));
				}

				if (aux == "Height")
				{
					choice1->setHeight(std::stoi(line.substr(pos + 2, 3)));
				}

				if (aux == "TDP")
				{
					choice1->setTDP(std::stoi(line.substr(pos + 2, 3)));
				}
			}
		}
	}

	
	fin.close();
	return choice1;
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
