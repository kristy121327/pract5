#include "Nedv.h"

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

ostream& operator<<(ostream& ost, const Data& data) {
    ost << data.day << " " << data.month << " " << data.year;
    return ost;
}


bool Nedv::is_valid() const
{
	return is_valid(owner);
}
bool Nedv::is_valid(string name)
{
    if (!isupper(name[0])) // âñòðîåííàÿ ôóíêöèÿ äëÿ ïðîâåðêè çàãëàâíîé áóêâû
    {
        throw std::runtime_error("The name does not start with a capital letter(ne s zaglavnoi bykvi)");
    }

    for (size_t i = 1; i < name.length(); ++i) {
        if (!islower(name[i])) // âñòðîåííàÿ ôóíêöèÿ äëÿ ïðîâåðêè èìåíè, ÷òîáû ïîñëå çàãëàâíîé øëè òîëüêî ñòðî÷íûå áóêâû
        {
            throw std::runtime_error("The name does not continue from lowercase letters(ne iz strochnix)");
        }
    }
}
