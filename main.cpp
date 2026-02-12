#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Studentas
{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
};
void skaitymas(vector<Studentas>&studentai, int studentu_skaicius)
{
    for (int i=0; i<studentu_skaicius; i++)
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
            cout<<"Įveskite teigiamą skaičių: "<<endl;
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
        if(n=0)
            A.galutinis=A.egzaminas*0.6;
        else A.galutinis=sum*1.0/(A.pazymiai.size()*1.0)*0.4+A.egzaminas*0.6;
        studentai.push_back(A);
    }
}
void spausdinimas(const vector<Studentas>&studentai)
{
    cout<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(10)<<"Galutinis (Vid.)"<<endl;
    for(int i=0; i<studentai.size(); i++)
    {
        cout<<left<<setw(20)<<studentai[i].vardas<<setw(20)<<studentai[i].pavarde<<setw(10)<<fixed<< setprecision(2)<<studentai[i].galutinis<<endl;
    }
}
int main()
{
    vector<Studentas> studentai;

    int studentu_skaicius=3;
    skaitymas(studentai, studentu_skaicius);
    spausdinimas(studentai);

    return 0;
}