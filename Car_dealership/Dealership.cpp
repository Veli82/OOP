#include <iostream>
#include <stdexcept>

#include "Dealership.h"
#include "Car.h"

Dealership::Dealership(int parkingSlots)
{
	cars = new Car * [parkingSlots] {};
	for (int i = 0; i < parkinSlots; i++)
	{
		cars[i] = nullptr;
	}
	prices = new int[parkingSlots] {};
	this->parkinSlots = parkingSlots;
}

Dealership::~Dealership()
{
	for (int i = 0; i < parkinSlots; i++) {
		delete cars[i];
	}
	delete[] cars;
	delete[] prices;
}

void Dealership::add(const Car& car)
{
	for (int i = 0; i < parkinSlots; i++) {
		if (cars[i] == nullptr) {
			cars[i] = new Car(car);		//vse oshte ne sum siguren dali e po dobre da gi kopiram (izlishno kopie mozhe bi) ili da prenasochvam pointera samo (samo che ima opastnost da se promenqt dannite otvun)
			prices[i] = cars[i]->getPower() * 1000;	//nqkakuv bullshit izmislih za da ne e prazno, nikude v zadachata ne pishe ot kude idva taq cena???
			return;
		}
	}
	throw std::runtime_error("Can't add! No free space at the dealership!");
}

void Dealership::sell(int parkingSlot)
{
	for (int i = 0; i < parkinSlots; i++) {
		if (i == parkingSlot) {
			if (cars[i] == nullptr) throw std::runtime_error("Can't sell! Slot is already empty!");
			soldCount++;
			moneyFromSales += prices[i];
			prices[i] = 0;
			delete cars[i];
			cars[i] = nullptr;
			return;
		}
	}
	throw std::runtime_error("Can't sell1 Invalid slot requested!");
}

void Dealership::printSoldCarsInfo()
{
	std::cout << "Sold cars count: " << soldCount << ", total money from sales: " << moneyFromSales << '\n';
}

void Dealership::printByBrand(const char* brand) const
{
	for (int i = 0; i < parkinSlots; i++) {
		if (cars[i] != nullptr && !strcmp(cars[i]->getBrand(), brand)) {
			cars[i]->print(std::cout);
		}
	}
}

void Dealership::printByMaxPrice(int maxPrice) const
{
	for (int i = 0; i < parkinSlots; i++) {
		if (cars[i] != nullptr && prices[i] <= maxPrice) {
			cars[i]->print(std::cout);
		}
	}
}

void Dealership::printByProdYear(int productionYear) const
{
	for (int i = 0; i < parkinSlots; i++) {
		if (cars[i] != nullptr && cars[i]->getDate().getYear() == productionYear) {
			cars[i]->print(std::cout);
		}
	}
}

int Dealership::soldCount = 0;
int Dealership::moneyFromSales = 0;
