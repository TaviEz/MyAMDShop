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

CPU::CPU()
{
}

CPU::CPU(float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket) : Product(weight, height, TDP, nms, memory, frequency)
{
}

GPU::GPU()
{
}

GPU::GPU(float weight, int height, int TDP, int nms, int memory, float frequency, std::string maxRes, Technology tech): Product(weight, height, TDP, nms, memory, frequency)
{
}

APU::APU()
{
}

APU::APU(float weight, int height, int TDP, int nms, int memory, float frequency, int cores, int threads, std::string socket, std::string maxRes, Technology tech) : CPU(cores, threads, socket), GPU(maxRes, tech)
{
}
