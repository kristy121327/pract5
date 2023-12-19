#include <iostream>
#include <fstream>
#include "Nedv.h"
#include <cctype> 

using namespace std;

istream& operator >> (istream& ist, Nedv& nedv) {
    string name;
    
    ist >> nedv.data;
    ist >> nedv.price;
    ist >> name;

    if (ist.fail()) {
        throw std::runtime_error("read from stream failed");
    }

    if (!Nedv::is_valid(name)) {
        throw std::runtime_error("Name is invalid");
    }

    nedv.owner = name;

    return ist;
}


ostream& operator << (ostream& ost, Nedv& nedv)
{
    ost << nedv.data << " " << nedv.price << " " << nedv.owner << endl;
    return ost;
}

bool Nedv::is_valid() const
{
	return is_valid(owner);
}
bool Nedv::is_valid(string name)
{
    if (!isupper(name[0])) // встроенная функция для проверки заглавной букы
    {
        throw std::runtime_error("The name does not start with a capital letter(ne s zaglavnoi bykvi)");
    }

    for (size_t i = 1; i < name.length(); ++i) {
        if (!islower(name[i])) // встроенная функция для проверки имени, чтобы после заглавной шли только строчные буквы
        {
            throw std::runtime_error("The name does not continue from lowercase letters(ne iz strochnix)");
        }
    }

}
