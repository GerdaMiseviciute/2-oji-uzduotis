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
void skaiciavimai(Studentas& A)
{
    sort(A.pazymiai.begin(), A.pazymiai.end());
    if(A.pazymiai.size()==0)
    {
        A.galutinis=A.egzaminas*0.6;
        A.galutinis_mediana=A.egzaminas*0.6;
    }   
    else 
    {
        double vid=accumulate(A.pazymiai.begin(), A.pazymiai.end(), 0.0)/A.pazymiai.size();
        A.galutinis=vid*0.4+A.egzaminas*0.6;
        if(A.pazymiai.size()%2==1)
            A.galutinis_mediana=A.pazymiai[A.pazymiai.size()/2]*0.4+A.egzaminas*0.6;
        else A.galutinis_mediana=(A.pazymiai[A.pazymiai.size()/2]+A.pazymiai[A.pazymiai.size()/2-1])/2.0*0.4+A.egzaminas*0.6;
    }
}
bool did_var(Studentas& A, Studentas& B)
{
    return A.vardas<B.vardas;
}
bool maz_var(Studentas& A, Studentas& B)
{
    return A.vardas>B.vardas;
}
bool did_pav(Studentas& A, Studentas& B)
{
    return A.pavarde<B.pavarde;
}
bool maz_pav(Studentas& A, Studentas& B)
{
    return A.pavarde>B.pavarde;
}
bool did_gal_med(Studentas& A, Studentas& B)
{
    return A.galutinis_mediana<B.galutinis_mediana;
}
bool maz_gal_med(Studentas& A, Studentas& B)
{
    return A.galutinis_mediana>B.galutinis_mediana;
}
bool did_gal_vid(Studentas& A, Studentas& B)
{
    return A.galutinis<B.galutinis;
}
bool maz_gal_vid(Studentas& A, Studentas& B)
{
    return A.galutinis>B.galutinis;
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


// void vector_list_deque()
// {
//     int choice;
//     cout<<"===Meniu==="<<endl;
//     cout<<"1. Naudoti vektorius"<<endl;
//     cout<<"2. Naudoti list"<<endl;
//     cout<<"3. Naudoti deque"<<endl;
//     cout<<"4. Testavimas"<<endl;
//     cout<<"5. Baigti darba"<<endl;
//     while(true)
//     {
//         try
//         {
//             cin>>choice;
//             if(cin.fail() || choice<1 || choice>5)
//                 throw std::runtime_error("Iveskite skaiciu 1-5: ");

//             cin.ignore(1000, '\n');
//             break;
//         }
//         catch(const std::exception& e)
//         {
//             cerr<<"Klaida! "<<e.what()<<endl;
//             cin.clear();
//             cin.ignore(1000, '\n');
//         }
//     }
//     switch(choice)
//     {
//         case 1:
//             skaitymas(studentai);
//             break;
//         case 2:
//             pazymiu_generavimas(studentai);
//             break;
//         case 3:
//             generuoti_viska(studentai);
//             break;
//         case 4:
//             skaitymas_is_failo(studentai); 
//             break; 
//         case 5:
//             int k;
//             cout<<"Iveskite generuojamo failo dydi: ";
//             while(true)
//             {
//                 try
//                 {
//                     cin>>k;
//                     if(cin.fail() || k<1)
//                         throw std::runtime_error("Iveskite teigiama skaiciu: ");

//                     cin.ignore(1000, '\n');
//                     break;
//                 }
//                 catch(const std::exception& e)
//                 {
//                     cerr<<"Klaida! "<<e.what()<<endl;
//                     cin.clear();
//                     cin.ignore(1000, '\n');
//                 }
//             }
//             failu_generavimas(k);
//             pasirinkimas(studentai);
//         case 6:
//             testas_1(1000);
//             testas_1(10000);
//             testas_1(100000);
//             testas_1(1000000);
//             testas_1(10000000);
//             exit(0);
//         case 7:
//             testas_2(studentai, 1000);
//             testas_2(studentai, 10000);
//             testas_2(studentai, 100000);
//             testas_2(studentai, 1000000);
//             testas_2(studentai, 10000000);
//             exit(0);
//         case 8:
//             exit(0);
//     }
// }