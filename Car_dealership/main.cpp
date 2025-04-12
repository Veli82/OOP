#include <iostream>
#include <algorithm>

#include "Date.h"
#include "Car.h"
#include "Dealership.h"

int main() {

	Dealership d1(5);
	Car car1(std::cin);
	Car car2(std::cin);
	Car car3(std::cin);
	d1.add(car1);
	d1.add(car2);
	d1.add(car3);
	//d1.sell(1);
	//d1.add(car1);
	d1.printByBrand("Honda");
	d1.printByMaxPrice(100000);
	d1.printByProdYear(2005);
	d1.sell(2);
	d1.printSoldCarsInfo();
	Dealership::printSoldCarsInfo();
	

}