#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Product.h"
#include <string>
class Phone: public Product
{
protected:
	string brand;
	string model;
	float batteryCapacity;
//	Type type;

public:
	Phone();
	Phone(int _itemCode, float _price, int _quantity, const string& _brand, const string& _model, float _batteryCapacity);

	//getters
	const string& getBrand() const;
	const string& getModel() const;
	float getBatteryCapacity() const;

	//setters
	void setBrand(const string& _brand);
	void setModel(const string& _model);
	void setBatteryCapacity(float _batteryCapacity);

	Product* clone() const override;
	virtual void print() const override;
	const string getTypeOfProduct()const; //function to get the Type of the product

	friend istream& operator>>(istream& _istream, Phone& _product);
	friend ostream& operator<<(ostream& _ostream, const Phone& _product);
};

