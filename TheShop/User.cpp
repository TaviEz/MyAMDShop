#include "User.h"
#include <iostream>
#include <string>
#include <map>
#include <boost/assign/list_of.hpp>
#include <boost/assert.hpp>
#include <chrono>
#include <thread>

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

void delete_line(std::string file_name, std::string deleteLine)
{
	std::ifstream fin;

	std::ofstream fout;
	std::string line;

	fin.open(file_name);
	fout.open("temp.txt", std::ofstream::out);

	while (getline(fin, line))
	{
		if (line != deleteLine)
		{
			fout << line << std::endl;
		}
	}

	fout.close();
	fin.close();

	const char* p = file_name.c_str();
	remove(p);
	rename("temp.txt", p);
}

std::string iterate(std::string line, int& i, char a, char b)
{
	{
		std::string aux = "";

		while (line[i] != a)
			i++;

		i += 2;
		while (line[i] != b)
		{
			aux += line[i];
			i++;
		}

		return aux;
	}
}

void printFile (User* u, std::string choice)
{
	bool ans;
	int ok = 0;

	if(choice == "inv")
		std::cout << "Do you want to see the inventory? \n1 - Yes\n0 - No\nYour choice: ";
	else if(choice == "cart")
		std::cout << "Do you want to see the shopping cart? \n1 - Yes\n0 - No\nYour choice: ";

	std::cin >> ans;
	std::cout << std::endl;
	system("cls");
	if (ans == true)
	{
		std::string line;
		std::ifstream fin;

		if (choice == "inv")
		{
			fin.open("listaProduse.txt");
		}
		else if (choice == "cart")
		{
			fin.open(u->getUsername() + ".txt");
		}

		while (fin)
		{
			getline(fin, line);
			if (line != "")
			{
				ok = 1;
				std::cout << line << std::endl << std::endl;
			}
		}

		if (ok == 0)
		{
			if (choice == "inv")
				std::cout << "The inventory is empty";
			else if (choice == "cart")
				std::cout << "Your shopping cart is empty";
		}
		else
			std::cout << std::endl;

		fin.close();
	}
}


void removeProduct(std::string file_name)
{

	std::ifstream fin;
	std::string type = "";
	std::string name;
	std::string line;
	std::string aux;
	int ok = 0;
	
	while (type != "CPU" && type != "GPU" && type != "APU")
	{
		std::cout << "What type of product do you want to remove? (CPU/APU/GPU) ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, type);
		if (type != "CPU" && type != "GPU" && type != "APU")
			std::cout << "Error! Please choose a product from the following list: CPU, GPU, APU\n";
	}

	std::cout << "\nThe " << type << " you want to remove is: ";
	getline(std::cin, name);

	fin.open(file_name);

	while (fin)
	{
		
		getline(fin, line);
		if (line == "")
			continue;

		int i;
		aux = "";
		for (i = line.find_first_of("s") + 3; i < line.find_first_of("U") + 1; i++)
			aux += line[i];


		if (aux == type)
		{
			aux = iterate(line, i, ':', 'W');
			aux.pop_back();

			if (aux == name)
			{
				ok = 1;
				std::cout << "Deleting your product...";
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				fin.close();
				delete_line(file_name, line);
				std::cout << "Product removed" << std::endl;
				break;
			}
		}
		else
			continue;
	}
	if (ok == 0)
		std::cout << "Product doesn't exist.\n";

	fin.close();
}

void replace_line(const char* file_name, std::string replaceLine, std::string str)
{
	std::ifstream fin;
	std::ofstream fout;
	std::string line;

	fin.open(file_name);
	fout.open("temp.txt", std::ofstream::out);

	while (getline(fin, line))
	{
		if (line == replaceLine)
		{
			//name
			fout << line << std::endl;
			// password
			getline(fin, line);
			fout << line << std::endl;
			//role
			getline(fin, line);
			fout << str << std::endl << std::endl;
		}
		else
		{
			fout << line << std::endl;
		}
	}

	fin.close();
	fout.close();
	remove(file_name);
	rename("temp.txt", file_name);
}

