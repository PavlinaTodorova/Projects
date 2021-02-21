#include "Dress.h"
#include<cstring>



Dress::Dress()
{
	type = Type::dress;
	setSize(0);
	setBrand("");
	setModel("");
	setColour("");
}

Dress::Dress(int _itemCode, float _price, int _quantity, int _size, const string& _brand, const string& _model, const string& _colour): Product(_itemCode, _price, _quantity)
{
	type = Type::dress;
	setSize(_size);
	setBrand(_brand);
	setModel(_model);
	setColour(_colour);
}

Product * Dress::clone() const
{
	return new Dress (*this);
}


int Dress::getSize() const
{
	return size;
}

const string& Dress::getBrand() const
{
	return brand;
}

const string& Dress::getModel() const
{
	return model;
}

const string& Dress::getColour() const
{
	return colour;
}

void Dress::setSize(int _size)
{
	size = _size;
}

void Dress::setBrand(const string& _brand)
{
	brand = _brand;
}

void Dress::setModel(const string& _model)
{
	model= _model;
}

void Dress::setColour(const string& _colour)
{
	colour = _colour;
}

void Dress::print() const
{
	cout << "Type: " << getTypeOfProduct() << endl;
	cout << "Size: " << getSize() << endl;
	cout << "Brand: " << getBrand() << endl;
	cout << "Model: " << getModel() << endl;
	cout << "Colour: " << getColour() << endl;
	Product::print();
	std::cout << "\n";
}

const string Dress::getTypeOfProduct() const
{
	return "Dress";
}

istream & operator>>(istream & _istream, Dress & _product)
{
	char buffer[500];
	cout << "Size: ";
	_istream >> _product.size;
	cout << "Brand: ";
	_istream >> buffer;
	_product.setBrand(buffer);
	cout << "Model: ";
	_istream >> buffer;
	_product.setModel(buffer);
	cout << "Colour: ";
	_istream >> buffer;
	_product.setColour(buffer);
	operator >> (_istream, (Product&)_product);
	return _istream;

}

ostream & operator<<(ostream & _ostream, const Dress & _product)
{
	_ostream << "Size: " << _product.getSize() << endl;
	_ostream << "Brand: " << _product.getBrand() << endl;
	_ostream << "Model: " << _product.getModel() << endl;
	_ostream << "Colour: " << _product.getColour() << endl;
	operator<<(_ostream, (Product&)_product);
	return _ostream;
}
