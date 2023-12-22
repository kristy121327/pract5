#include <iostream>
#include <fstream>
#include "Price.h"
#include "Data.h"

using namespace std;

struct Nedv
{
    string owner;
    Data data;
    Price price;
    bool is_valid() const;

    friend std::istream& operator >> (istream& ist, Nedv& nedv);
    friend std::ostream& operator << (ostream& ost, Nedv& nedv);

private:
    static bool is_valid(string name);
};


