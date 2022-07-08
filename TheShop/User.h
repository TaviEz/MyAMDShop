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
};

class Admin : public User
{
public:
	Admin();
	Admin(std::string username, std::string password, Role role = admin);

	void addProduct(Product& p);
};
