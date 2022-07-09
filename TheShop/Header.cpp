#include "Header.h"
#include <typeinfo>
#include <iostream>

Product::Product()
{
}

Product::Product(std::string name, float weight, int height, int TDP, int nms, int memory, float frequency)
{
	this->name = name;
	this->weight = weight;
	this->height = height;
	this->TDP = TDP;
	this->nms = nms;
	this->memory = memory;
	this->frequency = frequency;
}

std::string Product::getName()
{
	return name;
}

void Product::setName(std::string name)
{
	this->name = name;
}

float Product::getWeight()
{
	return weight;
}

void Product::setWeight(float weight)
{
	this->weight = weight;
}

int Product::getHeight()
{
	return height;
}

void Product::setHeight(int height)
{
	this->height = height;
}

int Product::getTDP()
{
	return TDP;
}

void Product::setTDP(int TDP)
{
	this->TDP = TDP;
}

int Product::getNms()
{
	return nms;
}

int Product::getMemory()
{
	return memory;
}

float Product::getFrequency()
{
	return frequency;
}

CPU::CPU()
{
}

CPU::CPU(int cores, int threads, std::string socket, std::string name, float weight, int height, int TDP, int nms, int memory, float frequency) : Product(name, weight, height, TDP, nms, memory, frequency)
{
	this->cores = cores;
	this->threads = threads;
	this->socket = socket;
}

int CPU::getCores()
{
	return this->cores;
}

void CPU::setCores(int cores)
{
	this->cores = cores;
}

int CPU::getThreads()
{
	return this->threads;
}

void CPU::setThreads(int threads)
{
	this->threads = threads;
}

std::string CPU::getSocket()
{
	return this->socket;
}

void CPU::setSocket(std::string socket)
{
	this->socket = socket;
}

std::string CPU::getMaxRes()
{
	return std::string();
}

void CPU::setMaxRes(std::string maxRes)
{

}

Technology CPU::getTech()
{
	return Technology();
}

void CPU::setTech(Technology tech)
{
}

std::string CPU::getVar()
{
	return typeid(*this).name();
}

GPU::GPU()
{
}

GPU::GPU(std::string maxRes, Technology tech, std::string name, float weight, int height, int TDP, int nms, int memory, float frequency): Product(name, weight, height, TDP, nms, memory, frequency)
{
	this->maxRes = maxRes;
	this->tech = tech;
}

int GPU::getCores()
{
	return 0;
}

void GPU::setCores(int cores)
{
}

int GPU::getThreads()
{
	return 0;
}

void GPU::setThreads(int threads)
{
}

std::string GPU::getSocket()
{
	return std::string();
}

void GPU::setSocket(std::string socket)
{
}

std::string GPU::getMaxRes()
{
	return this->maxRes;
}

void GPU::setMaxRes(std::string maxRes)
{
	this->maxRes = maxRes;
}

Technology GPU::getTech()
{
	return this->tech;
}

void GPU::setTech(Technology tech)
{
	this->tech = tech;
}

std::string GPU::getVar()
{
	return typeid(*this).name();
}


APU::APU()
{
}

APU::APU(std::string name, float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket, std::string maxRes, Technology tech) : Product(name, weight, height, TDP, nms, memory, frequency), CPU(cores, threads, socket), GPU(maxRes, tech)
{
}

int APU::getCores()
{
	return this->cores;
}

void APU::setCores(int cores)
{
	this->cores = cores;
}

int APU::getThreads()
{
	return this->threads;
}

void APU::setThreads(int threads)
{
	this->threads = threads;
}

std::string APU::getSocket()
{
	return this->socket;
}

void APU::setSocket(std::string socket)
{
	this->socket = socket;
}

std::string APU::getMaxRes()
{
	return this->maxRes;
}

void APU::setMaxRes(std::string maxRes)
{
	this->maxRes = maxRes;
}

Technology APU::getTech()
{
	return this->tech;
}

void APU::setTech(Technology tech)
{
	this->tech = tech;
}

std::string APU::getVar()
{
	return typeid(*this).name();
}



const char* ToString(Technology t)
{
	switch (t)
	{
	case OpenGL: return "OpenGL";
	case DirectX: return "DirectX";
	default: return "Unknown GPU tech";
	}
}

