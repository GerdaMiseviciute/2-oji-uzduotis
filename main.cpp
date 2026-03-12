#include "funkcijos.h"
int main()
{
    srand(time(NULL));
    vector<Studentas> studentai;

    pasirinkimas(studentai);
    
    vector<Studentas> tinginiai;
    vector<Studentas> darbstuoliai;
    dalinimas_i_kategorijas(studentai, tinginiai, darbstuoliai);

    if(tinginiai.size()>1)
    {
        cout<<"Prastai besimokanciu studentu rikiavimas"<<endl;
        rikiavimas(tinginiai);
    }
    
    if(darbstuoliai.size()>1)
    {
        cout<<"Gerai besimokanciu studentu rikiavimas"<<endl;
        rikiavimas(darbstuoliai);
    }

    cout<<"Prastai besimokanciu studentu spausdinimas"<<endl;
    spausdinimas(tinginiai);
    cout<<"Gerai besimokanciu studentu spausdinimas"<<endl;
    spausdinimas(darbstuoliai);

    return 0;
}