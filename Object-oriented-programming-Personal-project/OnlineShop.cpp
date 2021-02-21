#include "OnlineShop.h"
#include"Product.h"
#include<iostream>
#include<cstring>

using namespace std;


OnlineShop::OnlineShop()
{
}

OnlineShop::OnlineShop(const OnlineShop & cpy)
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		items[i] = cpy.items[i]->clone();
	}
}

OnlineShop & OnlineShop::operator=(const OnlineShop & cpy)
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

OnlineShop::~OnlineShop()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
	items.clear();
}

void OnlineShop::addItem(const Product * _product)
{
	items.push_back(_product->clone());
}

void OnlineShop::removeItem(int index)
{
	if (index < items.size() && index >= 0)
	{
		delete items[index];
		items.erase(items.begin() + index);
	}
}



void OnlineShop::print() const
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		cout << "index:" << i <<endl;
	    items[i]->print();
	}
}

void OnlineShop::filterByPrice(float minPrice, float maxPrice) const
{
	for (int i = 0;i < items.size();i++)
	{
		if (items[i]->getPrice() >= minPrice && items[i]->getPrice() <= maxPrice)
		{
			items[i]->print();
		}
	}
}

Product * OnlineShop::getProduct(int index) const
{
	for (unsigned i = 0; i < items.size(); i++)
	{
		if (index == i)
		{
			return items[index];
			break;
		}
	}

}


