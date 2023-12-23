#include "Data.h"

using namespace std;

istream& operator>>(istream& ist, Data& data)
{
	int dd, mm, yy; // yyyy.mm.dd
	char dots[2];

	ist >> dd;
	dots[0] = ist.get();
	ist >> mm;
	dots[1] = ist.get();
	ist >> yy;

	if (ist.fail()) {
		throw std::runtime_error("read from stream failed");
	}
	if (dots[0] != '.' && dots[1] != '.') {
		throw std::runtime_error("dot not found");
	}
	try {
		if (!Data::is_valid(dd, mm, yy)) {
			throw std::runtime_error("date is invalid");
		}
	} catch (const std::runtime_error& e) {
		throw;
	}
	data.day = dd;
	data.month = mm;
	data.year = yy;

	return ist;
};
ostream& operator<<(ostream& ost, const Data& data)
{
	ost << data.day<< "." << data.month << "." << data.year;
	return ost;
}

bool Data::is_valid() const 
{
	return is_valid(day, month, year);
}
bool Data::is_valid(int dd, int mm, int yy) {
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yy > 2023) {
        return false;
    }

    if (((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0) && mm == 2 && dd > 29) {
        return false;
    }

    if (((yy % 4 != 0 || yy % 100 == 0) && yy % 400 != 0) && mm == 2 && dd > 28) {
        return false;
    }

    if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd > 31) {
        return false;
    }

    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) {
        return false;
    }

    return true;
}
