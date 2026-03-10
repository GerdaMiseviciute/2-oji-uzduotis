#include "funkcijos.h"
int main()
{
    srand(time(NULL));
    vector<Studentas> studentai;
    cout<<"Spauskite 'g', jei norite, kad duomenys butu generuojami i faila arba 't', kad testumete programos veikima"<<endl;
    char c=raides('g', 't');
    if(c=='g')
    {
        failu_generavimas(1000);
    }


    cout<<"Spauskite 'f', jei norite, kad duomenys butu nuskaitomi is failo arba 'i', kad juos ivestumete patys"<<endl;
    char a=raides('f', 'i');
    
    if(a=='f')
        skaitymas_is_failo(studentai);  
    else ivedimas(studentai);

    rikiavimas(studentai);
    
    spausdinimas(studentai);

    return 0;
}