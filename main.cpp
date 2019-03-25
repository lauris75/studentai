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
int sprendimas()
{
    cout << endl << "Pasirinkite, kà norësite daryti:" << endl << "Jei norite patikrinti programos veikimà suvedant duomenis arba nuskaitant iğ jûsø failo patys spauskite 1" << endl;
    cout << "Jei norite patikrinti vektoriaus veikimo greitá, spauskite 2" << endl;
    cout << "O jei norite lyginti skirtingø konteineriø spartà nuskaitant iğ failo," << endl << "ruğiuojant (dviem skirtingais bûdais) ir iğvedant, spauskite 3 ";
    int x;
    for(int i = 0; i < 1; i++)
    {
        cin >> x;
        if (cin.fail() || ((x != 1) && (x != 2) && (x != 3)))
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka blogai ivedei, bandyk vel... " << endl;
            i--;
        }
    }
    cout << endl;
    return x;
}
template <typename T1>
void DuomenuNuskaitymas(T1 &stude, int &ilgvardas, int &ilgpavarde)
{
    string galutinis;
    int x, suma, kiekis = 0;
    std::ifstream PD ("kursiokai.txt");
    if(PD)
    {
        PD >> galutinis >> galutinis >> galutinis;
        while(galutinis[0] == 'N')
    {
        kiekis++;
        PD >> galutinis;
    }
    while(!PD.eof())
    {
        stud b;
        PD >> b.vardas;
        if(b.vardas.length() > ilgvardas-2) ilgvardas = b.vardas.length() + 2;
        PD >> b.pavarde;
        if(b.pavarde.length() > ilgpavarde-2) ilgpavarde = b.pavarde.length() + 2;
        suma = 0;
        for(int i = 0; i < kiekis; i++)
        {
            PD >> x;
            b.nd.push_back(x);
            suma = suma + x;
        }
        PD >> x;
        b.egzas = x;
        if(kiekis != 0) b.galvid = 0.4 * suma / kiekis + x * 0.6;
        else b.galvid = x * 0.6;
        stude.push_back(b);
    }
    PD.close();
    }
    else
    {
        cout << "Failo aplankale nëra, ásitikinkite, kad jis yra programos aplankale..." << endl;
        DuomenuNuskaitymas(stude, ilgvardas, ilgpavarde);
        return;
    }
}
void DuomenuIvedimas(vector<stud> &stude, int &ilgvardas, int &ilgpavarde)
{
    cout << "Duomenis ávesite patys ar juos nuskaityti? Nuskaitymui spauskite 1, kitu atveju spauskite 2" << endl;
    int x;
    for(int i = 0; i < 1; i++)
    {
        cin >> x;
        if (cin.fail() || ((x != 1) && (x != 2)))
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka blogai ivedei, bandyk vel... " << endl;
            i--;
        }
    }
    if(x == 1)DuomenuNuskaitymas(stude, ilgvardas, ilgpavarde);
    else
    {
        cout << "Áveskite, kiek bus studentø: ";
        int q;
        for(int i = 0; i < 1; i++)
        {
            cin >> q;
            if (cin.fail() || q < 1)
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                i--;
            }
        }
        for(int i = 0; i < q; i++)
        {
            stud a;
            cout << "Áveskite studento vardà - ";
            cin >> a.vardas;
            if(a.vardas.length() > ilgvardas) ilgvardas = a.vardas.length()+2;
            cout << "Áveskite studento pavardæ - ";
            cin >> a.pavarde;
            if(a.pavarde.length() > ilgpavarde) ilgpavarde = a.pavarde.length()+2;
            cout << "Áveskite, kiek bus namø darbø... Jei neşinote kiek bus, spauskite -1, jei norite generuoti, spauskite -2" << endl;
            for(int y = 0; y < 1; y++)
            {
                cin >> x;
                if (cin.fail() || x < -2)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                    y--;
                }
            }
            if(x == -2)
            {
                for(int i = 0; i < 100; i++)
                {
                    x = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
                    a.nd.push_back(x);
                }
            }
            if(x == -1)
            {
                while(x != -2)
                {
                    cout << "Jei baigëte suvedinëti paşymius, rağykite -2, kitu atveju," << endl << "Áveskite namø darbø paşymá - " ;
                    for(int y = 0; y < 1; y++)
                    {
                        cin >> x;
                        if (cin.fail() || (x != -2 && (x < 1 || x>10)))
                        {
                            cin.clear();
                            cin.ignore();
                            cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                            y--;
                        }
                    }
                    if(x != -2)a.nd.push_back(x);
                }
            }
            else
            {
                int z;
                for(int y = 0; y < x; y++)
                {
                    cout << "Iveskite namø darbà nr. " << y+1 << " - ";
                    cin >> z;
                    if (cin.fail() || (z < 1 || z > 10))
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                        y--;
                    }
                    a.nd.push_back(z);
                }
            }
            cout << "Egzamino paşymá generuoti (spauskite -1) ar patys ávesite (áveskite pavertinimà tada) - ";
            for(int y = 0; y < 1; y++)
            {
                cin >> x;
                if (cin.fail() || (x != -1 && (x < 1 || x > 10)))
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                    y--;
                }
                if(x == -1) a.egzas = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
                else a.egzas = x;
            }
            int o = a.nd.size(), suma = 0;
            for(int y = 0; y < o; y++)
            {
                suma = suma + a.nd.at(y);
            }
            if(o == 0)a.galvid = a.egzas * 0.6;
            else a.galvid = 0.4 * suma/o + a.egzas * 0.6;
            stude.push_back(a);
        }
    }
}
void DuomenuKurimas(vector<stud> &stude, int y)
{
    int ran, suma;
    for(int i=0; i < y; i++)
    {
        stud n;
        n.vardas = "Vardenis" + std::to_string(i+1);
        n.pavarde = "Pavardenis" + std::to_string(i+1);
        for(int x = 0; x < 100; x++)
        {
            ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
            n.nd.push_back(ran);
        }
        n.egzas = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
        suma = 0;
        for(int x = 0; x < 100; x++)
        {
            suma = suma + n.nd.at(x);
        }
        n.galvid = 0.4 * suma/100 + n.egzas * 0.6;
        stude.push_back(n);
    }
}
bool PagalGal(const stud &a, const stud &b)
{
    return a.galvid < b.galvid;
}
bool compare(const stud& a, const stud& b){
	return a.vardas < b.vardas;
}
template<typename T1, typename T2>
void DuomenuSkirstymas (T1 &stude, T2 &feil)
{
    std::sort(stude.begin(), stude.end(), compare);
    std::sort(stude.begin(), stude.end(), PagalGal);
    int x = stude.size();
    for(int i = 0; i < x; i++)
    {
        if(stude.at(i).galvid < 5)
        {
            feil.push_back(stude.at(i));
            stude.erase(stude.begin() + i);
            i--;
            x--;
        }
    }
}
template<typename T1, typename T2, typename T3>
void DuomenuSkirstymas2 (T1 &stude, T2 &feil, T3 &kiet)
{
    std::sort(stude.begin(), stude.end(), compare);
    std::sort(stude.begin(), stude.end(), PagalGal);
    int x = stude.size();
    for(int i = 0; i < x; i++)
    {
        if(stude.at(0).galvid < 5) feil.push_back(stude.at(i));
        else kiet.push_back(stude.at(i));
    }
}
bool Skola (const stud& a)
{
    return (a.galvid < 5);
}
void TobulintasSkirstymas(vector<stud> &stude, vector<stud> &feilai)
{
    std::sort(stude.begin(), stude.end(), compare);
    std::sort(stude.begin(), stude.end(), PagalGal);
    int y = 0, x = stude.size();
    std::remove_copy_if (stude.begin(),stude.begin()+y,feilai.begin(),Skola);
}
void DuomenuSkirstymasList (list<stud> &stude, list<stud> &feilai)
{
    stude.sort(compare);
    stude.sort(PagalGal);
    auto it = stude.begin();
    int x = stude.size();
    for(int i = 0; i < x; i++)
    {
        if(it->galvid < 5)
        {
            stud a;
            a.vardas = it->vardas;
            a.pavarde = it->pavarde;
            a.galvid = it->galvid;
            feilai.push_back(a);
            stude.erase(it);
            it=stude.begin();
            advance(it, i);
            i--;
            x--;
        }
        else it++;
    }
}
void DuomenuSkirstymasList2 (list<stud> &stude, list<stud> &feilai, list<stud> &kiet)
{
    stude.sort(compare);
    stude.sort(PagalGal);
    auto it = stude.begin();
    int x = stude.size();
    for(int i = 0; i < x; i++)
    {
        if(it->galvid < 5)
        {
            stud a;
            a.vardas = it->vardas;
            a.pavarde = it->pavarde;
            a.galvid = it->galvid;
            feilai.push_back(a);
        }
        else
        {
            stud a;
            a.vardas = it->vardas;
            a.pavarde = it->pavarde;
            a.galvid = it->galvid;
            kiet.push_back(a);
        }
        it++;
    }
}
template<typename T>
void DuomenuIsvedimas(T stude, int ilgvardas, int ilgpavarde, string k)
{
    auto it = stude.begin();
    std::ofstream RZ (k);
    int x = stude.size();
    for(int i = 0; i < x; i++)
    {
        RZ << std::left << std::setw(ilgvardas) << it->vardas << std::setw(ilgpavarde) << it->pavarde << std::setprecision(3) << it->galvid << endl;
        it++;
    }
    RZ.close();
}
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
            RZ << "Generuojant " << y << " studentø sàrağà prireikë " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekundşiø" << endl;
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
            if(i == 0)RZ << "Dabar prastai iğlaikiusius ádësime á naujà konteineryje, o iğ seno iğtrynsime, tokiu bûdu darant" << endl << "Konteineriams prireikë tiek laiko:" << endl;
            else RZ << "Dabar studentus skirstysime á du naujus konteinerius, tokiu bûdu, mûsø naudojamiems konteineriams prireikë tiek laiko:" << endl;
            auto begin = std::chrono::high_resolution_clock::now();
            DuomenuNuskaitymas(studvec, ilgvardas, ilgpavarde);
            if(i == 0)DuomenuSkirstymas (studvec, feilai);
            else DuomenuSkirstymas2(studvec, feilai, kietiakai);
            if(i == 0)DuomenuIsvedimas(studvec, ilgvardas, ilgpavarde, "VectorKietiakai");
            else DuomenuIsvedimas(kietiakai, ilgvardas, ilgpavarde, "VectorKietiakai");
            DuomenuIsvedimas(feilai, ilgvardas, ilgpavarde, "VectorFeilai");
            auto end = std::chrono::high_resolution_clock::now();
            RZ << "Vektoriui prireikë " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekundşiø" << endl;
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
            RZ << "Listui prireikë " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekundşiø" << endl;
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
            RZ << "Deque prireikë " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekundşiø" << endl;
            studdeq.clear();
            feildeq.clear();
            kietdeq.clear();
        }
        RZ << "Naudojant specialià funkcijà (std::remove_copy_if) vektoriaus sukûrimas ir naudojimas uşima: ";
        auto begin = std::chrono::high_resolution_clock::now();
        DuomenuNuskaitymas(studvec, ilgvardas, ilgpavarde);
        TobulintasSkirstymas(studvec, feilai);
        DuomenuIsvedimas(studvec, ilgvardas, ilgpavarde, "VectorKietiakai");
        DuomenuIsvedimas(feilai, ilgvardas, ilgpavarde, "VectorFeilai");
        auto end = std::chrono::high_resolution_clock::now();
        RZ << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << " nanosekundşiø" << endl;
        RZ.close();
    }
    return 0;
}
