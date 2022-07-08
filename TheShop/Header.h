#pragma once
#include <string>
#include <string>

class Product
{
protected:
	std::string name;
	float weight;
	int height;
	int TDP;
	int nms;
	int memory;
	float frequency;

public:
	Product();
	Product(std::string name, float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0);

	std::string getName();
	float getWeight();
	int getHeight();
	int getTDP();
	int getNms();
	int getMemory();
	float getFrequency();
};

class CPU : virtual public Product
{
protected:
	int cores;
	int threads;
	std::string socket;

public:
	CPU();
	CPU(int cores, int threads, std::string socket, std::string name = "", float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0);

	int getCores();
	int getThreads();
	std::string getSocket();
};

enum Technology { OpenGL = 1, DirectX = 2 };

const char* ToString(Technology t);

class GPU : virtual public Product
{
protected:
	std::string maxRes;
	Technology tech;

public:
	GPU();
	GPU(std::string maxRes, Technology tech, std::string name = "", float weight = 0.0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0.0);

	std::string getMaxRes();
	Technology getTech();
};

class APU: public CPU, public GPU
{
public:
	APU();
	APU(std::string name, float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket, std::string maxRes, Technology tech);
};



