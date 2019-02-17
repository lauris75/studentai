#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fixed;

int ilgvardas = 2, ilgpavarde = 2;
string galutinis = "nieko";
struct stud
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzas;
    double vid;
    double med;
    double galvid;
    double galmed;
    stud* next;

}*h, *n, *t;

void DuomenuIvedimas()
{
    int ran, x, l, k=0, tik, tik2, kiekis, ch = 1;
    cout << "Áveskite, keliø studentø duomenis ávesite: ";
    for(int i = 0; i < 1; i++)
    {
        cin >> x;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka blogai ivedei, bandyk vel... " << endl;
            i--;
        }
    }
    if(x == 0)
    {
        cout << "Tada nëra, kà atspausdinti...";
        galutinis = "pabaiga";
        return;
    }
    tik = 0;
    for(int i = 0; i < x; i++)
    {
        n = new stud;
        if(tik == 1) t->next = n;
        if(tik == 0)
            {
                h = n;
                tik = 1;
            }
        t = n;
        cout << "Áveskite studento vardà - ";
        cin >> n->vardas;
        if(n->vardas.length() > ilgvardas-2) ilgvardas = n->vardas.length()+2;
        cout << "Áveskite studento pavardæ - ";
        cin >> n->pavarde;
        if(n->pavarde.length() > ilgpavarde-2) ilgpavarde = n->pavarde.length()+2;
        cout << "Áveskite kiek norësite ávesti studento \"" << n->vardas << " " << n->pavarde << "\" namø darbø." << endl << "Jei neþinote kiek bus namø darbø raðykite -1: " << endl << "Jei norite automatiðkai sugeneruoti namø darbø paþymius, spauskite -2: ";
        for(int y = 0; y < 1; y++)
        {
            cin >> k;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                y--;
            }
            if(k < -2)
            {
                cout << "Namø darbø negali bûti maþiau nei 0... bandyk vel" << endl;
                y--;
            }
        }
        kiekis = 1;
        if (k == -2)
        {
            cout << "Kiek sugeneruoti namø darbø rezultatø? ";
            for(int y = 0; y < 1; y++)
            {
                cin >> k;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                    y--;
                }
                if(k < 0)
                {
                    cout << "Namø darbø negali bûti maþiau nei 0... bandyk vel" << endl;
                    y--;
                }
            }
            ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
            for(int p = 0; p < k; p++)
            {
                ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
                t->nd.push_back(ran);
            }
        }
        else if (k == -1)
        {
            cout << "Kai jau bûsite ávedæ visus namø darbø ávetinimus, raðykite -2" << endl;
            while(k != -2)
            {
                cout << "Nd nr." << kiekis << " ávertinimas = ";
                cin >> k;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                }
                if ((k != -2) && (k<11) && (k>0))
                {
                    kiekis++;
                    n->nd.push_back(k);
                }
                else if(k != -2) cout << "Áveskite normalø namø darbø paþymá..." << endl << "Primenu: norëdami baigti ðio studento namø darbø ávedimà, paraðykite -2" << endl;
            }
        }
        else
        {
            for (int y = 0; y < k; y++)
        {
            cout << "Iveskite nd Nr." << y+1 << " - ";
            cin >> l;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                y--;
                ch = 0;
            }
            if((ch == 1) && (l<11) && (l>0))
            {
                n->nd.push_back(l);
                ch = 0;
            }
            else if (ch == 1)
            {
                cout << "Áveskite normalø paþymá (tarp 1 ir 10)... " << endl;
                y--;
            }
            ch = 1;
        }
        }
        l = 5;
        cout << "Egzamino paþymá ávesite ar sugeneruoti?" << endl << "generavimui spauskite 1, kitu atveju, spauskite 0. ";
        for(int q = 0; q < 1; q++)
        {
            cin >> l;
            if (cin.fail() && ((l != 1) || (l != 0)))
            {
                cin.clear();
                cin.ignore();
                cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                q--;
            }
        }
        if(l == 1)
        {
            t->egzas = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
            t->egzas = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
        }
        else
        {
            cout << "Áveskite studento egzamino paþymá: ";
            for(int y = 0; y < 1; y++)
            {
                cin >> l;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Kazka blogai ivedei, bandyk vel... " << endl;
                    y--;
                }
                if((l < 0) || (l > 11))
                {
                    cout << "Ávedëte neteisingà egzamino vertinimà, jis turëtø bûti ðiame intervale (1 - 10)," << endl << "Áveskite ið naujo - ";
                    y--;
                }
                if (y == 0) n->egzas = l;
            }
        }

    }
    t->next = NULL;
}

