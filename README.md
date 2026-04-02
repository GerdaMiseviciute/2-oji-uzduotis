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




***Vector spartos analizė su 1000, 10000, 100000, 1000000 ir 10000000 dydžio failais***

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

Išvados: didesnės apimties failų testavime galime įžvelgti, jog programos, naudojančios **vector**, veikia truputį sparčiau, tačiau mažesnės apimties failų testavime geriausiai pasirodė **list** naudojusios programos.


**Rūšiavimo į kategorijas strategijų testavimo analizė**

***Vector analizė***

| Failų dydžiai | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Pirma strategija | 0,000213267 | 0,0025555 | 0,028144167 | 0,315669667 | 2,113413333|
| Antra strategija | 0,0005327 | 0,007126233 | 0,091599833 | 1,473003333 | 14,38853333 |
| Trečia strategija | 0,0001646 | 0,001723133 | 0,019166867 | 0,271909 | 1,876206667 |

***List analizė***

| Failų dydžiai | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Pirma strategija | 0,000247133 | 0,003962933 | 0,023656733 | 0,378496667 | 3,156196667 |
| Antra strategija | 0,000263967 | 0,002993433 | 0,054836967 | 1,376689667 | 13,25733333 |
| Trečia strategija | 0,0003482 | 0,003692967 | 0,037266233 | 0,484794667 | 3,54157 |

***Deque analizė***

| Failų dydžiai | 1000 dydžio failas | 10000 dydžio failas | 100000 dydžio failas | 1000000 dydžio failas | 10000000 dydžio failas |
| -------- | -------- | -------- | -------- | -------- | -------- |
| Pirma strategija | 0,0001793 | 0,0021333 | 0,017161767 | 0,200608333 | 1,715253333 |
| Antra strategija | 0,000728067 | 0,007970833 | 0,112796333 | 1,548866667 | 17,72823333 |
| Trečia strategija | 0,0002595 | 0,0033179 | 0,024069333 | 0,271357667 | 2,25674 |

Išvados: matome, jog antra strategija nepalanki **vector**, **list** ir **deque** programoms jų spartos atžvelgiu. **List** ir **deque** sparčiausiai veikia naudodami pirmą strategiją, o **vector** - trečią.

![alt text](<Screenshot 2026-03-27 234332.png>) 
![alt text](<Screenshot 2026-03-27 233527.png>)


## Naudojimo instrukcijos ##
1. Įsitikinkite, jog jūsų įrenginyje yra įdiegta CMake
- Atsidarykite Command Prompt arba PowerShell
- Įveskite: **cmake --version**
- Jei terminalas parodo versiją, viskas gerai. Jei ne, reikia įsidiegti CMake
2. Raskite **run.bat** failą (jis turi būti pagrindiniame projekto kataloge)
3. Paleiskite **run.bat** failą
- *1 variantas:* dukart spustelėkite failą
- *2 variantas:* atidarykite PowerShell arba Command Prompt, nueikite į projekto katalogą ir įveskite **.\run.bat**
