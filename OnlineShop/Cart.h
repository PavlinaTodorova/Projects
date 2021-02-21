#pragma once
#include"Product.h"
#include<iostream>
#include"Chocolate.h"
#include"Dress.h"
#include"Phone.h"
#include<vector>

using namespace std;

class Cart
{
	vector<Product*> items;

public:

	Cart();
	Cart(const Cart& cpy);
	Cart& operator=(const Cart& cpy);
	~Cart();

	void addItem(const Product* _product); 
	void removeItem(int index); 
	void print() const;

	/* function to filter the products by their price
	(example: we have only 10lv, so what can we buy with these money: minPrice 0, maxPrice 10) */
	// This function exist also here, in case some of the users want to filter their products by price in the Cart
	void filterByPrice(float minPrice, float maxPrice)const; 
	
};

