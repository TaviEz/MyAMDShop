# AMD Shop

**About**

This project is a CRUD(create read update delete) app made for the console and written in C++.
As the name says the app is basically a shop where clients can register and order their favourite AMD products.

**What are the availabile type of products in the app?**

There are 3 types of products: **CPU**, **GPU** and **APU**.
Every type of product have a series of specifications: *weight, height, TDP, nms, memory and clock frequency.*

The **CPU** will have a number of cores and threads, a socket.
The **GPU** will have a maximum resolution and support for different version of technologies.
(OpenGL, DirectX);
The **APU** basically merges a CPU and a GPU in only one product.

**How the app works?**
First of all I created a login form where you can either register or login or to quit the app.
POZA 1?


In my project I opted for txt files to serve as databases. 
The databases that I created are used for: the inventory of the app, the list of users and every user's shopping cart.
For this example I stored  the name, the password and the function of every user that is registered in this app in the "users.txt" file.
If there are no users I automatically added myself as an admin in order to login.


There are 2 types of users: clients and admins.
Every type of user has the same starting menu after logging in.
POZA 2


1) Add items

In case of adding an item, the user can add it either in his shopping cart, either in the inventory of the app, depending on his role.
The UI is simillar, it is only differentiated by the location where we want to add the item.

POZE 3

After that, the user is asked how many products does he want to add and then the user must provide in the console the type of the product he wants (i.e: CPU) and the name of it (i.e. Ryzen 5).

POZA 4
In case of an admin he must provide all the specifications of the product.

POZA 5

If there is no such product it will be displayed an error in the console.


2) Delete Items
The process is quite simillar. The user chooses again which product he wants to remove then then the deletion will be complete.
Afterwards he is asked if the wants to see the inventory so he can see the product that he wanted to remove is no longer in the shopping cart or in the inventory.

3) Add admin
Is availabile only for the users that have the admin role.
They can change the role for the clients into admins.

POZA 7

