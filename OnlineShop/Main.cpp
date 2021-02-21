#include <iostream>
#include <string>
#include "Product.h"
#include "OnlineShop.h"
#include "User.h"
#include "Cart.h"
#include"Chocolate.h"

using namespace std;

int main()
{
	
	cout << "Wellcome to the New Onlineshop PavliExpress :)" << endl << endl;
	OnlineShop PavliExpress;

	Chocolate Milka(100, 2.50, 1, "Milka", 100);
	Chocolate Lindor(200, 5, 1, "Lindor", 100);
	Dress littleBlack(300, 88, 1, 38, "Guess", "Little Black dress", "black");
	Phone SmartPhone(400, 750, 1, "Samsung", "A52017", 56);

	Product* ptr100 = &Milka;
	Product* ptr200 = &Lindor;
	Product* ptr300 = &littleBlack;
	Product* ptr400 = &SmartPhone;

	PavliExpress.addItem(ptr100);
	PavliExpress.addItem(ptr200);
	PavliExpress.addItem(ptr300);
	PavliExpress.addItem(ptr400);

	cout << "login for employee -> enter E" << endl;
	cout << "login for user -> enter U " << endl;
	char symbol;
	cin >> symbol;

	if (symbol == 'e' || symbol== 'E')
	{
		User Employee;
		cin >> Employee;
		cout << endl;
		cout << "Login successful" << endl << endl;
		while (true)
		{
			cout << "Choose an option: " << endl;
			cout << "A Add new product in Shop" << endl;
			cout << "R Remove product in Shop" << endl;
			cout << "D Display products in Shop" << endl;
			cout << "F Filter products by price" << endl;
			cout << "V View Employee Information" << endl;
			cout << "P Change your password" << endl;
			cout << "Q Quit" << endl;

			cout << endl;
			char symbol;
			cin >> symbol;
			switch (symbol)
			{
			case 'A': case 'a':
			{
				cout << "Now you can choose one of these products: " << endl << "1: Chocolate " << endl << "2: Dress " << endl << "3: Phone " << endl;
				cout << "Enter the number of product: ";
				int num;
				cin >> num;
				if (num == 1)
				{
					Chocolate newProduct;
					cin >> newProduct;
					Product* ptr = &newProduct;
					PavliExpress.addItem(ptr);
				}
				else if (num == 2)
				{
					Dress newProduct;
					cin >> newProduct;
					Product* ptr = &newProduct;
					PavliExpress.addItem(ptr);
				}
				else if (num == 3)
				{
					Phone newProduct;
					cin >> newProduct;
					Product* ptr = &newProduct;
					PavliExpress.addItem(ptr);
				}
				else cout << "Wrong number";
				break;
					
			}
			case 'R': case 'r':
			{
				int index;
				PavliExpress.print();
				cout << "Enter index (only digit) of the product you want to delete: " << endl;
				cin >> index;
				PavliExpress.removeItem(index);
				break;
			}
			case 'D': case 'd':
			{
				PavliExpress.print();
				break;
			}
			case 'F': case 'f':
			{
				cout << "Filter By Price " << endl;
				float lowestPrice, highestPrice;
				cout << "Enter lowest limit: ";
				cin >> lowestPrice;
				cout << endl;
				cout << "Enter highest limit: ";
				cin >> highestPrice;
				cout << endl;
				PavliExpress.filterByPrice(lowestPrice, highestPrice);
				break;

			}
			case 'V': case 'v':
			{
				Employee.showInfoUser();
				cout << endl;
				break;
			}
			case 'P': case 'p':
			{
				cout << "Enter the old password: " << endl;
				string oldpass;
				cin >> oldpass;
				cout << endl;
				cout << "Enter the new password: " << endl;
				string newpass;
				cin >> newpass;
				Employee.changePassword(oldpass, newpass);
				cout << endl;
				break;
			}
			case 'Q': case 'q': return 0;
			default:
				return 0;
			}
			cout << endl;
		}


	}
	else if (symbol == 'u' || symbol == 'U')
	{
		User person;
		cin >> person;
		cout << endl;
		Cart ShoppingCart;
		cout << "Login successful" << endl << endl;

		while (true)
		{
			cout << "Choose an option: " << endl;
			cout << "A Add new product in Cart" << endl;
			cout << "R Remove product in Cart" << endl;
			cout << "D Display products in Cart" << endl;
			cout << "V View User Information" << endl;
			cout << "P Change your password" << endl;
			cout << "Q Quit" << endl;

			cout << endl;
			char symbol;
			cin >> symbol;
			switch (symbol)
			{
			case 'A': case 'a':
			{
				cout << endl << "MENU (Now you can choose one of these products): " << endl << endl;
				PavliExpress.print();
				cout << "Enter the index of product you choose: " << endl;
				int index;
				cin >> index;
				ShoppingCart.addItem(PavliExpress.getProduct(index));
				break;
			}
			case 'R': case 'r':
			{
				int index;
				ShoppingCart.print();
				cout << "Enter index (only digit) of the product you want to remove: " << endl;
				cin >> index;
				ShoppingCart.removeItem(index);
				break;
			}
			case 'D': case 'd':
			{
				ShoppingCart.print();
				break;
			}
			case 'V': case 'v':
			{
				person.showInfoUser();
				cout << endl;
				break;
			}
			case 'P': case 'p':
			{
				cout << "Enter the old password: " << endl;
				string oldpass;
				cin >> oldpass;
				cout << endl;
				cout << "Enter the new password: " << endl;
				string newpass;
				cin >> newpass;
				person.changePassword(oldpass, newpass);
				cout << endl;
				break;
			}
			case 'Q': case 'q': return 0;
			default:
				return 0;
			}
			cout << endl;
		}

	}
	else
	{
		cout << "invalid character, try again later! Have a nice day! :)" << endl;
		cout << endl;
	}


	system("pause");
	return 0;

}