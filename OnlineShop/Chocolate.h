#pragma once
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include"Product.h"
class Chocolate: public Product
{
	string name;
	double grams;
//	Type type;

public: 
	Chocolate();
	Chocolate(int _itemCode, float _price, int _quantity, const string& _name, double _grams);

	//getters
	const string& getName() const;
	double getGrams() const;

	//setters
	void setName(const string& _name);
	void setGrams(double _grams);

	Product* clone() const override;
	virtual void print() const override;
	const string getTypeOfProduct() const; //function to get the Type of the product

	friend istream& operator>>(istream& _istream, Chocolate& _product);
	friend ostream& operator<<(ostream& _ostream, const Chocolate& _product);

};

