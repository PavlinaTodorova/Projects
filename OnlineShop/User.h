#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Cart.h"
#include<string>

class User
{
	string userName;
	string password;
	string address;
	Cart cart;

public:
	User();
	User(const string& _userName, const string& _password, const string& _address);

	//getters
	const string& getUserName() const;
	const string& getAddress() const;
	const string& getPassword() const;

	//setters
	void setUserName(const string& _userName);
	void setPassword(const string& _password);
	void changePassword(const string& oldpassword, const string& newpassword); //Function that change the password. We enter the present password and the new password.
	void setAddress(const string& _address);

	void addToCart(Product* productToAdd);
	void removeFromCart();
	void printCart() const;

	void showInfoUser() const; //User Information

	friend istream& operator>>(istream& _ostream, User& _product);
	friend ostream& operator<<(ostream& _ostream, const User& _product);
	
};

