#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	Product p(20.5, 10, 65, 7, 8, 1.85);

	CPU c(6, 12, "AM4");

	GPU g("1920x1080", OpenGL);

	cout << p.getFrequency() << " " << c.getCores() << c.getFrequency() << endl;
	cout << g.getMaxRes() << " " << ToString(g.getTech()) << " " << g.getWeight() << endl;
}