# Objektinis-programavimas
Programa, kuri apskaičiuoja studentų galutinius rezultatus pagal vidurkį ir pagal medianą. Pagal meniu vartotojas gali pasirinkti, ar jis nori visus studentų duomenis įrašyti pats, ar kad dalis studentų duomenų (studentų pažymius) arba visi duomenys (vardus, pavardes ir pažymius) būtų generuojami.

### V0.4 versijos testavimai

Programa gali generuoti failus su nurodytu duomenų kiekiu, nuskaityti failus, duomenis išskirstyti į gerai ir prastai besimokančių studentų sąrašus bei juos atspausdinti į skirtingus failus.

1.

1000 dydžio failą sugeneruoti vidutiniškai užtruko 0.0029793 s

10000 dydžio failą sugeneruoti vidutiniškai užtruko 0.0167226 s

100000 dydžio failą sugeneruoti vidutiniškai užtruko 0.178187 s

1000000 dydžio failą sugeneruoti vidutiniškai užtruko 2.021443 s

10000000 dydžio failą sugeneruoti vidutiniškai užtruko 9.25826 s


![alt text](<Screenshot 2026-03-12 231917.png>)
![alt text](<Screenshot 2026-03-12 232126.png>) 
![alt text](<Screenshot 2026-03-12 232156.png>)

2.

1000 dydžio failą nuskaityti, suskirstyti į dvi kategorijas ir atspausdinti į atskirus failus vidutiniškai užtruko 0.1699 s

10000 dydžio failą nuskaityti, suskirstyti į dvi kategorijas ir atspausdinti į atskirus failus vidutiniškai užtruko 0.0948 s

100000 dydžio failą nuskaityti, suskirstyti į dvi kategorijas ir atspausdinti į atskirus failus vidutiniškai užtruko 0.7442 s

1000000 dydžio failą nuskaityti, suskirstyti į dvi kategorijas ir atspausdinti į atskirus failus vidutiniškai užtruko 4.9046 s

10000000 dydžio failą nuskaityti, suskirstyti į dvi kategorijas ir atspausdinti į atskirus failus vidutiniškai užtruko 69.558 s


![alt text](<Screenshot 2026-03-12 230500.png>)
![alt text](<Screenshot 2026-03-12 230216.png>)
![alt text](<Screenshot 2026-03-12 225838.png>)

### V1.0 versijos testavimai

**Testavimo sistemos parametrai:** 
- 
- 
- 

Kiekvienai lentelei imami 3 testų duomenys ir pateikiamas jų vidurkis, matuojamas sekundėmis

***Vektorių spartos analizė su 1000, 10000, 100000, 1000000 ir 10000000 dydžio failais***
| | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| ---- | ---- |
| Failo nuskaitymas | 0,005600733 | 0,029518033 | 0,435859667 | 3,56562 | 41,54203333 |
| Rikiavimas | 0,0007025 | 0,006810833 | 0,0827156 | 0,931385667 | 11,8154 |
| Skirstymas į 2 kategorijas | 0,000400167 | 0,005733233 | 0,036472033 | 0,348283667 | 3,673683333 |
| Iš viso | 0,007497033 | 0,0426005 | 0,555712 | 4,846136667 | 57,01153333 |
