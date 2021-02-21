#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Product.h"
#include<string>
class Dress : public Product
{
	int size;
	string brand;
	string model;
	string colour;
//	Type type;

public:
	Dress();
	Dress(int _itemCode, float _price, int _quantity, int _size, const string& _brand, const string& _model, const string& _colour);

	//getters
	int getSize() const;
	const string& getBrand() const;
	const string& getModel() const;
	const string& getColour() const;

	//setters
	void setSize(int _size);
	void setBrand(const string& _brand);
	void setModel(const string& _model);
	void setColour(const string& _colour);

	Product* clone() const override;
	virtual void print() const override; 
	const string getTypeOfProduct()const; //function to get the Type of the product

	friend istream& operator>>(istream& _istream, Dress& _product);
	friend ostream& operator<<(ostream& _ostream, const Dress& _product);
};

