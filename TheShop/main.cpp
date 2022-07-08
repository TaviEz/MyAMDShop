#include <iostream>
#include "Header.h"
#include "User.h"
using namespace std;

int main()
{
	User u("tavi", "messi", client);
	cout << u.username << " " << u.password << " " << ToString(u.role) << endl;

	Admin a("Tavi", "secret");
	cout << a.username << " " << a.password << " " << ToString(a.role) << endl;

	GPU g("1920x1080", OpenGL, "RX 6600", 813.2, 107, 65, 7, 8, 2100);
	CPU c(6, 12, "AM4", "Ryzen 7");
	Product p("Produs", 20.5, 10, 65, 7, 8, 1.85);

	//a.addProduct(g);
	


	Product* p1 = new GPU("1920x1080", DirectX, "RX 6600");
	cout << typeid(*p1).name() << endl;
}