void pressEnter()
{
	std::cout << "Press Enter to Continue: ";
	std::cin.ignore();
	system("cls");
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

std::string User::getUsername()
{
	return this->username;
}

std::string User::getPassword()
{
	return this->password;
}

Role User::getRole()
{
	return this->role;
}

void User::setRole(Role r)
{
	this->role = r;
}

Admin::Admin()
{
	//role = admin;
	this->setRole(admin);
}

Admin::Admin(std::string username, std::string password, Role role) : User(username, password, role)
{
}

void Admin::addProduct()
{
	std::ofstream fout;
	std::string type = "";
	Product* p = nullptr;
	std::string name;
	float weight;
	int height;
	int TDP;
	int nms;
	int memory;
	float frequency;
	int cores;
	int threads;
	std::string socket;
	std::string maxRes;
	std::string tech;

	fout.open("listaProduse.txt", std::ios::app);

	while (type != "CPU" && type != "GPU" && type != "APU")
	{
		std::cout << "Type of product: (CPU, GPU, APU) ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, type);
		if (type != "CPU" && type != "GPU" && type != "APU")
			std::cout << "Error! Please choose a product from the following list: CPU, GPU, APU\n";
	}

	if (type == "CPU")
	{
		p = new CPU(0, 0, "");
	}
	else if (type == "GPU")
	{
		p = new GPU("0x0", OpenGL);
	}
	else if(type == "APU")
		p = new APU();

	fout << "Type of product: " << p->getVar() << " ";

	std::cout << "\nName: ";
	getline(std::cin, name);
	p->setName(name);
	fout << "Name: " << p->getName() << " ";

	std::cout << "\nWeight: ";
	std::cin >> weight;
	p->setWeight(weight);
	fout << "Weight: " << p->getWeight() << " g" << " ";

	std::cout << "\nHeight: ";
	std::cin >> height;
	p->setHeight(height);
	fout << "Height: " << p->getHeight() << " mm" << " ";

	std::cout << "\nTDP: ";
	std::cin >> TDP;
	p->setTDP(TDP);
	fout << "TDP: " << p->getTDP() << " W" << " ";

	std::cout << "\nNms: ";
	std::cin >> nms;
	p->setNms(nms);
	fout << "Nms: " << p->getNms() << " ";

	std::cout << "\nMemory: ";
	std::cin >> memory;
	p->setMemory(memory);
	fout << "Memory: " << p->getMemory() << " ";

	if (p->getVar() == "class CPU")
		fout << "MB" << " ";
	else
		fout << "GB" << " ";

	std::cout << "\nFrequency: ";
	std::cin >> frequency;
	p->setFrequency(frequency);
	fout << "Frequency: " << p->getFrequency() << " MHz" << " ";
	
	if (p->getVar() == "class CPU" || p->getVar() == "class APU")
	{
		std::cout << "\nCores: ";
		std::cin >> cores;
		p->setCores(cores);
		fout << "Cores: " << p->getCores() << " ";
		
		std::cout << "\nThreads: ";
		std::cin >> threads;
		p->setThreads(threads);
		fout << "Threads: " << p->getThreads() << " ";

		std::cout << "\nSocket: ";
		std::cin >> socket;
		p->setSocket(socket);
		fout << "Socket: " << p->getSocket() << " ";
	}

	if (p->getVar() == "class CPU")
	{
		fout << std::endl << std::endl;

	}

	if (p->getVar() == "class GPU" || p->getVar() == "class APU")
	{
		std::cout << "\nMaximum Resolution: (LengthxWidth): ";
		std::cin >> maxRes;
		p->setMaxRes(maxRes);
		fout << "MaximumResolution: " << p->getMaxRes() << " ";

		std::cout << "\nTechnology supported: ";
		std::cin >> tech;
		p->setTech(stringToEnum(tech));
		fout << "Technology supported: " << ToString(p->getTech()) << " " << std::endl << std::endl;
	}
	fout.close();
}

void Admin::addAdmin()
{
	std::ifstream fin;
	std::ofstream fout;
	std::string line;
	std::string name;
	int ok = 0;

	while (ok == 0)
	{
		if (printUsers()) // if there are clients in the file
		{
			std::cout << "\nChoose a client to be promoted: ";
			std::cin >> name;

			fin.open("users.txt");
			fout.open("users.txt", std::ios::app);
			while (fin)
			{
				getline(fin, line);
				if (line == name)
				{
					//pass
					getline(fin, line);

					//role
					getline(fin, line);
					fin.close();
					fout.close();
					replace_line("users.txt", name, "admin");
					std::cout << "Admin added " << std::endl;
					ok = 1;
					break;
				}
			}

			if (ok == 0)
				std::cout << "The client you were looking for doesn't exist.\nTry again.\n";
		}

		else // if there are no clients in the file then exit the loop
			ok = 1;
	}

	fin.close();
	fout.close();

}

int Admin::printUsers()
{
	std::ifstream fin;
	std::string name;
	std::string password;
	std::string role;
	int ok = 0;
	bool ans;

	std::cout << "Do you want to see the list of the clients?\n1 - Yes\n0 - No\nYour choice: ";
	std::cin >> ans;
	std::cout << std::endl;

	fin.open("users.txt");

	
	while (fin)
	{
		getline(fin, name);
		if (name == "")
			continue;
		getline(fin, password);
		getline(fin, role);

		if (role == "client")
		{
			if(ans == true)
				std::cout << name << std::endl;
			ok = 1;
		}
	}
	
	fin.close();
	if(ok == 0)
		std::cout << "There are no clients registered at the moment.\n";
	return ok;
}

Client::Client()
{
}

Client::Client(std::string username, std::string password, Role role): User(username, password, role)
{
}

void Client::addProduct()
{

	std::ifstream fin;
	std::ofstream fout;
	std::string line;
	std::string prev = "a";
	std::string aux;
	std::string type;
	std::string name;
	std::string file = this->getUsername();

	int size;
	Product* choice = nullptr;
	
	fin.open("listaProduse.txt");
	fout.open(file + ".txt", std::ios::app);

	std::cout << "Choose your type of product you want to buy: (CPU/GPU/APU) ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, type);

	std::cout << "Choose your " << type << ": ";
	getline(std::cin, name);

	while (fin)
	{
		getline(fin, line);
		if (line == "")
		{
			continue;
		}

		int i;

		aux = "";
		for (i = line.find_first_of("s") + 3; i < line.find_first_of("U") + 1; i++)
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

		std::string aux2 = iterate(line, i, ':', 'W');
		aux2.pop_back();
		choice->setName(aux2);

		if (aux == type && choice->getName() == name)
		{
			std::cout << "Yes we have it" << std::endl;
			fout << "Type of product: " << choice->getVar() << " ";
			fout << "Name: " << choice->getName() << " ";

			choice->setWeight(std::stoi(iterate(line, i, ':', 'g')));
			fout << "Weight: " << choice->getWeight() << " g ";

			choice->setHeight(std::stof(iterate(line, i, ':', 'm')));
			fout << "Height: " << choice->getHeight() << " mm ";

			choice->setTDP(std::stoi(iterate(line, i, ':', 'W')));
			fout << "TDP: " << choice->getTDP() << " W ";

			choice->setNms(std::stoi(iterate(line, i, ':', 'M')));
			fout << "Nms: " << choice->getNms() << " ";

			choice->setMemory(std::stoi(iterate(line, i, ':', ' ')));
			fout << "Memory: " << choice->getMemory();
			if (choice->getVar() == "class CPU")
				fout << " MB ";
			else
				fout << " GB ";

			choice->setFrequency(std::stof(iterate(line, i, ':', 'M')));
			fout << "Frequency: " << choice->getFrequency() << " " << "MHZ ";

			if (aux == "CPU" || aux == "APU")
			{
				choice->setCores(std::stoi(iterate(line, i, ':', 'T')));
				fout << "Cores: " << choice->getCores() << " ";

				choice->setThreads(std::stoi(iterate(line, i, ':', 'S')));
				fout << "Threads: " << choice->getThreads() << " ";

				choice->setSocket(iterate(line, i, ':', ' '));
				fout << "Socket: " << choice->getSocket() << " ";
			}

			if (aux == "CPU")
			{
				fout << std::endl << std::endl;
			}

			if (aux == "GPU" || aux == "APU")
			{
				choice->setMaxRes(iterate(line, i, ':', ' '));
				fout << "MaxRes: " << choice->getMaxRes() << " ";

				choice->setTech(stringToEnum(iterate(line, i, ':', ' ')));
				fout << "Technology supported: " << ToString(choice->getTech()) << std::endl << std::endl;
			}
			std::cout << "Item added to the cart" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(700));
			break;
		}
		prev = line;
	}
	fin.close();
	fout.close();
}

