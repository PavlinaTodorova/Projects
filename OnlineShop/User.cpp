#include "User.h"
#include<string>
#include<iostream>
using namespace std;



User::User()
{
	setUserName("");
	setPassword("");
	setAddress("");
}

User::User(const string& _userName, const string& _password, const string& _address)
{
	setUserName(_userName);
	setPassword(_password);
	setAddress(_address);
}

const string& User::getUserName() const
{
	return userName;
}

const string& User::getPassword() const
{
	return password;
}

const string& User::getAddress() const
{
	return address;
}

void User::setUserName(const string& _userName)
{
	userName = _userName;
}

void User::setPassword(const string& _password)
{
	password = _password;
	for (int i = 0; i < _password.length(); i++)
	{
		password[i] += 2; //here I use something like a script (-2) to make it harder to break into the system and access personal data
	}
}

void User::changePassword(const string& oldpassword, const string& newpassword)
{
	for (int i = 0; i < oldpassword.length(); i++)
	{
		password[i] -= 2; //remove script
	}

	if (password.compare(oldpassword) != 0)
	{
		for (int i = 0; i < oldpassword.length(); i++)
		{
			password[i] += 2;
		}
		cout << "Invalid Password!" << endl;
	}
	else
	{
		password = newpassword;
		for (int i = 0; i < newpassword.length(); i++)
		{
			password[i] += 2;
		}
	}

}

void User::setAddress(const string& _address)
{
	address = _address;
}

void User::addToCart(Product * productToAdd)
{
	cart.addItem(productToAdd);
}

void User::removeFromCart()
{
	cout << "Enter the index of the product in cart to remove from cart: ";
	int index;
	cin >> index;
	cart.removeItem(index);
}

void User::printCart() const
{
	cart.print();
}


void User::showInfoUser() const
{
	cout << "userName:" << getUserName() << endl;
	cout << "password:" << getPassword() << endl;
	cout << "adress:" << getAddress() << endl;
}

istream & operator>>(istream & _istream, User & _user)
{
	char buffer[500];
	cout << "UserName: ";
	_istream >> buffer;
	_user.setUserName(buffer);
	cout << "Password: ";
	_istream >> buffer;
	_user.setPassword(buffer);
	cout << "Address: ";
	_istream >> buffer;
	_user.setAddress(buffer);
	return _istream;
}

ostream & operator<<(ostream & _ostream, const User & _user)
{
	_ostream << "UserName: " << _user.getUserName() << endl;
	_ostream << "Password: " << _user.getPassword() << endl;
	_ostream << "Address: " << _user.getAddress() << endl;
	return _ostream;
}