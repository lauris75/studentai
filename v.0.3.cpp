#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include "funkcijos.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    int ilgvardas = 2, ilgpavarde = 2;
    string galutinis = "nieko";
    vector<string> vardai;
    system("chcp 1257");
    DuomenuIvedimas(ilgvardas, ilgpavarde, galutinis);
    clock_t pradzia, pabaiga ;
    pradzia = clock();
    rikiavimas(vardai);
    if(galutinis == "pabaiga") return 0;
    skaiciavimai();
    spausdinimas(ilgvardas, ilgpavarde);
    pabaiga = clock();
    cout << endl << 1.0*( pabaiga - pradzia )/ CLOCKS_PER_SEC << endl;
    return 0;
}
