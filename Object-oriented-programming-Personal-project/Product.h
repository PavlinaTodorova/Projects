#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Product
{
public:
	//we have 3 types of products
	enum class Type {
		chocolate,
		dress,
		phone
	};

protected:
	int itemCode;
	float price;
	int quantity;
	Type type;

public:
	Product();
	Product(int _itemCode, float _price, int _quantity);

	virtual Product* clone() const = 0; 

	//getters
	int getItemCode() const;
	float getPrice() const;
	int getQuantity() const;
	//Product::Type getType() const;

	//setters
	void setItemCode(int _itemCode);
	void setPrice(float _price);
	void setQuantity(int _quantity);

	virtual void print() const;

	friend istream& operator>>(istream& _istream, Product& _product);
	friend ostream& operator<<(ostream& _ostream, const Product& _product);
};



