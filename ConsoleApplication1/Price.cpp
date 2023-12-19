#include <iostream>
#include <fstream>
#include "Price.h"
#include <cctype> 

using namespace std;

istream& operator >> (istream& ist, Price& price) {
    int cost;

    ist >> cost;

    if (ist.fail()) {
        throw std::runtime_error("read from stream failed");
    }

    if (!Price::is_valid(cost)) {
        throw std::runtime_error("Name is invalid");
    }

    price.price = cost;

    return ist;
}


ostream& operator << (ostream& ost, Price& price)
{
    ost << price.price;
    return ost;
}

bool Price::is_valid() const
{
    return is_valid(price);
}
bool Price::is_valid(int cost)
{
    if (cost < 0 )
    {
        throw std::runtime_error("Cost is invalid");
    }
}