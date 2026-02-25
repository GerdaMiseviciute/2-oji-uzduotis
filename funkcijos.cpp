#include "funkcijos.h"
// #include "mylib.h"
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
void skaitymas_is_failo(vector<Studentas>&studentai)
{
    try
    {
        string eil;

        auto start = high_resolution_clock::now();
        ifstream fd("kursiokai.txt");
        if(!fd)
        {
            throw std::runtime_error("Nepavyko atidaryti failo.");
        }
        getline(fd, eil);
        while(getline(fd, eil))
        {
            if (eil.empty()) continue;
            stringstream ss(eil);
            Studentas A;
            ss>>A.vardas>>A.pavarde;
            int x;
            while(ss>>x)
            {
                A.pazymiai.push_back(x);
            }
            if(!A.pazymiai.empty())
            {
                A.egzaminas=A.pazymiai.back();
                A.pazymiai.pop_back();
            }
            skaiciavimai(A);
            studentai.push_back(A);
        }
        fd.close();
        auto end = high_resolution_clock::now();
        duration<double> laikas=end-start;
        cout<<laikas.count()<<endl;
    }
    catch(const std::exception& e)
    {
        cerr<<"Klaida: "<<e.what()<<endl;
    }
    
}
void skaitymas(vector<Studentas>&studentai)
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
            int pazymys;
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
                else A.pazymiai.push_back(pazymys);
            }
            cout<<"Įveskite egzamino rezultatą: ";
            while(!(cin>>A.egzaminas) || A.egzaminas<1 || A.egzaminas>10)
            {
                cout<<"Įveskite skaičių 1-10: "<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            skaiciavimai(A);
            studentai.push_back(A);
        }
        else break;
    }
}
void pazymiu_generavimas(vector<Studentas>&studentai)
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
                A.pazymiai.push_back(rand()%10+1);
            }
            A.egzaminas=rand()%10+1;
            skaiciavimai(A);
            studentai.push_back(A);
        }
        else break;
    }
}
void generuoti_viska(vector<Studentas>&studentai)
{
    int m=rand()%20+1;
    for(int i=0; i<m; i++)
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
            a.pazymiai.push_back(rand()%10+1);
        }
        a.egzaminas=rand()%10+1;
        skaiciavimai(a);
        studentai.push_back(a);
    }
}
void spausdinimas_i_ekrana(const vector<Studentas>&studentai)
{
    cout<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(20)<<"Galutinis (Vid.)"<<setw(20)<<"Galutinis (Med.)"<<endl;
    for(int i=0; i<studentai.size(); i++)
    {
        cout<<left<<setw(20)<<studentai[i].vardas<<setw(20)<<studentai[i].pavarde<<setw(20)<<fixed<<setprecision(2)<<studentai[i].galutinis<<setw(20)<<fixed<< setprecision(2)<<studentai[i].galutinis_mediana<<endl;
    }
}
void spausdinimas_i_faila(const vector<Studentas>&studentai)
{
    ofstream fr("rezultatai.txt");
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(20)<<"Galutinis (Vid.)"<<setw(20)<<"Galutinis (Med.)"<<endl;
    for(int i=0; i<studentai.size(); i++)
    {
        fr<<left<<setw(20)<<studentai[i].vardas<<setw(20)<<studentai[i].pavarde<<setw(20)<<fixed<<setprecision(2)<<studentai[i].galutinis<<setw(20)<<fixed<< setprecision(2)<<studentai[i].galutinis_mediana<<endl;
    }
}
void ivedimas(vector<Studentas>&studentai)
{
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
            skaitymas(studentai);
            break;
        case 2:
            pazymiu_generavimas(studentai);
            break;
        case 3:
            generuoti_viska(studentai);
            break;
        case 4:
            break; 
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
void rikiavimas(vector<Studentas>&studentai)
{
    string b;
    cout<<"Pasirinkite rūšiavimo kriterijų - vardą, pavardę, galutinį rezultatą pagal medianą arba galutinį rezultatą pagal vidurkį (vardas / pavarde / gal_med / gal_vid): "<<endl;
    while(true)
    {
        cin>>b;
        if(b=="vardas" || b=="pavarde" || b=="gal_med" || b=="gal_vid")
            break;
        cout<<"Neteisingas kriterijus! Įrašykite iš naujo: "<<endl;
    }
    char tvarka;
    cout<<"Spauskite 'd', jei norite, kad duomenys būtų spausdinami didėjimo tvarka, arba 'm', kad duomenys būtų spausdinami mažėjimo tvarka: "<<endl;
    while(!(cin>>tvarka) || (tvarka!='d' && tvarka!='m'))
    {
        cout<<"Įveskite 'f' arba 'i': "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if(tvarka=='d')
    {
        if(b=="vardas")
            sort(studentai.begin(), studentai.end(), did_var);
        else if(b=="pavarde")
            sort(studentai.begin(), studentai.end(), did_pav);
        else if(b=="gal_med")
            sort(studentai.begin(), studentai.end(), did_gal_med);
        else sort(studentai.begin(), studentai.end(), did_gal_vid);
    }
    else
    {
        if(b=="vardas")
            sort(studentai.begin(), studentai.end(), maz_var);
        else if(b=="pavarde")
            sort(studentai.begin(), studentai.end(), maz_pav);
        else if(b=="gal_med")
            sort(studentai.begin(), studentai.end(), maz_gal_med);
        else sort(studentai.begin(), studentai.end(), maz_gal_vid);
    }
}
void spausdinimas(const vector<Studentas>&studentai)
{
    char s;
    cout<<"Spauskite 'f', jei norite, kad duomenys būtų spausdinami į failą, arba 'e', kad duomenys būtų spausdinami į ekraną: "<<endl;
    while(!(cin>>s) || (s!='e' && s!='f'))
    {
        cout<<"Įveskite 'f' arba 'i': "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    if(s=='f')
        spausdinimas_i_faila(studentai);
    else spausdinimas_i_ekrana(studentai);
}