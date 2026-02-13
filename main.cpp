#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::left;
using std::setw;
using std::string;
using std::endl;
using std::fixed;
using std::setprecision;

struct Studentas
{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};
void skaiciavimai(int sum, Studentas& A, int n)
{
    sort(A.pazymiai.begin(), A.pazymiai.end());
    if(n=0)
    {
        A.galutinis=A.egzaminas*0.6;
        A.galutinis_mediana=A.egzaminas*0.6;
    }   
    else 
    {
        A.galutinis=sum*1.0/(A.pazymiai.size()*1.0)*0.4+A.egzaminas*0.6;
        if(A.pazymiai.size()%2==1)
            A.galutinis_mediana=A.pazymiai[A.pazymiai.size()/2]*0.4+A.egzaminas*0.6;
        else A.galutinis_mediana=(A.pazymiai[A.pazymiai.size()/2]+A.pazymiai[A.pazymiai.size()/2-1])/2.0*0.4+A.egzaminas*0.6;
    }
}
void skaitymas(vector<Studentas>&studentai, int& m)
{
    cout<<"Įveskite studentų skaičių: "<<endl;
    while(!(cin>>m) || m<1)
    {
        cout<<"Įveskite teigiamą skaičių: "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    for (int i=0; i<m; i++)
    {
        Studentas A;
        cout<<i+1<<" studentas:"<<endl;
        cout<<"Įvesk studento vardą: ";
        cin>>A.vardas;
        cout<<endl<<"Įvesk studento pavardę: ";
        cin>>A.pavarde;
        cout<<endl;
        int n, pazymys, sum=0;
        cout<<"Kiek namų darbų įvertinimų turi studentas?"<<endl;
        while(!(cin>>n) || n<0)
        {
            cout<<"Įveskite ne neigiamą skaičių: "<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
        for(int j=0; j<n; j++)
        {
            cout<<"Įveskite "<<j+1<<"-ąjį pažymį iš "<<n<<": ";
            while(!(cin>>pazymys) || pazymys<1 || pazymys>10)
            {
                cout<<"Įveskite skaičių 1-10: "<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            A.pazymiai.push_back(pazymys);
            sum+=pazymys;
        }
        cout<<"Įveskite egzamino rezultatą: ";
        while(!(cin>>A.egzaminas) || A.egzaminas<1 || A.egzaminas>10)
        {
            cout<<"Įveskite skaičių 1-10: "<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        skaiciavimai(sum, A, n);
        studentai.push_back(A);
    }
}
void spausdinimas(const vector<Studentas>&studentai)
{
    cout<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(20)<<"Galutinis (Vid.)"<<setw(20)<<"Galutinis (Med.)"<<endl;
    for(int i=0; i<studentai.size(); i++)
    {
        cout<<left<<setw(20)<<studentai[i].vardas<<setw(20)<<studentai[i].pavarde<<setw(20)<<fixed<<setprecision(2)<<studentai[i].galutinis<<setw(20)<<fixed<< setprecision(2)<<studentai[i].galutinis_mediana<<endl;
    }
}
int main()
{
    vector<Studentas> studentai;
    int m;
    skaitymas(studentai, m);
    spausdinimas(studentai);
    return 0;
}