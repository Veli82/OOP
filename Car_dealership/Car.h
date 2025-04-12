#pragma once
#include "Date.h"
#include <fstream>

enum class TrunkType
{
	Unknown = -1,
	Sedan,
	Kombi,
	Hatchback,
	Count
};

class Car
{
public:
	Car(std::istream& is);
	Car(const Car& car);
	Car& operator=(const Car& car);
	~Car();

	void print(std::ostream& os) const;
	static int getTotalPower();
	unsigned getPower() const;
	const char* getBrand() const;
	Date getDate() const;
private:
	char* brand = nullptr;
	Date prodDate;
	const TrunkType trunkType = TrunkType::Unknown;
	unsigned power = 0;
	unsigned numberOfSeats = 0;

	static int totalPower;

	void copyStatic(const Car& car);
	char* getStringCopy(const char* str);
	void free();

	//setters only for the constructor
	char* setBrand(std::istream& is);
	Date setDate(std::istream& is);
	TrunkType setTrunkType(std::istream& is);
	unsigned setUnsigned(std::istream& is);
};