void Client::addAdmin()
{
	std::cout << "Warning! Entering restricted area" << std::endl;
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

	fin.open("users.txt");

	while (fin)
	{
		getline(fin, usr);
		if (usr == "")
			continue;
		getline(fin, pw);

		if (usr == username && pw == password)
		{
			getline(fin, rol);
			if (rol == "client")
			{
				u = new Client(usr, pw);
			}
			else if (rol == "admin")
			{
				u = new Admin(usr, pw);
			}

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
	std::ifstream fin;
	fin.open("users.txt");

	if (isEmpty(fin))
	{
		//add an admin if there are no users
		std::ofstream fout;
		fout.open("users.txt", std::ios::app);
		fout << "Tavi" << std::endl;
		fout << "pass" << std::endl;
		fout << "admin" << std::endl << std::endl;
		fout.close();
	}
	fin.close();

	int option = 0;
	while (option != 3)
	{
		system("cls");
		std::cout << "1: Register\n2: Login\n3: Exit\nYour option: ";
		std::cin >> option;

		if (option == 1)
		{
			std::string user, pass;
			std::cout << "Set an user and a password for your account" << std::endl;
			std::cout << "Select your username: ";
			std::cin >> user;
			std::cout << "Select your password: ";
			std::cin >> pass;

			std::ofstream fout;
			fout.open("users.txt", std::ios::app);
			fout << user << std::endl << pass << std::endl;
			fout << "client" << std::endl << std::endl;
			fout.close();
		}

		else if (option == 2)
		{
			User* u = isLoggedIn();
			int choice = 0;

			if (u == nullptr)
			{
				std::cout << "Failed to log in :(" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(700));
			}
			else
			{
				std::cout << "Logged in successfully :)" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(700));
				system("cls");
				while(choice != 4)
				{
					std::cout << "1) Add items" << std::endl;
					std::cout << "2) Delete items" << std::endl;
					std::cout << "3) Add admin" << std::endl;
					std::cout << "4) Log out" << std::endl;
					std::cout << "Your choice: ";
					std::cin >> choice;
					std::cout << "\n";

					if (u->getRole() == client)
					{
						//metode pt client
						if (choice == 1)
						{
							int n;
							printFile(u, "inv");
							std::cout << "How many products do you want to add in your shopping cart: ";
							std::cin >> n;
							for (int i = 0; i < n; i++)
							{
								u->addProduct();
							}
							system("cls");
							printFile(u, "cart");
							std::this_thread::sleep_for(std::chrono::milliseconds(5000));
							system("cls");
						}
						else if (choice == 2)
						{
							printFile(u, "cart");
							removeProduct(u->getUsername() + ".txt");
							std::this_thread::sleep_for(std::chrono::milliseconds(700));
							system("cls");
							printFile(u, "cart");
							std::this_thread::sleep_for(std::chrono::milliseconds(5000));
							system("cls");
						}
						else if (choice == 3)
						{
							u->addAdmin();
							std::this_thread::sleep_for(std::chrono::milliseconds(700));
							system("cls");
						}
					}
					else if (u->getRole() == admin)
					{
						// metode pt admin
						if (choice == 1)
						{
							int n;
							printFile(u, "inv");
							std::cout << "How many products do you want to add in the inventory: ";
							std::cin >> n;
							for (int i = 0; i < n; i++)
							{
								u->addProduct();
							}
							system("cls");
							printFile(u, "inv");
							std::this_thread::sleep_for(std::chrono::milliseconds(5000));
							system("cls");
						}
						else if (choice == 2)
						{
							printFile(u, "inv");
							removeProduct("listaProduse.txt");
							std::this_thread::sleep_for(std::chrono::milliseconds(700));
							system("cls");
							printFile(u, "inv");
							std::this_thread::sleep_for(std::chrono::milliseconds(5000));
							system("cls");
						}
						else if (choice == 3)
						{
							u->addAdmin();
							std::this_thread::sleep_for(std::chrono::milliseconds(700));
							system("cls");
						}
					}
				}
			}
		}
		else if (option == 3)
		{

			std::cout << "Exiting...";
			std::this_thread::sleep_for(std::chrono::milliseconds(700));
		}
		else
		{
			std::cout << "Please enter a number from 1 to 3";
			std::this_thread::sleep_for(std::chrono::milliseconds(700));
		}

		system("cls");
	}
}