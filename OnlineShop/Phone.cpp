#include "Phone.h"
#include<iostream>
#include<cstring>



Phone::Phone()
{
	type = Type::phone;
	setBrand("");
	setModel("");
	setBatteryCapacity(0);
}

Phone::Phone(int _itemCode, float _price, int _quantity, const string& _brand, const string& _model, float _batteryCapacity): Product(_itemCode, _price, _quantity)
{
	type = Type::phone;
	setBrand(_brand);
	setModel(_model);
	setBatteryCapacity(_batteryCapacity);
}

Product * Phone::clone() const
{
	return new Phone(*this);
}

const string& Phone::getBrand() const
{
	return brand;
}

const string& Phone::getModel() const
{
	return model;
}

float Phone::getBatteryCapacity() const
{
	return batteryCapacity;
}

void Phone::setBrand(const string& _brand)
{
	brand = _brand;
}

void Phone::setModel(const string& _model)
{
	model = _model;
}

void Phone::setBatteryCapacity(float _batteryCapacity)
{
	batteryCapacity = _batteryCapacity;
}

void Phone::print() const
{
	cout << "Type: " << getTypeOfProduct() << endl;
	cout << "Brand: " << getBrand() << endl;
	cout << "Model: " << getModel() << endl;
	cout << "BatteryCapacity: " << getBatteryCapacity() << endl;
	Product::print();
	std::cout << "\n";
}

const string  Phone::getTypeOfProduct() const
{
	return "Phone";
}

istream & operator>>(istream & _istream, Phone & _product)
{
	char buffer[500];
	cout << "Brand: ";
	_istream >> buffer;
	_product.setBrand(buffer);
	cout << "Model: ";
	_istream >> buffer;
	_product.setModel(buffer);
	cout << "BaterryCapacity: ";
	_istream >> _product.batteryCapacity;
	operator >> (_istream, (Product&)_product);
	return _istream;
}

ostream & operator<<(ostream & _ostream, const Phone & _product)
{
	operator<<(_ostream, (Product&)_product);
	_ostream << "Brand: " << _product.getBrand() << endl;
	_ostream << "Model: " << _product.getModel() << endl;
	_ostream << "BatteryCapacity: " << _product.getBatteryCapacity() << endl;
	operator<<(_ostream, (Product&)_product);
	return _ostream;
}
