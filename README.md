# Objektinis-programavimas

## V1.1 versija

Kiekvienai lentelei imami 3 testų duomenys ir pateikiamas jų vidurkis, matuojamas sekundėmis. Testui atlikti buvo naudoti **vector** tipo konteineriai, atlikti tyrimai su skirtingomis optimizavimo vėliavėlėmis - **o1**, **o2** ir **o3**

**Klasių analizė**
| Failų dydžiai | 100000 dydžio failas | 1000000 dydžio failas |
| -------- | -------- | -------- |
| Failo nuskaitymas | 0,178971333 | 1,711526667 |
| Rikiavimas | 0,247536 | 3,258963333 |
| Skirstymas į 2 kategorijas | 0,0115029 | 0,118587333 |
| Spausdinimas | 0,149683 | 1,124083333 |
| Iš viso | 0,590147 | 6,214986667 |

**Struktūrų analizė**

| Failų dydžiai | 100000 dydžio failas | 1000000 dydžio failas |
| -------- | -------- | -------- |
| Failo nuskaitymas | 0,153855667 | 3,47111 |
| Rikiavimas | 0,0717167 | 0,896167333 |
| Skirstymas į 2 kategorijas | 0,013489367 | 0,237404333 |
| Spausdinimas | 0,122633667 | 1,14252 |
| Iš viso | 0,363875333 | 5,74894 |


***Optimizavimo vėliavėlių analizė***

Matuojamas tik bendras programos veikimo laikas

**Klasių analizė**

| Failų dydžiai | 100000 dydžio failas | 1000000 dydžio failas |
| -------- | -------- | -------- |
| O1 | 0,453891 | 4,51037 |
| O2 | 0,460904667 | 4,501266667 |
| O3 | 0,470426 | 4,508686667 |

