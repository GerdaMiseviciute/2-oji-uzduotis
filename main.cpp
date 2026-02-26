#include "funkcijos.h"
int main()
{
    srand(time(NULL));
    vector<Studentas> studentai;
    
    cout<<"Spauskite 'f', jei norite, kad duomenys butu nuskaitomi is failo arba 'i', kad juos ivestumete patys"<<endl;
    char a;
    while(!(cin>>a) || (a!='f' && a!='i'))
    {
        cout<<"Įveskite 'f' arba 'i': "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if(a=='f')
        skaitymas_is_failo(studentai);  
    else ivedimas(studentai);

    rikiavimas(studentai);
    
    spausdinimas(studentai);

    return 0;
}