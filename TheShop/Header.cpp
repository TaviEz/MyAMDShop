#include "Header.h"

Product::Product()
{
}

Product::Product(float weight, int height, int TDP, int nms, int memory, float frequency)
{
	this->weight = weight;
	this->height = height;
	this->TDP = TDP;
	this->nms = nms;
	this->memory = memory;
	this->frequency = frequency;
}

float Product::getWeight()
{
	return weight;
}

int Product::getHeight()
{
	return height;
}

int Product::getTDP()
{
	return TDP;
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

CPU::CPU(int cores, int threads, std::string socket, float weight, int height, int TDP, int nms, int memory, float frequency) : Product(weight, height, TDP, nms, memory, frequency)
{
	this->cores = cores;
	this->threads = threads;
	this->socket = socket;
}

int CPU::getCores()
{
	return cores;
}

int CPU::getThreads()
{
	return threads;
}

std::string CPU::getSocket()
{
	return socket;
}

GPU::GPU()
{
}

GPU::GPU(std::string maxRes, Technology tech, float weight, int height, int TDP, int nms, int memory, float frequency): Product(weight, height, TDP, nms, memory, frequency)
{
	this->maxRes = maxRes;
	this->tech = tech;
}

std::string GPU::getMaxRes()
{
	return maxRes;
}

Technology GPU::getTech()
{
	return tech;
}

APU::APU()
{
}

APU::APU(float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket, std::string maxRes, Technology tech) : Product(weight, height, TDP, nms, memory, frequency), CPU(cores, threads, socket), GPU(maxRes, tech)
{
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