void skaiciavimai()
{
    t = h;
    int lm;
    double vid, laik, tik = 0, med;
    while (tik == 0)
    {
        laik = 0;
        vid = 0;
        if(t->nd.empty() == 0)
        {
            for(int i = 0; i < t->nd.size(); i++)
            {
                vid = vid + t->nd.at(i);
                laik++;
            }
            vid = vid / laik;
        }
        t->galvid = vid * 0.4 + t->egzas*0.6;
        if(t->nd.empty() == 0)
        {
            lm = t->nd.size();
            sort(t->nd.begin(), t->nd.end());
            if(lm%2 != 1)
            {
                med = (t->nd.at(lm/2) + t->nd.at(lm/2-1))/2;
            }
            else med = t->nd.at(lm/2);
            t->galmed = med * 0.4 + t->egzas * 0.6;
        }
        if(t->next == NULL) tik++;
        if(t->next != NULL) t = t->next;
    }
}

void spausdinimas()
{
    t =h;
    cout << "Vardas";
    if(ilgvardas > 8)
        for(int i = 0; i < ilgvardas - 6; i++)
    {
        cout << " ";
    }
    else cout << "  ";
    cout << "Pavarde";
    if(ilgpavarde > 9)
        for(int i = 0; i < ilgpavarde - 7; i++)
    {
        cout << " ";
    }
    else cout << "  ";
    if(galutinis == "vidurkis") cout << "Galutinis (vid.) " << endl;
    else cout << "Galutinis (med.)" << endl;
    for(int i = 0; i < ilgvardas + ilgpavarde+20; i++)
    {
        cout << "-";
    }
    cout << endl;
    t = h;
    while (t->next != NULL)
    {
        cout << t->vardas;
        if(ilgvardas > t->vardas.length() + 2)
        {
            for(int i = 0; i < ilgvardas - t->vardas.length(); i++)
            {
                cout << " ";
            }
        }
        else cout << "  ";
        if((t->vardas.length() == ilgvardas-2) && (t->vardas.length()<6))
        {
            for(int i = 0; i < 6-t->vardas.length(); i++)
            {
                cout << " ";
            }
        }
        cout << t->pavarde;
        if(ilgpavarde > t->pavarde.length() +2)
        {
            for(int i = 0; i < ilgpavarde - t->pavarde.length(); i++)
            {
                cout << " ";
            }
        }
        else cout << "  ";
        if((t->pavarde.length() == ilgpavarde-2) && (t->pavarde.length()<7))
        {
            for(int i = 0; i < 7-t->pavarde.length(); i++)
            {
                cout << " ";
            }
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        if(galutinis == "vidurkis") cout << t->galvid << endl;
        else cout << t->galmed << endl;
        t = t->next;
    }
        cout << t->vardas;
        if(ilgvardas > t->vardas.length() + 2)
        {
            for(int i = 0; i < ilgvardas - t->vardas.length(); i++)
            {
                cout << " ";
            }
        }
        else cout << "  ";
        if((t->vardas.length() == ilgvardas-2) && (t->vardas.length()<6))
        {
            for(int i = 0; i < 6-t->vardas.length(); i++)
            {
                cout << " ";
            }
        }
        cout << t->pavarde;
        if(ilgpavarde > t->pavarde.length() +2)
        {
            for(int i = 0; i < ilgpavarde - t->pavarde.length(); i++)
            {
                cout << " ";
            }
        }
        else cout << "  ";
        if((t->pavarde.length() == ilgpavarde-2) && (t->pavarde.length()<7))
        {
            for(int i = 0; i < 7-t->pavarde.length(); i++)
            {
                cout << " ";
            }
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        if(galutinis == "vidurkis") cout << t->galvid << endl;
        else cout << t->galmed << endl;
}

int main()
{
    system("chcp 1257");
    DuomenuIvedimas();
    if(galutinis == "pabaiga") return 0;
    skaiciavimai();
    cout << "Áveskite, kà norësite matyti galutinëje ataskaitoje: galutiná vertinimà paskaièiuotà naudojant vidurká ar medianà?" << endl << "Atitinkamai Áveskite (\"mediana\" arba \"vidurkis\") ";
    for(int i = 0; i < 1; i++)
    {
        cin >> galutinis;
        if((galutinis != "mediana")  && (galutinis != "vidurkis"))
        {
            cout << "Blogai ávedëte, áveskite dar kartà... " << endl;
            i--;
        }
    }
    spausdinimas();
    return 0;
}
