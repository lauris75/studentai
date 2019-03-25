# Studentų duomenų apdorojimas

## Programos tikslas

Programa perskaito pateiktus arba įvestus studentų duomenis, juos apdoroja ir išveda į tvarkingą failą.

### Naudojimasis programa

Norint programai pateikti studentų sąrašą faile apdorojimui, jis turi būti programos aplankale pavadinimu kursiokai.txt
Pirmoje eilutėje turi būti parašyti stulpelių pavadinimai: Vardas Pavardė ND1 ND2..... Egzaminas
Visose kitose eilutėse (atitinkamai pagal stulpelių pavadinimus) surašyti studentų duomenys.
Stulpeliai gali būti neišlygiuoti, tačiau atskiri duomenys (vardas ir pavardė, skiringų namų darbų rezultatai, turi būti atskirti tarpu ar kitu atskyrimo ženklu.
Įvedant duomenis per konsolę, įvedimas aiškiai paaiškintas viso įvedimo metu, net ir įvedus ką nors klaidingai.

## Rezultatai

### Failų kūrimas

Studentų duomenų generavimo ir išvedimo laikai, priklausant nuo generuojamų studentų skaičiaus yra tokie:

Generuojant 10 studentų sąrašą prireikė 2998000 nanosekundžių (~0,003 sekundės).
Generuojant 100 studentų sąrašą prireikė 4983000 nanosekundžių (~0,005 sekundės).
Generuojant 1000 studentų sąrašą prireikė 41885000 nanosekundžių (~0,042 sekundės).
Generuojant 10000 studentų sąrašą prireikė 297219000 nanosekundžių (~0,297 sekundės).
Generuojant 100000 studentų sąrašą prireikė 3202049000 nanosekundžių (~3,2 sekundės).
Generuojant 1000000 studentų sąrašą prireikė 33857341000 nanosekundžių (~33,857 sekundės).

Ps. Reminder -  1 sekundė = 1 * 1 000 000 000 nanosekundžių

### Pirma strategija

#### Neišlaikiusius perkeliant į naują failą ir ištrinant iš senojo

Skaičiuota naudojant 10000 studentų, kurių kiekvienas turėjo 7-tynių namų darbų įvertinimus.

Naudojant std::vector 15977537000 nanosekundžių (~16 sekundžių). (Vektoriui yra labai skausminga elementų naikinimo funkcija)
Naudojant std::list   280288000 nanosekundžių (~0,28 sekundės).
Naudojant std::deque  377954000 nanosekundžių (~0,378 sekundės).

### Antra strategija

#### Peržiūrime nuskanuotų studentų konteinerį ir skirstome į du naujus konteinerius (užimama daugiau atminties)

Skaičiuota naudojant tuos pačius 10000 studentų, kurių kiekvienas turėjo 7-tynių namų darbų įvertinimus.

Naudojant std::vector 467261000 nanosekundžių (~0,467 sekundės).
Naudojant std::list   313159000 nanosekundžių (~0,313 sekundės).
Naudojant std::deque  478720000 nanosekundžių (~0,479 sekundės).

## Įdiegimas (Unix)
- https://github.com/lauris75/studentai/releases/tag/v1.0
- make(terminale)
- ./main
-
- Nepavykstant šiam būdui, visad bus galima parsisiųstį vientisą failą ir kompiliuoti tik jį
- (https://github.com/lauris75/studentai/releases/tag/PapildomasNaudojimoB%C5%ABdas)
- 
## Versijos

### [v1.0](https://github.com/lauris75/studentai/releases/tag/v1.0) - (2018-03-25)
**Pridėta**
- Skirtingos dalijimo strategijos
- Greičio analizė su pirma strategija
    
- Naudojant std::vector 15977537000 nanosekundžių (~16 sekundžių). (Vektoriui yra labai skausminga elementų naikinimo funkcija)
- Naudojant std::list   280288000 nanosekundžių (~0,28 sekundės).
- Naudojant std::deque  377954000 nanosekundžių (~0,378 sekundės).
    
- Greičio analizė su antra strategija
    
- Naudojant std::vector 467261000 nanosekundžių (~0,467 sekundės).
- Naudojant std::list   313159000 nanosekundžių (~0,313 sekundės).
- Naudojant std::deque  478720000 nanosekundžių (~0,479 sekundės).
    

**Koreguota**
- ReadMe failas
- Visos funkcijos pritaikytos naudoti anksčiau minėtus konteinerius
- Panaikintas anksčiau naudotas linked list;

### [v0.5](https://github.com/lauris75/studentai/releases/tag/v.0.5) - (2018-03-12)
**Pridėta**
- Testai su skirtingais konteineriais(išrūšiuojant studentų duomenis pačiam konteineryje pagal vidurkį)

- Naudojant std::vector 465755000 nanosekundžių (~0,466 sekundės).
- Naudojant std::list   347234000 nanosekundžių (~0,347 sekundės).
- Naudojant std::deque  3611660000 nanosekundžių (~0,361 sekundės).

### [v0.4](https://github.com/lauris75/studentai/releases/tag/v.0.4) - (2018-03-03)
**Pridėta**
- Atsitiktinių failų generavimas
- Studentų rušiavimas į atskirus failus
- Greičio analizė
- Generuojant 10 studentų sąrašą prireikė 2998000 nanosekundžių (~0,003 sekundės).
- Generuojant 100 studentų sąrašą prireikė 4983000 nanosekundžių (~0,005 sekundės).
- Generuojant 1000 studentų sąrašą prireikė 41885000 nanosekundžių (~0,042 sekundės).
- Generuojant 10000 studentų sąrašą prireikė 297219000 nanosekundžių (~0,297 sekundės).
- Generuojant 100000 studentų sąrašą prireikė 3202049000 nanosekundžių (~3,2 sekundės).
- Generuojant 1000000 studentų sąrašą prireikė 33857341000 nanosekundžių (~33,857 sekundės).

### [v0.3](https://github.com/lauris75/studentai/releases/tag/v.0.3) - (2018-02-24)
**Pridėta**
- Exceptionų handlinimas (cin.fail())

**Koreguota**
- Kodas išskirstytas į atskirus failus

### [v0.2](https://github.com/lauris75/studentai/releases/tag/v.0v2) - (2018-02-17)
**Pridėta**
- Nuskaitymas iš failų
- Studentų rušiavimas (pagal vardus)
- Failai išvedant sudedami į tvarkingus stulpelius

### [v0.1](https://github.com/lauris75/studentai/releases/tag/untagged-9b4ad8c4d659ff6c0e8e) - (2018-02-17)
***Pridėta***
- Pirminė programos versija
- Nuskaito vartotojo įvestus duomenis, juos apdoruoja, išveda į atskirą failą.
- Yra galimybė generuoti namų darbų ir egzamino pažymius.
