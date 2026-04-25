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

**100 000 dydžio failas**

| Implementacija | Build flag | Testo vykdymo laikas | .exe failo dydis |
| -------- | -------- | -------- | -------- |
| CLASS | O1 | 0,453891 | 347 KB |
| CLASS | O2 | 0,460904667 | 327 KB |
| CLASS | O3 | 0,470426 | 352 KB |
| STRUCT | O1 | 0,402349667 | 352 KB |
| STRUCT | O2 | 0,378048667 | 319 KB | 
| STRUCT | O3 | 0,387034667 | 334 KB | 

**1 000 000 dydžio failas**

| Implementacija | Build flag | Testo vykdymo laikas | .exe failo dydis |
| -------- | -------- | -------- | -------- |
| CLASS | O1 | 4,51037 | 347 KB |
| CLASS | O2 | 4,501266667 | 327 KB |
| CLASS | O3 | 4,508686667 | 352 KB |
| STRUCT | O1 | 5,888936667 | 352 KB |
| STRUCT | O2 | 5,683196667 | 319 KB |
| STRUCT | O3 | 5,554806667 | 334 KB |

Matome, jog be optimizavimo vėliavėlių programos su klasėmis veikdavo truputį lėčiau negu su struktūromis, tačiau su optimizavimo vėliavėlėmis didesnės apimties failai apdorojami greičiau pasitelkiant klases.

![alt text](<Screenshot 2026-04-03 002301.png>) 
![alt text](<Screenshot 2026-04-03 002413.png>)


## V1.2 versija

| Metodas | Paskirtis |
| -------- | -------- |
| Default konstruktorius | Automatiškai priskiria reikšmes |
| Konstruktorius su parametrais | Priskiria specifines reikšmes |
| Getteriai | Grąžina tam tikro vieno parametro reikšmę |
| Kopijavimo konstruktorius | Nukopijuoja visas tam tikro objekto reikšmes |
| Kopijavimo priskyrimas | Nukopijuoja visas tam tikro objekto reikšmes (skirtumas toks, kad jau yra sukurtas default objektas, kuriam priskiriamos kito objekto reikšmės pasitelkiant = ženklą) |
| Move konstruktorius | Perkelia visas vieno objekto reikšmes į kitą objektą ir ištrina pirmojo reikšmes |
| Move priskyrimas | Perkelia visas vieno objekto reikšmes į kitą objektą ir ištrina pirmojo reikšmes (skirtumas toks, jog jau yra sukurtas default objektas, kuriam priskiriamos kito objekto reikšmės pasitelkiant = ženklą) |
| Destruktorius | Ištrina objektui priskirtas reikšmes |
| Įvesties operatorius | Leidžia iš pasirinkto srauto nuskaityti vieno objekto duomenis |
| Išvesties operatorius | Leidžia į pasirinktą srautą įrašyti vieno objekto duomenis |

Perdengtas įvedimo operatorius operator>> turi nuskaityti duomenis iš srauto ir užpildyti objektą.

Perdengtas išvesties operatorius operator<< turi gražiai suformatuoti studento informaciją į tekstinį srautą.

![alt text](<Screenshot 2026-04-24 015915.png>)

## V1.5 versija

Sukurta bazinė klasė **Zmogus**, iš kurios išvesta klasė **Studentas**.

Klasė **Zmogus** yra abstrakti - tai reiškia, jog jos objektų kūrimas yra negalimas, galima kurti tik jos derived klasių objektus, šiuo atveju, **Studentas** klasės objektus.

![alt text](<Screenshot 2026-04-25 222104.png>)

Visi v1.2 versijoje realizuoti testai veikia su dabartine derived klase **Studentas**.

![alt text](<Screenshot 2026-04-25 221321.png>)
