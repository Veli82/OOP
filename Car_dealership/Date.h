#include <inttypes.h>
#include <fstream>

#pragma once
class Date
{
public:
	Date();
	Date(int day, int month, int year);
	Date(const char* str);
	Date(const Date&) = default;
	Date& operator=(const Date& date) = default;
	~Date() = default;
	
	void setDay(int  day);
	void setMonth(int month);
	void setYear(int year);
	int getYear() const;

	void print(std::ostream& os) const;
private:
	//0/0/0 is default
	uint16_t day 	: 5;	//0-31
	uint16_t month	: 4;	//0-15
	uint16_t year	: 6;	//0-63		year: 1969-2032
	
};

