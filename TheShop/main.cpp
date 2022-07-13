#include <iostream>
#include "Header.h"
#include "User.h"
using namespace std;

int main()
{
	/*Product* p1 = new GPU("1920x1080", OpenGL, "RX 6600", 813.2, 107, 65, 7, 8, 2100);
	Product* p2 = new CPU(6, 12, "AM4", "Ryzen 7", 20, 100, 60, 7, 8, 4000);
	Product* p3 = new APU("APU1", 813.2, 107, 65, 7, 8, 2100, 6, 12, "AM4", "1920x1080", DirectX);*/

	User* a1 = new Admin("user", "parola");
	/*a1->addProduct();
	a1->addProduct();*/
	//a1->addAdmin();



	/*User* c = new Client("Client1", "parola");
	c->addProduct();*/

	Login l;
	l.start();
}