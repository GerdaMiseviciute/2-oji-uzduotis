#include "funkcijos.h"
char raides(char a, char b)
{
    char c;
    while(true)
    {
        try
        {
            cin>>c;
            if(cin.fail() || (c!=a && c!=b))
                throw std::runtime_error(string("Iveskite '")+a+string("' arba '")+b+string("': "));

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
    return c;
}
// void skaiciavimai(Studentas& A)
// {
//     sort(A.pazymiai.begin(), A.pazymiai.end());
//     if(A.pazymiai.size()==0)
//     {
//         A.galutinis=A.egzaminas*0.6;
//         A.galutinis_mediana=A.egzaminas*0.6;
//     }   
//     else 
//     {
//         double vid=accumulate(A.pazymiai.begin(), A.pazymiai.end(), 0.0)/A.pazymiai.size();
//         A.galutinis=vid*0.4+A.egzaminas*0.6;
//         if(A.pazymiai.size()%2==1)
//             A.galutinis_mediana=A.pazymiai[A.pazymiai.size()/2]*0.4+A.egzaminas*0.6;
//         else A.galutinis_mediana=(A.pazymiai[A.pazymiai.size()/2]+A.pazymiai[A.pazymiai.size()/2-1])/2.0*0.4+A.egzaminas*0.6;
//     }
// }
bool did_var(Studentas& A, Studentas& B)
{
    return A.getVardas()<B.getVardas();
}
bool maz_var(Studentas& A, Studentas& B)
{
    return A.getVardas()>B.getVardas();
}
bool did_pav(Studentas& A, Studentas& B)
{
    return A.getPavarde()<B.getPavarde();
}
bool maz_pav(Studentas& A, Studentas& B)
{
    return A.getPavarde()>B.getPavarde();
}
bool did_gal_med(Studentas& A, Studentas& B)
{
    return A.Galutinis_mediana()<B.Galutinis_mediana();
}
bool maz_gal_med(Studentas& A, Studentas& B)
{
    return A.Galutinis_mediana()>B.Galutinis_mediana();
}
bool did_gal_vid(Studentas& A, Studentas& B)
{
    return A.Galutinis()<B.Galutinis();
}
bool maz_gal_vid(Studentas& A, Studentas& B)
{
    return A.Galutinis()>B.Galutinis();
}
void rikiuoti(vector<Studentas>&studentai, char tvarka, string b)
{
    if(tvarka=='d')
    {
        if(b=="var")
            sort(studentai.begin(), studentai.end(), did_var);
        else if(b=="pav")
            sort(studentai.begin(), studentai.end(), did_pav);
        else if(b=="gal_med")
            sort(studentai.begin(), studentai.end(), did_gal_med);
        else sort(studentai.begin(), studentai.end(), did_gal_vid);
    }
    else
    {
        if(b=="var")
            sort(studentai.begin(), studentai.end(), maz_var);
        else if(b=="pav")
            sort(studentai.begin(), studentai.end(), maz_pav);
        else if(b=="gal_med")
            sort(studentai.begin(), studentai.end(), maz_gal_med);
        else sort(studentai.begin(), studentai.end(), maz_gal_vid);
    }
}
void rikiuoti(deque<Studentas>&studentai, char tvarka, string b)
{
    if(tvarka=='d')
    {
        if(b=="var")
            sort(studentai.begin(), studentai.end(), did_var);
        else if(b=="pav")
            sort(studentai.begin(), studentai.end(), did_pav);
        else if(b=="gal_med")
            sort(studentai.begin(), studentai.end(), did_gal_med);
        else sort(studentai.begin(), studentai.end(), did_gal_vid);
    }
    else
    {
        if(b=="var")
            sort(studentai.begin(), studentai.end(), maz_var);
        else if(b=="pav")
            sort(studentai.begin(), studentai.end(), maz_pav);
        else if(b=="gal_med")
            sort(studentai.begin(), studentai.end(), maz_gal_med);
        else sort(studentai.begin(), studentai.end(), maz_gal_vid);
    }
}
void rikiuoti(list<Studentas>&studentai, char tvarka, string b)
{
    if(tvarka=='d')
    {
        if(b=="var")
            studentai.sort(did_var);
        else if(b=="pav")
            studentai.sort(did_pav);
        else if(b=="gal_med")
            studentai.sort(did_gal_med);
        else studentai.sort(did_gal_vid);
    }
    else
    {
        if(b=="var")
            studentai.sort(maz_var);
        else if(b=="pav")
            studentai.sort(maz_pav);
        else if(b=="gal_med")
            studentai.sort(maz_gal_med);
        else studentai.sort(maz_gal_vid);
    }
}
void failu_generavimas(int n)
{
    ofstream f("failas_"+std::to_string(n)+".txt");
    int m=rand()%20+1;

    ostringstream ss;
    ss<<left<<setw(21)<<"Vardas"<<setw(21)<<"Pavarde";
    for(int i=0; i<m; i++)
    {
        ss<<setw(5)<<("ND"+std::to_string(i+1))<<" ";
    }
    ss<<setw(5)<<"Egzaminas"<<endl;
    for(int i=0; i<n; i++)
    {
        ss<<left<<setw(20)<<("Vardas"+std::to_string(i+1))<<" "<<setw(20)<<("Pavarde"+std::to_string(i+1))<<" ";
        for(int j=0; j<m; j++)
        {
            ss<<setw(5)<<rand()%10+1<<" ";
        }
        ss<<setw(5)<<rand()%10+1<<endl;
    }
    f<<ss.str();
    f.close();
}
void testas_1(int n)
{
    auto start = high_resolution_clock::now();
    failu_generavimas(n);
    auto end = high_resolution_clock::now();
    duration<double> laikas=end-start;
    cout<<n<<" dydzio faila sugeneruoti uztruko "<<laikas.count()<<" s"<<endl;
}
void konstruktoriu_testas()
{
    Studentas stud;
    if(stud==Studentas("Vardas", "Pavarde", { }, 0))
        cout<<"Default konstruktorius veikia"<<endl;
    else cout<<"Default konstruktorius neveikia"<<endl;

    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    if(Stud==Studentas("Vardenis", "Pavardenis", {5, 8, 3}, 9))
        cout<<"Konstruktorius su parametrais veikia"<<endl;
    else cout<<"Konstruktorius su parametrais neveikia"<<endl;
    
    if(Stud.getVardas()=="Vardenis")
        cout<<"Vardo 'getteris' veikia"<<endl;
    else cout<<"Vardo 'getteris' neveikia"<<endl;

    if(Stud.getPavarde()=="Pavardenis")
        cout<<"Pavardes 'getteris' veikia"<<endl;
    else cout<<"Pavardes 'getteris' neveikia"<<endl;

    if(Stud.getEgzaminas()==9)
        cout<<"Egzamino 'getteris' veikia"<<endl;
    else cout<<"Egzamino 'getteris' neveikia"<<endl;

    if(Stud.getGalutinis()==Stud.Galutinis())
        cout<<"Galutinio rezultato 'getteris' veikia"<<endl;
    else cout<<"Galutinio rezultato 'getteris' neveikia"<<endl;

    if(Stud.getGalutinis_mediana()==Stud.Galutinis_mediana())
        cout<<"Galutinio rezultato pagal mediana 'getteris' veikia"<<endl;
    else cout<<"Galutinio rezultato pagal mediana 'getteris' neveikia"<<endl;

    Studentas stud2(Stud);
    if(stud2==Stud)
        cout<<"Kopijavimo konstruktorius veikia"<<endl;
    else cout<<"Kopijavimo konstruktorius neveikia"<<endl;

    Studentas stud3;
    stud3=Stud;
    if(stud3==Stud)
        cout<<"Kopijavimo priskyrimas veikia"<<endl;
    else cout<<"Kopijavimo priskyrimas neveikia"<<endl;

    Studentas Stud2(std::move(Stud));
    if(Stud2==Studentas("Vardenis", "Pavardenis", {5, 8, 3}, 9) && Stud.Clear()==true)
        cout<<"Move konstruktorius veikia"<<endl;
    else cout<<"Move konstruktorius neveikia"<<endl;

    Studentas Stud1("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    Studentas stud1;
    stud1=std::move(Stud1);
    if(stud1==Studentas("Vardenis", "Pavardenis", {5, 8, 3}, 9) && Stud1.Clear()==true)
        cout<<"Move priskyrimas veikia"<<endl;
    else cout<<"Move priskyrimas neveikia"<<endl;

    Stud1.~Studentas();
    if(Stud1.Clear()==true)
        cout<<"Destruktorius veikia"<<endl;
    else cout<<"Destruktorius neveikia"<<endl;

    std::istringstream in("Jonas Jonaitis 10 9 8 7");
    Studentas s;
    in >> s;
    if(s.getVardas()=="Jonas" && s.getPavarde()=="Jonaitis")
        cout<<"Ivesties metodas veikia"<<endl;
    else cout<<"Ivesties metodas neveikia"<<endl;

    Studentas s1("Jonas", "Jonaitis", {10, 9, 8}, 7);
    std::ostringstream out;
    out << s1;
    if(out.str().find("Jonas") != string::npos && out.str().find("Jonaitis") != string::npos)
        cout<<"Isvesties metodas veikia"<<endl;
    else cout<<"Isvesties metodas neveikia"<<endl;
}
