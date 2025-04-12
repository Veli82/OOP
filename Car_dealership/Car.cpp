#pragma warning (disable : 4996)

#include "Car.h"

#include <cstring>
#include <stdexcept>

TrunkType stringToTrunkType(const char* str) {
	if (!strcmp(str, "Sedan")) return TrunkType::Sedan;
	if (!strcmp(str, "Kombi")) return TrunkType::Kombi;
	if (!strcmp(str, "Hatchback")) return TrunkType::Hatchback;
	return TrunkType::Unknown;
}

const char* trunkTypeToString(TrunkType trType) {
	switch (trType)
	{
	case TrunkType::Unknown:
		return "Unknown";
	case TrunkType::Sedan:
		return "Sedan";
	case TrunkType::Kombi:
		return "Kombi";
	case TrunkType::Hatchback:
		return "Hatchback";
	default:
		return "Unknown";
	}
}

Car::Car(std::istream& is) :
	brand(setBrand(is))	,
	prodDate(setDate(is)),
	trunkType(setTrunkType(is)),
	power(setUnsigned(is)),
	numberOfSeats(setUnsigned(is))
{
	totalPower += power;
}

Car::Car(const Car& car)
	:trunkType(car.trunkType)
{
	brand = getStringCopy(car.brand);
	copyStatic(car);
	totalPower += power;
}

Car& Car::operator=(const Car& car)
{
	if (this != &car) {
		char* temp = getStringCopy(car.brand);
		delete[] brand;
		brand = temp;
		totalPower -= power;
		copyStatic(car);
		totalPower += power;
	}

	return *this;
}

Car::~Car()
{
	free();
	totalPower -= power;
}

void Car::print(std::ostream& os) const
{
	os << brand << ' ';
	prodDate.print(os);
	os << trunkTypeToString(trunkType) << " horsepower: " << power
		<< " Seats: " << numberOfSeats << '\n';
}

int Car::getTotalPower()
{
	return totalPower;
}

const char* Car::getBrand() const
{
	return brand;
}

Date Car::getDate() const
{
	return prodDate;
}

unsigned Car::getPower() const
{
	return power;
}

void Car::copyStatic(const Car& car)
{
	prodDate = car.prodDate;
	power = car.power;
	numberOfSeats = car.numberOfSeats;
}

char* Car::getStringCopy(const char* str)
{
	if (!str) throw std::runtime_error("passed a nullptr");
	char* temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	return temp;
}

void Car::free()
{
	delete[] brand;
}

char* Car::setBrand(std::istream& is)
{
	char buffer[1024];
	is >> buffer;
	char* str = new char[strlen(buffer) + 1];
	strcpy(str, buffer);
	return str;
	
}

Date Car::setDate(std::istream& is)
{
	char buffer[1024];
	is >> buffer;
	return Date(buffer);
}

TrunkType Car::setTrunkType(std::istream& is)
{
	char buffer[1024];
	is >> buffer;
	return stringToTrunkType(buffer);
}

unsigned Car::setUnsigned(std::istream& is)
{
	int num;
	is >> num;
	if (num < 0) throw std::runtime_error("Invalid Car input!");
	return num;
}


int Car::totalPower = 0;
