#include "Product.h"
#include<cstring>
#include<iostream>
using namespace std;



Product::Product()
{
	setItemCode(0);
	setPrice(0);
	setQuantity(0);
}

Product::Product(int _itemCode, float _price, int _quantity)
{
	setItemCode(_itemCode);
	setPrice(_price);
	setQuantity(_quantity);
}

int Product::getItemCode() const
{
	return itemCode;
}

float Product::getPrice() const
{
	return price;
}

int Product::getQuantity() const
{
	return quantity;
}

/*Product::Type Product::getType() const
{
	return type;
}
*/

void Product::setItemCode(int _itemCode)
{
	itemCode = _itemCode;
}

void Product::setPrice(float _price)
{
	price = _price;
}

void Product::setQuantity(int _quantity)
{
	quantity = _quantity;
}

void Product::print() const
{
	cout << "itemCode: " << getItemCode() << endl;
	cout << "Price: " << getPrice() << endl;
	cout << "Quantity: " << getQuantity() << endl;

}



istream & operator>>(istream & _istream, Product & _product)
{
	cout << "itemCode: ";
	_istream >> _product.itemCode;
	cout << "Price: ";
	_istream >> _product.price;
	cout << "Quantity: ";
	_istream >> _product.quantity;
	return _istream;
}

ostream & operator<<(ostream & _ostream, const Product & _product)
{
	_ostream << "itemCode: " << _product.getItemCode() << endl;
	_ostream << "Price: " << _product.getPrice() << endl;
	_ostream << "Quantity: " << _product.getQuantity() << endl;
	return _ostream;
}
