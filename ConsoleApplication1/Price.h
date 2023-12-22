#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Price
{
    int price;
    bool is_valid() const;

    friend std::istream& operator >> (istream& ist, Price& nedv);
    friend std::ostream& operator << (ostream& ost, Price& nedv);

private:
    static bool is_valid(int cost);
};


