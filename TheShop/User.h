#pragma once
#include <string>
#include "Header.h"
#include <fstream>


enum Role { admin = 1, client = 2 };
const char* ToString(Role r);

class User
{
private:
	int _id;
	std::string username;
	std::string password;
	Role role;
public:
	User();
	User(std::string username, std::string password, Role role);
	
	std::string getUsername();
	std::string getPassword();
	
	Role getRole();
	void setRole(Role r);

	virtual void addProduct() = 0;
	virtual void addAdmin() = 0;
};

class Admin : public User
{
public:
	Admin();
	Admin(std::string username, std::string password, Role role = admin);

	void addProduct() override;
	void addAdmin() override;
	int printUsers();
};

class Client : public User
{
public:
	Client();
	Client(std::string username, std::string password, Role role = client);

	void addProduct() override;
	void addAdmin() override;
};

const Technology stringToEnum(std::string str);

void delete_line(std::string file_name, std::string line);

std::string iterate(std::string line, int& i, char c);

void printFile(User* u, std::string choice);

void removeProduct(std::string file_name);

std::string selectType(std::string line);

void replace_line(const char* file_name, std::string line, std::string str);

void pressEnter();


class Login
{
public:
	Login();

	User* isLoggedIn();

	void start();

};

const Role stringToEnum2(std::string str);

bool isEmpty(std::ifstream& pFile);





