# Objektinis-programavimas
Programa, kuri apskaičiuoja studentų galutinius rezultatus pagal vidurkį ir pagal medianą. Pagal meniu vartotojas gali pasirinkti, ar jis nori visus studentų duomenis įrašyti pats, ar kad dalis studentų duomenų (studentų pažymius) arba visi duomenys (vardus, pavardes ir pažymius) būtų generuojami.

**V0.4 versijos testavimai**

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

**V1.0 versijos testavimai**

### Testavimo sistemos parametrai: 
- CPU: 3.4 GHz, 4 branduoliai
- RAM: 3200 MT/s, 16 GB
- SSD: 512 GB

Kiekvienai lentelei imami 3 testų duomenys ir pateikiamas jų vidurkis, matuojamas sekundėmis

***Vektorių spartos analizė su 1000, 10000, 100000, 1000000 ir 10000000 dydžio failais***

| Failų dydžiai | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Failo nuskaitymas | 0,005600733 | 0,029518033 | 0,435859667 | 3,56562 | 41,54203333 |
| Rikiavimas | 0,0007025 | 0,006810833 | 0,0827156 | 0,931385667 | 11,8154 |
| Skirstymas į 2 kategorijas | 0,000400167 | 0,005733233 | 0,036472033 | 0,348283667 | 3,673683333 |
| Iš viso | 0,007497033 | 0,0426005 | 0,555712 | 4,846136667 | 57,01153333 |

***List spartos analizė su 1000, 10000, 100000, 1000000 ir 10000000 dydžio failais***

| Failų dydžiai | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Failo nuskaitymas | 0,004109367 | 0,0258542 | 0,370875333 | 3,66187 | 41,88056667 |
| Rikiavimas | 0,0002647 | 0,004726267 | 0,0478411 | 0,723928333 | 11,67033333 |
| Skirstymas į 2 kategorijas | 0,000436533 | 0,003955433 | 0,0539726 | 0,462945667 | 5,218796667 |
| Iš viso | 0,005440133 | 0,035286667 | 0,473769333 | 4,84954 | 58,77096667 |

***Deque spartos analizė su 1000, 10000, 100000, 1000000 ir 10000000 dydžio failais***

| Failų dydžiai | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Failo nuskaitymas | 0,003991767 | 0,0269215 | 0,389101 | 3,6245 | 41,3559 |
| Rikiavimas | 0,0009713 | 0,008097533 | 0,103303233 | 1,228936667 | 15,94126667 |
| Skirstymas į 2 kategorijas | 0,000363267 | 0,002833733 | 0,0256732 | 0,280710667 | 3,74385 |
| Iš viso | 0,005840733 | 0,038334633 | 0,518905333 | 5,13525 | 61,04193333 |

Išvados: didesnės apimties failų testavime galime įžvelgti, jog programos, naudojančios vector, veikia truputį sparčiau, tačiau mažesnės apimties failų testavime geriausiai pasirodė list naudojusios programos.