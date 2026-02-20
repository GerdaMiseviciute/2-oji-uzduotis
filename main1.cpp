#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <numeric>
using std::cin;
using std::cout;
using std::vector;
using std::left;
using std::setw;
using std::string;
using std::endl;
using std::fixed;
using std::setprecision;
using std::sort;
using std::accumulate;

struct Studentas
{
    string vardas, pavarde;
    int masyvo_dydis=10;
    int* pazymiai = new int[masyvo_dydis];
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};
void skaiciavimai(Studentas& A, int pazymiu_masyvo_dydis)
{
    sort(A.pazymiai, A.pazymiai+pazymiu_masyvo_dydis);
    if(pazymiu_masyvo_dydis==0)
    {
        A.galutinis=A.egzaminas*0.6;
        A.galutinis_mediana=A.egzaminas*0.6;
    }
    else 
    {
        double vid=accumulate(A.pazymiai, A.pazymiai+pazymiu_masyvo_dydis, 0.0)/pazymiu_masyvo_dydis;
        A.galutinis=vid*0.4+A.egzaminas*0.6;
        if(pazymiu_masyvo_dydis%2==1)
            A.galutinis_mediana=A.pazymiai[pazymiu_masyvo_dydis/2]*0.4+A.egzaminas*0.6;
        else A.galutinis_mediana=(A.pazymiai[pazymiu_masyvo_dydis/2]+A.pazymiai[pazymiu_masyvo_dydis/2-1])/2.0*0.4+A.egzaminas*0.6;
    }
}
void skaitymas(Studentas*& studentai, int& m, int& size)
{
    for (int i=0; ; i++)
    {
        Studentas A;
        int a;
        cout<<"Jei norite įvesti naujo studento duomenis, spauskite 1, jei baigėte žmonių įvedimą, spauskite 0: ";
        while(!(cin>>a) || (a!=0 && a!=1))
        {
            cout<<"Įveskite 1 arba 0: "<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if(a==1)
        {
            cout<<i+1<<" studentas:"<<endl;
            cout<<"Įvesk studento vardą: ";
            cin.ignore();
            getline(cin, A.vardas);
            cout<<endl<<"Įvesk studento pavardę: ";
            getline(cin, A.pavarde);
            cout<<endl;
            int pazymys, pazymiu_masyvo_dydis=0;
            for(int j=0; ;j++)
            {
                cout<<"Įveskite "<<j+1<<"-ąjį pažymį (jei įvedėte visus pažymius, spauskite 0): ";
                while(!(cin>>pazymys) || pazymys<0 || pazymys>10)
                {
                    cout<<"Įveskite skaičių 1-10: "<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                if(pazymys==0)
                    break;
                else 
                {
                    if(pazymiu_masyvo_dydis==A.masyvo_dydis)
                    {
                        A.masyvo_dydis*=2;
                        int* naujas_masyvas=new int[A.masyvo_dydis];
                        for(int z=0; z<pazymiu_masyvo_dydis; z++)
                        {
                            naujas_masyvas[z]=A.pazymiai[z];
                        }
                        delete [] A.pazymiai;
                        A.pazymiai=naujas_masyvas;
                    }
                    A.pazymiai[pazymiu_masyvo_dydis]=pazymys;
                    pazymiu_masyvo_dydis++;
                }
            }
            cout<<"Įveskite egzamino rezultatą: ";
            while(!(cin>>A.egzaminas) || A.egzaminas<1 || A.egzaminas>10)
            {
                cout<<"Įveskite skaičių 1-10: "<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            skaiciavimai(A, pazymiu_masyvo_dydis);
            if(size==m)
            {
                m*=2;
                Studentas* naujas_masyvas=new Studentas[m];
                for(int z=0; z<size; z++)
                {
                    naujas_masyvas[z]=studentai[z];
                }
                delete [] studentai;
                studentai=naujas_masyvas;
            }
            studentai[size]=A;
            size++;
        }
        else break;
    }
}
void pazymiu_generavimas(Studentas*&studentai, int& m, int& size)
{
    for(int i=0; ; i++)
    {
        int a;
        cout<<"Jei norite įvesti naujo studento duomenis, spauskite 1, jei baigėte žmonių įvedimą, spauskite 0: ";
        while(!(cin>>a) || (a!=0 && a!=1))
        {
            cout<<"Įveskite 1 arba 0: "<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if(a==1)
        {
            Studentas A;
            cout<<i+1<<" studentas:"<<endl;
            cout<<"Įvesk studento vardą: ";
            cin.ignore();
            getline(cin, A.vardas);
            cout<<endl<<"Įvesk studento pavardę: ";
            getline(cin, A.pavarde);
            cout<<endl;
            int n=rand()%20+1;
            for(int j=0; j<n; j++)
            {
                if(j==A.masyvo_dydis)
                {
                    A.masyvo_dydis*=2;
                    int* naujas_masyvas=new int[A.masyvo_dydis];
                    for(int z=0; z<j; z++)
                    {
                        naujas_masyvas[z]=A.pazymiai[z];
                    }
                    delete [] A.pazymiai;
                    A.pazymiai=naujas_masyvas;
                }
                A.pazymiai[j]=rand()%10+1;
            }
            A.egzaminas=rand()%10+1;
            skaiciavimai(A, n);
            if(size==m)
            {
                m*=2;
                Studentas* naujas_masyvas=new Studentas[m];
                for(int z=0; z<size; z++)
                {
                    naujas_masyvas[z]=studentai[z];
                }
                delete [] studentai;
                studentai=naujas_masyvas;
            }
            studentai[size]=A;
            size++;
        }
        else break;
    }
}
void generuoti_viska(Studentas*& studentai, int& m, int& size)
{
    size=rand()%20+1;
    for(int i=0; i<size; i++)
    {
        Studentas a;
        switch(rand()%10)
        {
            case 0: a.vardas="Renata"; break;
            case 1: a.vardas="Jolanta"; break;
            case 2: a.vardas="Lina"; break;
            case 3: a.vardas="Amelija"; break;
            case 4: a.vardas="Sofija"; break;
            case 5: a.vardas="Mantas"; break;
            case 6: a.vardas="Antanas"; break;
            case 7: a.vardas="Rokas"; break;
            case 8: a.vardas="Algirdas"; break;
            case 9: a.vardas="Andrius"; break;
        }
        switch(*a.vardas.rbegin())
        {
            case 's':
                switch(rand()%5)
                {
                    case 0: a.pavarde="Pavardenis1"; break;
                    case 1: a.pavarde="Pavardenis2"; break;
                    case 2: a.pavarde="Pavardenis3"; break;
                    case 3: a.pavarde="Pavardenis4"; break;
                    case 4: a.pavarde="Pavardenis5"; break;
                }
                break;
            default:
                switch(rand()%5)
                {
                    case 0: a.pavarde="Pavardaite1"; break;
                    case 1: a.pavarde="Pavardiene1"; break;
                    case 2: a.pavarde="Pavardyte"; break;
                    case 3: a.pavarde="Pavardaite2"; break;
                    case 4: a.pavarde="Pavardiene2"; break;
                }
                break;
        };
        int n=rand()%20+1;
        for(int j=0; j<n; j++)
        {
            if(j==a.masyvo_dydis)
            {
                a.masyvo_dydis*=2;
                int* naujas_masyvas=new int[a.masyvo_dydis];
                for(int z=0; z<j; z++)
                {
                    naujas_masyvas[z]=a.pazymiai[z];
                }
                delete [] a.pazymiai;
                a.pazymiai=naujas_masyvas;
            }
            a.pazymiai[j]=rand()%10+1;
        }
        a.egzaminas=rand()%10+1;
        skaiciavimai(a, n);
        if(i==m)
        {
            m*=2;
            Studentas* naujas_masyvas=new Studentas[m];
            for(int z=0; z<i; z++)
            {
                naujas_masyvas[z]=studentai[z];
            }
            delete [] studentai;
            studentai=naujas_masyvas;
        }
        studentai[i]=a;
    }
}
void spausdinimas(Studentas*&studentai, int size)
{
    cout<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(20)<<"Galutinis (Vid.)"<<setw(20)<<"Galutinis (Med.)"<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<left<<setw(20)<<studentai[i].vardas<<setw(20)<<studentai[i].pavarde<<setw(20)<<fixed<<setprecision(2)<<studentai[i].galutinis<<setw(20)<<fixed<< setprecision(2)<<studentai[i].galutinis_mediana<<endl;
    }
}
int main()
{
    srand(time(NULL));
    int m=10, size=0;
    Studentas* studentai= new Studentas[m];
    int choice;
    cout<<"===Meniu==="<<endl;
    cout<<"1. Ranka"<<endl;
    cout<<"2. Generuoti pažymius"<<endl;
    cout<<"3. Generuoti studentų vardus, pavardes ir pažymius"<<endl;
    cout<<"4. Baigti darbą"<<endl;
    while(!(cin>>choice) || choice<1 || choice>4)
    {
        cout<<"Įveskite skaičių 1-4: "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    switch(choice)
    {
        case 1:
            skaitymas(studentai, m, size);
            spausdinimas(studentai, size);
            break;
        case 2:
            pazymiu_generavimas(studentai, m, size);
            spausdinimas(studentai, size);
            break;
        case 3:
            generuoti_viska(studentai, m, size);
            spausdinimas(studentai, size);
            break;
        case 4:
            break;
    }
    delete [] studentai;
    return 0;
}