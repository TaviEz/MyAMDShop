#include <iostream>
#include "Header.h"
#include "User.h"
using namespace std;

int main()
{
	/*CPU c(6, 12, "AM4", "Ryzen 7");
	Product p("Produs", 20.5, 10, 65, 7, 8, 1.85);*/

	/*GPU g("1920x1080", OpenGL, "RX 6600", 813.2, 107, 65, 7, 8, 2100);
	cout << typeid(g).name() << " ";*/
	//a.addProduct(&g);

	Product* p1 = new GPU("1920x1080", OpenGL, "RX 6600", 813.2, 107, 65, 7, 8, 2100);
	Product* p2 = new CPU(6, 12, "AM4", "Ryzen 7", 20, 100, 60, 7, 8, 4000);
	Product* p3 = new APU("APU1", 813.2, 107, 65, 7, 8, 2100, 6, 12, "AM4", "1920x1080", DirectX);

	User* a1 = new Admin("user", "parola");
	a1->addProduct(p2);
	a1->addProduct(p1);
	a1->addProduct(p3);

	User* c = new Client("Client1", "parola");
	c->selectProduct();

	Login l;
	l.start();

	//delete_line("users.txt", 2);
	
}