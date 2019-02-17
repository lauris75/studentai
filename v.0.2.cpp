#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fixed;

int ilgvardas = 2, ilgpavarde = 2;
string galutinis = "nieko";
vector<string> vardai;
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

}*h, *n, *t, *h2, *t2, *t3;

void DuomenuIvedimas()
{
    int ran, x, l, k=0, tik, tik2, kiekis, ch = 1;
    cout << "Duomenis �vesite patys, ar nuskaityti i� failo (nuskaitymui para�ykite 0, kitu atveju 1): ";
    for(int i = 0; i < 1; i++)
    {
        cin >> x;
        if(cin.fail() || ((x != 0) && (x != 1)))
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka blogai ivedei, bandyk vel... " << endl;
            i--;
        }
    }
    if(x == 0)
    {
        kiekis = 0;
        char z;
        tik = 0;
        std::ifstream PD ("kursiokai.txt");
        PD >> galutinis >> galutinis >> galutinis;
        while(galutinis[0] == 'N')
        {
            kiekis++;
            PD >> galutinis;
        }
        while(!PD.eof())
        {
            if(tik == 0)
            {
                n = new stud;
                h = n;
                t = n;
                PD >> n->vardas >> n->pavarde;
                if(n->vardas.length() > ilgvardas-2) ilgvardas = n->vardas.length()+2;
                if(n->pavarde.length() > ilgpavarde-2) ilgpavarde = n->pavarde.length()+2;
                for(int i = 0; i < kiekis; i++)
                {
                    PD >> tik2;
                    n->nd.push_back(tik2);
                }
                PD >> n->egzas;
                tik++;
            }
            else
            {
                n = new stud;
                t->next = n;
                t  = n;
                PD >> n->vardas >> n->pavarde;
                if(n->vardas.length() > ilgvardas-2) ilgvardas = n->vardas.length()+2;
                if(n->pavarde.length() > ilgpavarde-2) ilgpavarde = n->pavarde.length()+2;
                for(int i = 0; i < kiekis; i++)
                {
                    PD >> tik2;
                    n->nd.push_back(tik2);
                }
                PD >> n->egzas;
            }
        }
        t->next = NULL;
        PD.close();
    }
    else if(x == 1)
    {
        x = 0;
    cout << "�veskite, keli� student� duomenis �vesite: ";
    for(int i = 0; i < 1; i++)
    {
        cin >> x;
        if(cin.fail() || (x < 0))
        {
            cin.clear();
            cin.ignore();
            cout << "Kazka blogai ivedei, bandyk vel... " << endl;
            i--;
        }
    }
    if(x == 0)
    {
        cout << "Tada n�ra, k� atspausdinti...";
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
        cout << "�veskite studento vard� - ";
        cin >> n->vardas;
        if(n->vardas.length() > ilgvardas-2) ilgvardas = n->vardas.length()+2;
        cout << "�veskite studento pavard� - ";
        cin >> n->pavarde;
        if(n->pavarde.length() > ilgpavarde-2) ilgpavarde = n->pavarde.length()+2;
        cout << "�veskite kiek nor�site �vesti studento \"" << n->vardas << " " << n->pavarde << "\" nam� darb�." << endl << "Jei ne�inote kiek bus nam� darb� ra�ykite -1: " << endl << "Jei norite automati�kai sugeneruoti nam� darb� pa�ymius, spauskite -2: ";
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
                cout << "Nam� darb� negali b�ti ma�iau nei 0... bandyk vel" << endl;
                y--;
            }
        }
        kiekis = 1;
        if (k == -2)
        {
            cout << "Kiek sugeneruoti nam� darb� rezultat�? ";
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
                    cout << "Nam� darb� negali b�ti ma�iau nei 0... bandyk vel" << endl;
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
            cout << "Kai jau b�site �ved� visus nam� darb� �vetinimus, ra�ykite -2" << endl;
            while(k != -2)
            {
                cout << "Nd nr." << kiekis << " �vertinimas = ";
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
                else if(k != -2) cout << "�veskite normal� nam� darb� pa�ym�..." << endl << "Primenu: nor�dami baigti �io studento nam� darb� �vedim�, para�ykite -2" << endl;
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
                cout << "�veskite normal� pa�ym� (tarp 1 ir 10)... " << endl;
                y--;
            }
            ch = 1;
        }
        }
        l = 5;
        cout << "Egzamino pa�ym� �vesite ar sugeneruoti?" << endl << "generavimui spauskite 1, kitu atveju, spauskite 0. ";
        for(int q = 0; q < 1; q++)
        {
            cin >> l;
            if (cin.fail() || ((l != 1) && (l != 0)))
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
        else if(l == 0)
        {
            cout << "�veskite studento egzamino pa�ym�: ";
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
                    cout << "�ved�te neteising� egzamino vertinim�, jis tur�t� b�ti �iame intervale (1 - 10)," << endl << "�veskite i� naujo - ";
                    y--;
                }
                if (y == 0) n->egzas = l;
            }
        }

    }
    t->next = NULL;
    }
}
void rikiavimas()
{
    t = h;
    int kiekis = 1, tik = 0, tik2;
    while(t->next != NULL)
    {
        vardai.push_back(t->vardas);
        t = t->next;
    }
    vardai.push_back(t->vardas);
    kiekis = vardai.size();
    sort(vardai.begin(), vardai.end());
    h2 = h;
    for(int i = 0; i < kiekis; i++)
    {
        t2 = h2;
        tik2 = 0;
        if(t2->vardas == vardai.at(i))
        {
            if(tik == 0)
            {
                h = t2;
                h2 = h->next;
                t = h;
                tik++;
                tik2++;
            }
            else
            {
                t->next = t2;
                t = t2;
                h2 = t->next;
                tik2++;
            }
        }
        while(vardai.at(i) != t2->vardas)
        {
            t3 = t2;
            if(t2->next != NULL) t2 = t2->next;
            else break;
        }
        if((tik == 0) && (tik2 == 0))
        {
            h = t2;
            t = h;
            t3->next = t2->next;
            tik++;
        }
        else if(tik2 == 0)
        {
            t->next = t2;
            t = t->next;
            t3->next = t->next;
        }
    }
    t->next= NULL;
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
    cout << endl;
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
    cout << "Galutinis (vid.) " << "Galutinis (med.)" << endl;
    for(int i = 0; i < ilgvardas + ilgpavarde+45; i++)
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
        cout << t->galvid << "             " << t->galmed << endl;
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
        cout << t->galvid << "             " << t->galmed << endl;
}

int main()
{
    system("chcp 1257");
    DuomenuIvedimas();
    rikiavimas();
    if(galutinis == "pabaiga") return 0;
    skaiciavimai();
    spausdinimas();
    return 0;
}
