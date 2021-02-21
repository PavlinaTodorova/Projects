#include "Cart.h"
#include"Product.h"
#include<iostream>
using namespace std;


Cart::Cart()
{
}

Cart::Cart(const Cart & cpy)
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		items[i] = cpy.items[i]->clone();
	}
}

Cart & Cart::operator=(const Cart & cpy)
{
	if (this != &cpy)
	{
		for (size_t i = 0; i < cpy.items.size(); i++)
		{
			delete cpy.items[i];
		}

		items.clear();

		for (unsigned i = 0; i < cpy.items.size(); i++)
		{
			items.push_back(cpy.items[i]->clone());
		}
	}
	return *this;
}

Cart::~Cart()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}

void Cart::addItem(const Product * _product)
{
	items.push_back(_product->clone());
}

void Cart::removeItem(int index)
{
	if(index < items.size() && index >= 0)
	{
		delete items[index];
		items.erase(items.begin() + index);

	}
}


void Cart::print() const
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		cout << "index:" << i << endl;
		items[i]->print();
	}
}

void Cart::filterByPrice(float minPrice, float maxPrice) const
{
	for (int i = 0;i < items.size();i++)
	{
		if (items[i]->getPrice() >= minPrice && items[i]->getPrice() <= maxPrice)
		{
			items[i]->print();
		}
	}
}




