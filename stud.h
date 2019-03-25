#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

int sprendimas()
template <typename T1>
void DuomenuNuskaitymas(T1 &stude, int &ilgvardas, int &ilgpavarde)
void DuomenuIvedimas(vector<stud> &stude, int &ilgvardas, int &ilgpavarde)
void DuomenuKurimas(vector<stud> &stude, int y)
bool PagalGal(const stud &a, const stud &b)
bool compare(const stud& a, const stud& b)
template<typename T1, typename T2>
void DuomenuSkirstymas (T1 &stude, T2 &feil)
template<typename T1, typename T2, typename T3>
void DuomenuSkirstymas2 (T1 &stude, T2 &feil, T3 &kiet)
bool Skola (const stud& a)
void TobulintasSkirstymas(vector<stud> &stude, vector<stud> &feilai)
void DuomenuSkirstymasList (list<stud> &stude, list<stud> &feilai)
void DuomenuSkirstymasList2 (list<stud> &stude, list<stud> &feilai, list<stud> &kiet)
template<typename T>
void DuomenuIsvedimas(T stude, int ilgvardas, int ilgpavarde, string k)

#endif // STUD_H_INCLUDED
