#include "funkcijos.h"
int main()
{
    srand(time(NULL));
    vector<Studentas> studentai;

    int choice;
    cout<<"===Meniu==="<<endl;
    cout<<"1. Iprastas programos veikimas"<<endl;
    cout<<"2. Programos testavimas 1 (failų generavimas)"<<endl;
    cout<<"3. Programos testavimas 2 (generuotu failu apdorojimas)"<<endl;
    while(true)
    {
        try
        {
            cin>>choice;
            if(cin.fail() || choice<1 || choice>3)
                throw std::runtime_error("Iveskite skaiciu 1-3: ");

            cin.ignore(1000, '\n');
            break;
        }
        catch(const std::exception& e)
        {
            cerr<<"Klaida! "<<e.what()<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    switch(choice)
    {
        case 1:
            skaitymas(studentai);
            break;
        case 2:
            pazymiu_generavimas(studentai);
            break;
        case 3:
            generuoti_viska(studentai);
            break;
    }

    cout<<"Spauskite 'g', jei norite, kad duomenys butu generuojami i faila arba 't', kad testumete programos veikima"<<endl;
    char c=raides('g', 't');
    if(c=='g')
    {
        failu_generavimas(1000);
        failu_generavimas(10000);
        failu_generavimas(100000);
        failu_generavimas(1000000);
        failu_generavimas(10000000);
    }


    cout<<"Spauskite 'f', jei norite, kad duomenys butu nuskaitomi is failo arba 'i', kad juos ivestumete patys"<<endl;
    char a=raides('f', 'i');
    
    if(a=='f')
        skaitymas_is_failo(studentai);  
    else ivedimas(studentai);

    vector<Studentas> tinginiai;
    vector<Studentas> darbstuoliai;
    dalinimas_i_kategorijas(studentai, tinginiai, darbstuoliai);

    cout<<"Prastai besimokanciu studentu rikiavimas"<<endl;
    rikiavimas(tinginiai);
    cout<<"Gerai besimokanciu studentu rikiavimas"<<endl;
    rikiavimas(darbstuoliai);
    
    cout<<"Prastai besimokanciu studentu spausdinimas"<<endl;
    spausdinimas(tinginiai);
    cout<<"Gerai besimokanciu studentu spausdinimas"<<endl;
    spausdinimas(darbstuoliai);

    return 0;
}