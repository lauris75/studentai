#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <deque>
#include <list>
#include <iterator>
#include <chrono>
#include "stud.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::deque;

struct stud
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzas;
    double vid;
    double galvid;
};

int main()
{
    system("chcp 1257");
    int s = sprendimas();
    if(s == 1)
    {
        int ilgvardas = 8, ilgpavarde = 9;
        vector<stud>stude;
        DuomenuIvedimas(stude, ilgvardas, ilgpavarde);
        DuomenuIsvedimas(stude, ilgvardas, ilgpavarde, "Studentai");
    }
    if(s == 2)
    {
        vector<stud>stude;
        int y = 1;
        std::ofstream RZ ("Laikai.vec.txt");
        for(int i = 0; i < 6; i++)
        {
            auto begin = std::chrono::high_resolution_clock::now();
            y=y*10;
            DuomenuKurimas(stude, y);
            DuomenuIsvedimas(stude, 8+i, 9+i, "Studentai"+std::to_string(y));
            auto end = std::chrono::high_resolution_clock::now();
            RZ << "Generuojant " << y << " student� s�ra�� prireik� " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekund�i�" << endl;
            stude.clear();
        }
        RZ.close();
    }
    if(s == 3)
    {
        std::ofstream RZ ("Laikai.konteineriai.txt");
        int ilgvardas = 8, ilgpavarde = 9;
        vector<stud>studvec;
        vector<stud>feilai;
        vector<stud>kietiakai;
        std::list<stud>studlist;
        std::list<stud>feillist;
        std::list<stud>kietlist;
        std::deque<stud>studdeq;
        std::deque<stud>feildeq;
        std::deque<stud>kietdeq;
        for(int i = 0; i < 2; i++)
        {
            if(i == 0)RZ << "Dabar prastai i�laikiusius �d�sime � nauj� konteineryje, o i� seno i�trynsime, tokiu b�du darant" << endl << "Konteineriams prireik� tiek laiko:" << endl;
            else RZ << "Dabar studentus skirstysime � du naujus konteinerius, tokiu b�du, m�s� naudojamiems konteineriams prireik� tiek laiko:" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            DuomenuNuskaitymas(studvec, ilgvardas, ilgpavarde);
            if(i == 0)DuomenuSkirstymas (studvec, feilai);
            else DuomenuSkirstymas2(studvec, feilai, kietiakai);
            if(i == 0)DuomenuIsvedimas(studvec, ilgvardas, ilgpavarde, "VectorKietiakai");
            else DuomenuIsvedimas(kietiakai, ilgvardas, ilgpavarde, "VectorKietiakai");
            DuomenuIsvedimas(feilai, ilgvardas, ilgpavarde, "VectorFeilai");
            auto end = std::chrono::high_resolution_clock::now();
            RZ << "Vektoriui prireik� " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekund�i�" << endl;
            studvec.clear();
            feilai.clear();
            kietiakai.clear();
            begin = std::chrono::high_resolution_clock::now();
            DuomenuNuskaitymas(studlist, ilgvardas, ilgpavarde);
            if(i == 0)DuomenuSkirstymasList (studlist, feillist);
            else DuomenuSkirstymasList2(studlist, feillist, kietlist);
            if(i == 0)DuomenuIsvedimas(studlist, ilgvardas, ilgpavarde, "ListKietiakai");
            else DuomenuIsvedimas(kietlist, ilgvardas, ilgpavarde, "ListKietiakai");
            DuomenuIsvedimas(feillist, ilgvardas, ilgpavarde, "ListFeilai");
            end = std::chrono::high_resolution_clock::now();
            RZ << "Listui prireik� " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekund�i�" << endl;
            studlist.clear();
            feillist.clear();
            kietlist.clear();
            begin = std::chrono::high_resolution_clock::now();
            DuomenuNuskaitymas(studdeq, ilgvardas, ilgpavarde);
            if(i == 0)DuomenuSkirstymas (studdeq, feildeq);
            else DuomenuSkirstymas2(studdeq, feildeq, kietdeq);
            if(i == 0)DuomenuIsvedimas(studdeq, ilgvardas, ilgpavarde, "DequeKietiakai");
            else DuomenuIsvedimas(kietdeq, ilgvardas, ilgpavarde, "DequeKietiakai");
            DuomenuIsvedimas(feildeq, ilgvardas, ilgpavarde, "DequeFeilai");
            end = std::chrono::high_resolution_clock::now();
            RZ << "Deque prireik� " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekund�i�" << endl;
            studdeq.clear();
            feildeq.clear();
            kietdeq.clear();
        }
        RZ << "Naudojant speciali� funkcij� (std::remove_copy_if) vektoriaus suk�rimas ir naudojimas u�ima: ";
        auto begin = std::chrono::high_resolution_clock::now();
        DuomenuNuskaitymas(studvec, ilgvardas, ilgpavarde);
        TobulintasSkirstymas(studvec, feilai);
        DuomenuIsvedimas(studvec, ilgvardas, ilgpavarde, "VectorKietiakai");
        DuomenuIsvedimas(feilai, ilgvardas, ilgpavarde, "VectorFeilai");
        auto end = std::chrono::high_resolution_clock::now();
        RZ << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekund�i�" << endl;
        RZ.close();
    }
    return 0;
}
