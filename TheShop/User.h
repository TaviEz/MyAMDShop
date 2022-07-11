#pragma once
#include <string>
#include "Header.h"
#include <fstream>


enum Role { admin = 1, client = 2 };
const char* ToString(Role r);

class User
{
public:
	int _id;
	std::string username;
	std::string password;
	Role role;
public:
	User();
	User(std::string username, std::string password, Role role);
	virtual void addProduct(Product* p) = 0;
	virtual void selectProduct() = 0;
};

class Admin : public User
{
public:
	Admin();
	Admin(std::string username, std::string password, Role role = admin);

	void addProduct(Product* p) override;
	void selectProduct();
};

class Client : public User
{
public:
	Client();
	Client(std::string username, std::string password, Role role = client);

	void selectProduct() override;
	void addProduct(Product* p) override;
};

const Technology stringToEnum(std::string str);

class Login
{
public:
	Login();

	User* isLoggedIn();

	void start();

};

const Role stringToEnum2(std::string str);

bool isEmpty(std::ifstream& pFile);





