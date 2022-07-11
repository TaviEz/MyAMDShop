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
	case admin: return "admin";
	case client: return "client";
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

void delete_line(const char* file_name, int n)
{
	std::ifstream fin(file_name);

	std::ofstream fout;
	std::string line;

	fout.open("temp.txt", std::ofstream::out);

	int line_no = 1;

	while (getline(fin, line))
	{
		if (line_no != n)
		{
			fout << line << std::endl;
		}
		line_no++;
	}

	fout.close();
	fin.close();
	remove(file_name);
	rename("temp.txt", file_name);
}

std::string iterate(std::string line, int& i, char c)
{
	{
		std::string aux = "";

		while (line[i] != ':')
			i++;

		i += 2;
		while (line[i] != c)
		{
			aux += line[i];
			i++;
		}

		return aux;
	}
}

const Role stringToEnum2(std::string str)
{
	std::map < std::string, Role> xmap = map_list_of("admin", admin)("client", client);
	for (const auto& role : xmap)
	{
		if (role.first == str)
			return role.second;
	}
}

bool isEmpty(std::ifstream& pFile)
{
	
	return pFile.peek() == std::ifstream::traits_type::eof();
	
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

	fout << "Type of product: " << p->getVar() << " ";
	fout << "Name: " << p->getName() << " ";
	fout << "Weight: " << p->getWeight() << " g" << " ";
	fout << "Height: " << p->getHeight() << " mm" << " ";
	fout << "TDP: " << p->getTDP() << " W" << " ";
	fout << "Nms: " << p->getNms() << " ";
	fout << "Memory: " << p->getMemory() << " ";
	if (p->getVar() == "class CPU")
		fout << "MB" << " ";
	else
		fout << "GB" << " ";

	fout << "Frequency: " << p->getFrequency() << " MHz" << " ";
	
	if (p->getVar() == "class CPU")
	{
		fout << "Cores: " << p->getCores() << " ";
		fout << "Threads: " << p->getThreads() << " ";
		fout << "Socket: " << p->getSocket() << " " << std::endl << std::endl;
	}

	if (p->getVar() == "class GPU")
	{
		fout << "Maximum Resolution: " << p->getMaxRes() << " ";
		fout << "Technology supported: " << ToString(p->getTech()) << " " << std::endl << std::endl;
	}

	if (p->getVar() == "class APU")
	{
		fout << "Cores: " << p->getCores() << " ";
		fout << "Threads: " << p->getThreads() << " ";
		fout << "Socket: " << p->getSocket() << " ";
		fout << "Maximum Resolution: " << p->getMaxRes() << " ";
		fout << "Technology supported: " << ToString(p->getTech()) << " " << std::endl << std::endl;

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
	std::string aux2;

	int start;
	int size;
	size_t auxpos;
	Product* choice = nullptr;
	
	fin.open("listaProduse.txt");
	fout.open("ShoppingCart.txt", std::ios::app);


	while (fin)
	{
		getline(fin, line);
		if (line == "")
			continue;
		size = line.find_first_of(':');
		aux = line.substr(0, size);
		//aux = Type of product
		fout << aux << ": ";
		aux2 = aux;

		aux = "";

		int i;
		for (i = line.find_first_of("s") + 3; i < line.find_first_of("U") + 1; i++)
			aux += line[i];

		if (aux == "CPU")
		{
			choice = new CPU(0, 0, "");
			std::cout << choice->getVar() << std::endl;
			
		}
		else if (aux == "GPU")
		{
			choice = new GPU("0x0", OpenGL);
			std::cout << choice->getVar() << std::endl;

		}
		else if (aux == "APU")
		{
			choice = new APU();
			std::cout << choice->getVar() << std::endl;
		}

		choice->setName(iterate(line, i, 'W'));
		fout << choice->getName() << " ";

		choice->setWeight(std::stoi(iterate(line, i, 'g')));
		fout << choice->getWeight() << " ";

		choice->setHeight(std::stof(iterate(line, i, 'm')));
		fout << choice->getHeight() << " ";

		choice->setTDP(std::stoi(iterate(line, i, 'W')));
		fout << choice->getTDP() << " ";

		choice->setMemory(std::stoi(iterate(line, i, ' ')));
		fout << choice->getMemory() << " ";

		choice->setNms(std::stoi(iterate(line, i, 'M')));
		fout << choice->getNms() << " ";
		
		choice->setFrequency(std::stof(iterate(line, i, 'M')));
		fout << choice->getFrequency() << " ";

		if (aux == "CPU" || aux == "APU")
		{
			choice->setCores(std::stoi(iterate(line, i, 'T')));
			fout << choice->getCores() << " ";

			choice->setThreads(std::stoi(iterate(line, i, 'S')));
			fout << choice->getThreads() << " ";

			choice->setSocket(iterate(line, i, ' '));
			fout << choice->getSocket() << std::endl << std::endl;

		}

		if (aux == "GPU" || aux == "APU")
		{
			choice->setMaxRes(iterate(line, i, ' '));
			fout << choice->getSocket() << std::endl;

			choice->setTech(stringToEnum(iterate(line, i, ' ')));
			fout << choice->getMaxRes() << std::endl << std::endl;

		}
		break;
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


Login::Login()
{
}

User* Login::isLoggedIn()
{
	std::string usr;
	std::string pw;
	std::string rol;
	std::string username;
	std::string password;
	User* u = nullptr;

	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;

	std::ifstream fin;
	std::ofstream fout;
	fout.open("users.txt", std::ios::app);

	if (isEmpty(fin))
	{
		fout << "Tavi" << std::endl;
		fout << "pass" << std::endl;
		fout << "admin" << std::endl << std::endl;
		fout.close();
	}
	fin.open("users.txt");

	while (fin)
	{
		getline(fin, usr);
		getline(fin, pw);

		if (usr == username && pw == password)
		{
			getline(fin, rol);
			if (rol == "client")
			{
				u = new Client(usr, pw);

			}
			else
				u = new Admin(usr, pw);
			fin.close();
			return u;
		}
		
		//rol
		getline(fin, usr);
		
	   //	spatiu
		getline(fin, usr);
	}

	fin.close();
	return u;

}


void Login::start()
{
	int option;

	std::cout << "1: Register\n2: Login\n3: Exit\nYour option: ";
	std::cin >> option;
	if (option == 1)
	{
		std::string user, pass;
		std::cout << "Select your username: ";
		std::cin >> user;
		std::cout << "Select your password: ";
		std::cin >> pass;

		std::ofstream fout;
		// file.open("data\\" + username + "txt")'
		fout.open("users.txt", std::ios::app);
		fout << user << std::endl << pass << std::endl;
		fout << "client" << std::endl << std::endl;
		fout.close();
	}

	else if (option == 2)
	{
		User* u = isLoggedIn();

		if (u == nullptr)
		{
			std::cout << "Failed to log in :(" << std::endl;
		}
		else
		{
			std::cout << "Logged in successfully :)" << std::endl;

			if (u->role == client)
			{
				std::cout << "client on" << std::endl;
				//metode pt client
			}
			else if (u->role == admin)
			{
				std::cout << "admin on" << std::endl;
				// metode pt admin
			}
		}
	}
}