#pragma once
#include <string>
#include <string>

enum Technology { OpenGL = 1, DirectX = 2 };
const char* ToString(Technology t);

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
	Product(std::string name, float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0.0);

	std::string getName();
	void setName(std::string name);

	float getWeight();
	void setWeight(float weight);

	int getHeight();
	void setHeight(int height);

	int getTDP();
	void setTDP(int TDP);

	int getNms();
	void setNms(int nms);

	int getMemory();
	void setMemory(int memory);

	float getFrequency();
	void setFrequency(float frequency);

	virtual int getCores() = 0;
	virtual void setCores(int cores) = 0;

	virtual int getThreads() = 0;
	virtual void setThreads(int threads) = 0;

	virtual std::string getSocket() = 0;
	virtual void setSocket(std::string socket) = 0;

	virtual std::string getMaxRes() = 0;
	virtual void setMaxRes(std::string maxRes) = 0;

	virtual Technology getTech() = 0;
	virtual void setTech(Technology tech) = 0;

	virtual std::string getVar() = 0;
};

class CPU : virtual public Product
{
protected:
	int cores;
	int threads;
	std::string socket;

public:
	CPU();
	CPU(int cores, int threads, std::string socket, std::string name = "", float weight = 0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0.0);

	int getCores() override;
	void setCores(int cores) override;

	int getThreads() override;
	void setThreads(int threads) override;

	std::string getSocket() override;
	void setSocket(std::string socket) override;

	std::string getMaxRes() override;
	void setMaxRes(std::string maxRes) override;

	Technology getTech() override;
	void setTech(Technology tech) override;

	std::string getVar() override;
};

class GPU : virtual public Product
{
protected:
	std::string maxRes;
	Technology tech;

public:
	GPU();
	GPU(std::string maxRes, Technology tech, std::string name = "", float weight = 0.0, int height = 0, int TDP = 0, int nms = 0, int memory = 0, float frequency = 0.0);

	int getCores() override;
	void setCores(int cores) override;

	int getThreads() override;
	void setThreads(int threads) override;

	std::string getSocket() override;
	void setSocket(std::string socket) override;

	std::string getMaxRes() override;
	void setMaxRes(std::string maxRes) override;

	Technology getTech() override;
	void setTech(Technology tech) override;

	std::string getVar() override;
};

class APU: public CPU, public GPU
{
public:
	APU();
	APU(std::string name, float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket, std::string maxRes, Technology tech);

	int getCores() override;
	void setCores(int cores) override;

	int getThreads() override;
	void setThreads(int threads) override;

	std::string getSocket() override;
	void setSocket(std::string socket) override;

	std::string getMaxRes() override;
	void setMaxRes(std::string maxRes) override;

	Technology getTech() override;
	void setTech(Technology tech) override;

	std::string getVar() override;

};



