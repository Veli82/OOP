#pragma once

#include "Car.h"

class Dealership
{
public:
	Dealership(int parkingSlots);
	Dealership(const Dealership& dealership) = delete; //ne mislq che ima smisul da gi pisha puk i sus sig nqma da mi stigne vremeto
	Dealership& operator=(const Dealership dealership) = delete;
	~Dealership();

	void add(const Car& car);
	void sell(int parkingSlot);
	static void printSoldCarsInfo();
	void printByBrand(const char* brand) const;
	void printByMaxPrice(int maxPrice) const;
	void printByProdYear(int productionYear) const;

private:
	Car** cars = nullptr;	//everything will be heap allocated due to the lack of default constructor
	int* prices = nullptr;
	int parkinSlots;

	static int soldCount;
	static int moneyFromSales;
};

