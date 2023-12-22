#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW

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
        nedvs.push_back({ nedv });
    }
    
}

void output(vector <Nedv>& nedvs){
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
 
    _CrtDumpMemoryLeaks();
    return 0;
}
