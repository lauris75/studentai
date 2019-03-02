#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fixed;

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

int sprendimas()
{
    int x;
    cout << "Norite matuoti programos veikimo greitá, ar jos veikimà?" << endl << "Jei veikimo greitá spauskite 1, kitu atveju 2 - ";
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
    return x;
}

void DuomenuKurimas(int y)
{
    int ran;
    double gal, sum = 0;
    n = new stud;
    h = n;
    t = n;
    n->vardas = "Vardenis1";
    n->pavarde = "Pavardenis1";
    srand(time(NULL));
    for(int i = 0; i < 100; i++)
    {
        ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
        n->nd.push_back(ran);
    }
    ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
    n->egzas = ran;
    for(int i = 0; i < n->nd.size(); i++)
    {
        sum = sum + n->nd.at(i);
    }
    gal = (0.4 * (sum / n->nd.size())) + (0.6 * n->egzas);
    n->galvid = gal;
    for(int i = 0; i < y-1; i++)
    {
        n = new stud;
        t->next = n;
        t = n;
        n->vardas = "Vardenis" + std::to_string(i+2);
        n->pavarde = "Pavardenis" + std::to_string(i+2);
        for(int i = 0; i < 100; i++)
        {
            ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
            n->nd.push_back(ran);
        }
        ran = std::round(1 + (double) rand ()/ RAND_MAX * (10 - 1));
        n->egzas = ran;
        sum = 0;
        for(int i = 0; i < n->nd.size(); i++)
        {
            sum = sum + n->nd.at(i);
        }
        n->galvid = (0.4 * (sum / n->nd.size())) + (0.6 * n->egzas);
    }
    n = new stud;
    t->next = n;
    t = n;
    t->next = NULL;
}

FailuKurimas(int x)
{
    int y=1;
    std::ofstream feil("feilai" + std::to_string(x));
    std::ofstream mldc("malaciai" + std::to_string(x));
    t = h;
    while(t->next!=NULL)
    {
        if(t->galvid < 5) feil << t->vardas << "   " << t->pavarde << "   " << std::setprecision(3) << t->galvid << endl;
        else mldc << t->vardas << "   " << t->pavarde << "   " << std::setprecision(3) << t->galvid << endl;
        t = t->next;
        y++;
    }
    feil.close();
    mldc.close();
}

void DuomenuIvedimas(int &ilgvardas, int &ilgpavarde, string &galutinis)
{
    int ran, x, l, k=0, tik, tik2, kiekis, ch = 1;
    cout << "Duomenis ávesite patys, ar nuskaityti ið failo (nuskaitymui paraðykite 0, kitu atveju 1): ";
    for(int i = 0; i < 1; i++)
    {
        cin >> x;
        if(cin.fail() || ((x != 0) && (x != 1)))
        {
            cin.clear();
            cin.ignore();
            cout << "Kaþka blogai ávedei, bandyk vël... " << endl;
            i--;
        }
    }
    if(x == 0)
    {
        kiekis = 0;
        char z;
        tik = 0;
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
        else
        {
            cout << "Failo aplankale nëra, ásitikinkite, kad jis yra programos aplankale..." << endl;
            DuomenuIvedimas(ilgvardas, ilgpavarde, galutinis);
            return;
        }
    }
    else if(x == 1)
    {
        x = 0;
    cout << "Áveskite, keliø studentø duomenis ávesite: ";
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
}
void rikiavimas(vector<string> &vardai)
{
    t = h;
    int kiekis, tik = 0, tik2;
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

void spausdinimas(int ilgvardas, int ilgpavarde)
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
    cout << endl;
    int y = 1, x = sprendimas();
    clock_t pradzia, pabaiga;
    if(x == 1)
    {
        for(int i = 0; i < 6; i++)
        {
            pradzia = clock();
            y = y * 10;
            cout << endl << "Kuriamas sàraðas ið " << y << " studentø." << endl;
            DuomenuKurimas(y);
            FailuKurimas(i+1);
            pabaiga = clock();
            cout << "Kûrimas uþtruko - " << std::setprecision(4) << 1.0*( pabaiga - pradzia )/ CLOCKS_PER_SEC << " sec." << endl;
        }
    }
    else
    {
        int ilgvardas = 2, ilgpavarde = 2;
        string galutinis = "nieko";
        vector<string> vardai;
        DuomenuIvedimas(ilgvardas, ilgpavarde, galutinis);
        pradzia = clock();
        rikiavimas(vardai);
        if(galutinis == "pabaiga") return 0;
        skaiciavimai();
        spausdinimas(ilgvardas, ilgpavarde);
        pabaiga = clock();
        cout << endl << 1.0*( pabaiga - pradzia )/ CLOCKS_PER_SEC << endl;
    }
    return 0;
}
