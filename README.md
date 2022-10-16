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

![image1](https://user-images.githubusercontent.com/100527261/196040823-b092402a-4808-4a22-945e-aca483fa353d.png)


In my project I opted for txt files to serve as databases. 
The databases that I created are used for: the inventory of the app, the list of users and every user's shopping cart.
For this example I stored  the name, the password and the function of every user that is registered in this app in the "users.txt" file.
If there are no users I automatically added myself as an admin in order to login.


There are 2 types of users: clients and admins.
Every type of user has the same starting menu after logging in.

![image2](https://user-images.githubusercontent.com/100527261/196040861-2ae5847f-820b-45f1-bbbf-da6aef1a1876.png)


**Adding items**

In case of adding an item, the user can add it either in his shopping cart, either in the inventory of the app, depending on his role.
The UI is simillar, it is only differentiated by the location where we want to add the item.

![image3](https://user-images.githubusercontent.com/100527261/196040969-f4531cba-4f95-44f9-aff9-e5b7a0fdafe0.png)

After that, the user is asked how many products does he want to add and then the user must provide in the console the type of the product he wants (i.e: CPU) and the name of it (i.e. Ryzen 5).

![image4](https://user-images.githubusercontent.com/100527261/196040997-7f445fa8-7de6-4d46-ae8e-62afc4afcd71.png)

In case of an admin he must provide all the specifications of the product.

![image5](https://user-images.githubusercontent.com/100527261/196041027-3dcf43a7-80fc-4f9b-b2dc-c90476f42602.png)

If there is no such product it will be displayed an error in the console.


**Delete Items**

The process is quite simillar. The user chooses again which product he wants to remove then then the deletion will be complete.
Afterwards he is asked if the wants to see the inventory so he can see the product that he wanted to remove is no longer in the shopping cart or in the inventory.

![image6](https://user-images.githubusercontent.com/100527261/196041097-2e132df0-b39a-4330-aa04-7e2eee937b3b.png)

**Add admin**

Is availabile only for the users that have the admin role.
They can change the role for the clients into admins.

![image7](https://user-images.githubusercontent.com/100527261/196041132-5c5ec956-6d83-4a8b-b212-5b1edba1165e.png)

