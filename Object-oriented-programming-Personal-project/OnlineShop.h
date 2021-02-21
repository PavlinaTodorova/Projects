#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"Product.h"
#include"Chocolate.h"
#include"Dress.h"
#include"Phone.h"
#include<iostream>
#include<vector>
using namespace std;

class OnlineShop
{
	vector<Product*> items;
	
public:

	OnlineShop();
	OnlineShop(const OnlineShop& cpy);
	OnlineShop& operator=(const OnlineShop& cpy);
	~OnlineShop();

	void addItem(const Product* _product);
	void removeItem(int index);
	void print() const;

	/* function to filter the products by their price
	(example: we have only 10lv, so what can we buy with these money: minPrice 0, maxPrice 10) */
	void filterByPrice(float minPrice, float maxPrice)const;

	
	/* Functon that find product* from the submitted index. We use it when we want to add new product in the Cart*/
	Product* getProduct(int index) const;

};



