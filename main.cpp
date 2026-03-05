#include "funkcijos.h"
int main()
{
    srand(time(NULL));
    vector<Studentas> studentai;
    
    cout<<"Spauskite 'f', jei norite, kad duomenys butu nuskaitomi is failo arba 'i', kad juos ivestumete patys"<<endl;
    char a;
    while(true)
    {
        try
        {
            cin>>a;
            if(cin.fail() || (a!='f' && a!='i'))
                throw std::runtime_error("Iveskite 'f' arba 'i': ");

            cin.ignore(1000, '\n');
            break;
        }
        catch(const std::runtime_error& e)
        {
            cerr<<"Klaida! "<<e.what()<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    if(a=='f')
        skaitymas_is_failo(studentai);  
    else ivedimas(studentai);

    rikiavimas(studentai);
    
    spausdinimas(studentai);

    return 0;
}