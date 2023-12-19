#pragma once
#include <iostream>


using namespace std;
struct Data
{
	int day;
	int month;
	int year;
	bool is_valid() const;

	friend std::istream& operator>>(std::istream& ist, Data& data);
	friend std::ostream& operator<<(std::ostream& ost, Data& data);

private:
	static bool is_valid(int dd, int mm, int yy);
};



