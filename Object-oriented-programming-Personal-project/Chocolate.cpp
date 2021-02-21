#include "Chocolate.h"
#include<cstring>



Chocolate::Chocolate()
{
	type = Type::chocolate;
	setName("");
	setGrams(0);
}

Chocolate::Chocolate(int _itemCode, float _price, int _quantity, const string& _name, double _grams): Product(_itemCode, _price, _quantity)
{
	type = Type::chocolate;
	setName(_name);
	setGrams(_grams);
}

const string& Chocolate::getName() const
{
	return name;
}

double Chocolate::getGrams() const
{
	return grams;
}

void Chocolate::setName(const string& _name)
{
	name = _name;
}

void Chocolate::setGrams(double _grams)
{
	grams = _grams;
}

const string Chocolate::getTypeOfProduct() const
{
	return "Chocolate";
}

Product * Chocolate::clone() const
{
	return new Chocolate (* this);
}

void Chocolate::print() const
{
	cout << "Type: " << getTypeOfProduct() << endl;
	cout << "Name: " << getName() << endl;
	cout<<"Grams: " << getGrams() << endl;
	Product::print();
	std::cout << "\n";
}

istream & operator>>(istream & _istream, Chocolate & _product)
{
	char buffer[500];
	cout << "Name: ";
	_istream >> buffer;
	_product.setName(buffer);
	cout << "Grams: ";
	_istream >> _product.grams;
    operator >> (_istream, (Product&)_product);
	return _istream;
	
}

ostream & operator<<(ostream & _ostream, const Chocolate & _product)
{
	_ostream << "Name: " << _product.getName() << endl;
	_ostream << "Grams: " << _product.getGrams() << endl;
	operator<<(_ostream, (Product&)_product);
	return _ostream;
}
