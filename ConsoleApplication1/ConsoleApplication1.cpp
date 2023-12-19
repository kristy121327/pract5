#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>

#include "Data.h"
#include "Nedv.h"

using namespace std;

void input(ifstream& ist, vector <Nedv>& nedvs) {
    while (false == ist.eof()) {
        Nedv nedv;
        ist >> nedv;
        nedvs.push_back(nedv);
    }
}

void output(vector <Nedv> nedvs) {
    for (Nedv nedv : nedvs) {
        cout << nedv;
    }
}


int main()
{
    setlocale(0, "Rus");
    ifstream ist("in.txt");
    vector <Nedv> nedvs;

    try 
    {
        input(ist, nedvs);
        output(nedvs);
    }
    catch (std::runtime_error& err) 
    {
        std::cerr << err.what();
    }

    return 0;
}
