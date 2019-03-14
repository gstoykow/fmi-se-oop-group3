#include "Date.h"

#include <iostream>

using namespace std;

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

unsigned int Date::getDay() const
{
	return this->day;
}

void Date::setDay(unsigned int day)
{
	if (0 < day && day<= 31)
		this->day = day;
	else this->day = 1;
	
}

unsigned int Date::getMonth() const
{
	return this->month;
}

void Date::setMonth(unsigned int month)
{
	if (0 < month && month <= 12)
		this->month = month;
	else this->month = 1;
}

unsigned int Date::getYear() const
{
	return this->year;
}

void Date::setYear(unsigned int year)
{
	if (1878 <= year && year <= 2019)
		this->year = year;
	else this->year = 1878;
}

char * Date::getDate() const
{
	char* formatedDate = new char[11];
	int i = 1;

	int temp_day = getDay();
	while (i > -1)
	{
		formatedDate[i] = (temp_day % 10) + '0';
		temp_day /= 10;
		i--;
	}
	formatedDate[2] = '-';

	i = 4;
	int temp_month = getMonth();
	while (i > 2)
	{
		formatedDate[i] = (temp_month % 10) + '0';
		temp_month /= 10;
		i--;
	}
	formatedDate[5] = '-';

	i = 9;
	int temp_year = getYear();
	while (i > 5)
	{
		formatedDate[i] = (temp_year % 10)+ '0';
		temp_year /= 10;
		i--;
	}
	formatedDate[10] = '\0';

	return formatedDate;
}
