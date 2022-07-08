#include <iostream>
#include "Header.h"
#include "User.h"
using namespace std;

int main()
{
	User u("tavi", "messi", client);
	//cout << u.username << " " << u.password << " " << ToString(u.role) << endl;

	//cout << a.username << " " << a.password << " " << ToString(a.role) << endl;

	/*CPU c(6, 12, "AM4", "Ryzen 7");
	Product p("Produs", 20.5, 10, 65, 7, 8, 1.85);*/

	Admin a("Tavi", "secret");
	GPU g("1920x1080", OpenGL, "RX 6600", 813.2, 107, 65, 7, 8, 2100);
	//a.addProduct(&g);

	User* a1 = new Admin("user", "parola");
	Product* p1 = new GPU("1920x1080", OpenGL, "RX 6600", 813.2, 107, 65, 7, 8, 2100);
	a.addProduct(p1);
}