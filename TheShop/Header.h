#pragma once
#include <string>

class Product
{
protected:
	float weight;
	int height;
	int TDP;
	int nms;
	int memory;
	float frequency;

public:
	Product();
	Product(float weight, int height, int TDP, int nms, int memory, float frequency);
};

class CPU : virtual public Product
{
protected:
	int cores;
	int threads;
	std::string socket;

public:
	CPU();
	CPU(float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0, int cores = 0, int threads = 0, std::string socket = 0);
};

enum Technology { OpenGL, DirectX };

class GPU : virtual public Product
{
protected:
	std::string maxRes;
	Technology tech;

public:
	GPU();
	GPU(float weight, int height, int TDP, int nms, int memory, float frequency, std::string maxRes, Technology tech);
};

class APU: public CPU, public GPU
{
public:
	APU();
	APU(float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket, std::string maxRes, Technology tech);
};

enum Role {admin = 1, client = 2};

class User
{
	int ID;
	const char* username;
	const char* password;
	Role role;
};

class Admin : public User
{

};

