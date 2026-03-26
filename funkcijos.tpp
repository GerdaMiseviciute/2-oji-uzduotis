template <typename Konteineris>
void skaitymas_is_failo(Konteineris& studentai)
{
    string filename;
    system("dir *.txt");
    cout<<"Ivesk failo pavadinima: ";
    cin>>filename;
    try
    {
        string eil;
        ifstream fd(filename);
        if(!fd)
        {
            throw std::runtime_error("Nepavyko atidaryti failo.");
        }
        getline(fd, eil);
        while(getline(fd, eil))
        {
            if (eil.empty()) 
                continue;
            istringstream ss(eil);
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
            A.pazymiai.clear();
        }
        fd.close();
    }
    catch(const std::exception& e)
    {
        cerr<<"Klaida: "<<e.what()<<endl;
        terminate();
    }
}
template <typename Konteineris>
void skaitymas(Konteineris& studentai)
{
    for (int i=0; ; i++)
    {
        Studentas A;
        int a;
        cout<<"Jei norite ivesti naujo studento duomenis, spauskite 1, jei baigete zmoniu ivedima, spauskite 0: ";
        while(true)
        {
            try
            {
                cin>>a;
                if(cin.fail() || (a!=0 && a!=1))
                    throw std::runtime_error("Iveskite 1 arba 0: ");

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
        if(a==1)
        {
            cout<<i+1<<" studentas:"<<endl;
            cout<<"Ivesk studento varda: ";
            cin.ignore();
            getline(cin, A.vardas);
            cout<<endl<<"Ivesk studento pavarde: ";
            getline(cin, A.pavarde);
            cout<<endl;
            int pazymys;
            for(int j=0; ;j++)
            {
                cout<<"Iveskite "<<j+1<<"-aji pazymi (jei ivedete visus pazymius, spauskite 0): ";
                while(true)
                {
                    try
                    {
                        cin>>pazymys;
                        if(cin.fail() || pazymys<0 || pazymys>10)
                            throw std::runtime_error("Iveskite skaiciu 1-10: ");

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
                if(pazymys==0)
                    break;
                else A.pazymiai.push_back(pazymys);
            }
            cout<<"Iveskite egzamino rezultata: ";
            while(true)
            {
                try
                {
                    cin>>A.egzaminas;
                    if(cin.fail() || A.egzaminas<0 || A.egzaminas>10)
                        throw std::runtime_error("Iveskite skaiciu 1-10: ");

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
            skaiciavimai(A);
            studentai.push_back(A);
            A.pazymiai.clear();
        }
        else break;
    }
}
template <typename Konteineris>
void pazymiu_generavimas(Konteineris&studentai)
{
    for(int i=0; ; i++)
    {
        int a;
        cout<<"Jei norite ivesti naujo studento duomenis, spauskite 1, jei baigete zmoniu ivedima, spauskite 0: ";
        while(true)
        {
            try
            {
                cin>>a;
                if(cin.fail() || (a!=0 && a!=1))
                    throw std::runtime_error("Iveskite 1 arba 0: ");

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
        if(a==1)
        {
            Studentas A;
            cout<<i+1<<" studentas:"<<endl;
            cout<<"Ivesk studento varda: ";
            cin.ignore();
            getline(cin, A.vardas);
            cout<<endl<<"Ivesk studento pavarde: ";
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
            A.pazymiai.clear();
        }
        else break;
    }
}
template <typename Konteineris>
void generuoti_viska(Konteineris&studentai)
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
        a.pazymiai.clear();
    }
}
template <typename Konteineris>
void spausdinimas_i_ekrana(const Konteineris&studentai)
{
    ostringstream ss;
    ss<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(20)<<"Galutinis (Vid.)"<<setw(20)<<"Galutinis (Med.)"<<endl;
    for(auto &s:studentai)
    {
        ss<<left<<setw(20)<<s.vardas<<setw(20)<<s.pavarde<<setw(20)<<fixed<<setprecision(2)<<s.galutinis<<setw(20)<<fixed<< setprecision(2)<<s.galutinis_mediana<<endl;
    }
    cout<<ss.str();
}
template <typename Konteineris>
void spausdinimas_i_faila(const Konteineris&studentai)
{
    string filename;
    if(studentai.front().galutinis<5)
        filename="tinginiai.txt";
    else filename="darbstuoliai.txt";
    ofstream fr(filename);
    ostringstream ss;
    ss<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavardė"<<setw(20)<<"Galutinis (Vid.)"<<setw(20)<<"Galutinis (Med.)"<<endl;
    for(auto &s:studentai)
    {
        ss<<left<<setw(20)<<s.vardas<<setw(20)<<s.pavarde<<setw(20)<<fixed<<setprecision(2)<<s.galutinis<<setw(20)<<fixed<< setprecision(2)<<s.galutinis_mediana<<endl;  
    }
    fr<<ss.str();
}
template <typename Konteineris>
void pasirinkimas(Konteineris&studentai)
{
    int choice;
    cout<<"===Meniu==="<<endl;
    cout<<"1. Ivesti duomenis ranka"<<endl;
    cout<<"2. Generuoti pazymius"<<endl;
    cout<<"3. Generuoti studentu vardus, pavardes ir pazymius"<<endl;
    cout<<"4. Nuskaityti duomenis is failo"<<endl;
    cout<<"5. Generuoti faila"<<endl;
    // cout<<"6. Programos testavimas 1 (failu generavimas)"<<endl;
    // cout<<"7. Programos testavimas 2 (generuotu failu apdorojimas)"<<endl;
    cout<<"6. Baigti darba"<<endl;
    while(true)
    {
        try
        {
            cin>>choice;
            if(cin.fail() || choice<1 || choice>6)
                throw std::runtime_error("Iveskite skaiciu 1-6: ");

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
        case 4:
            skaitymas_is_failo(studentai); 
            break; 
        case 5:
            int k;
            cout<<"Iveskite generuojamo failo dydi: ";
            while(true)
            {
                try
                {
                    cin>>k;
                    if(cin.fail() || k<1)
                        throw std::runtime_error("Iveskite teigiama skaiciu: ");

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
            failu_generavimas(k);
            pasirinkimas(studentai);
        // case 6:
        //     testas_1(1000);
        //     testas_1(10000);
        //     testas_1(100000);
        //     testas_1(1000000);
        //     testas_1(10000000);
        //     exit(0);
        // case 7:
        //     testas_2(studentai, 1000);
        //     testas_2(studentai, 10000);
        //     testas_2(studentai, 100000);
        //     testas_2(studentai, 1000000);
        //     testas_2(studentai, 10000000);
        //     exit(0);
        case 6:
            exit(0);
    }
}
template <typename Konteineris>
void rikiavimas(Konteineris&studentai)
{
    string b;
    cout<<"Pasirinkite rusiavimo kriteriju - varda, pavarde, galutini rezultata pagal mediana arba galutini rezultata pagal vidurka (var / pav / gal_med / gal_vid): ";
    while(true)
    {
        try
        {
            cin>>b;
            if(cin.fail() || (b!="var" && b!="pav" && b!="gal_med" && b!="gal_vid"))
                throw std::runtime_error("Irasykite is naujo: ");

            break;
        }
        catch(const std::exception& e)
        {
            cerr<<"Neteisingas kriterijus! "<<e.what()<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    cout<<"Spauskite 'd', jei norite, kad duomenys butu spausdinami didejimo tvarka, arba 'm', kad duomenys butu spausdinami mazejimo tvarka: "<<endl;
    char tvarka=raides('d', 'm');
    
    rikiuoti(studentai, tvarka, b);
    
}
template <typename Konteineris>
void spausdinimas(const Konteineris&studentai)
{
    
    cout<<"Spauskite 'f', jei norite, kad duomenys butu spausdinami i faila, arba 'e', kad duomenys butu spausdinami i ekrana: "<<endl;
    char s=raides('f', 'e');

    if(s=='f')
        spausdinimas_i_faila(studentai);
    else spausdinimas_i_ekrana(studentai);
}
template <typename Konteineris>
void dalinimas_i_kategorijas(Konteineris&studentai, Konteineris&tinginiai, Konteineris&darbstuoliai)
{
    for(auto &a:studentai)
    {
        if(a.galutinis<5)
            tinginiai.push_back(a);
        else darbstuoliai.push_back(a);
    }
}
template <typename Konteineris>
void testas_2(Konteineris&studentai, int n)
{
    studentai.clear();
    auto start = high_resolution_clock::now();
    try
    {
        string eil;
        
        ifstream fd("failas_"+std::to_string(n)+".txt");
        if(!fd)
        {
            throw std::runtime_error("Nepavyko atidaryti failo.");
        }
        getline(fd, eil);
        while(getline(fd, eil))
        {
            if (eil.empty()) 
                continue;
            istringstream ss(eil);
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
            A.pazymiai.clear();
        }
        fd.close();
        auto end = high_resolution_clock::now();
        duration<double> laikas=end-start;
        cout<<n<<" dydzio faila nuskaityti uztruko "<<laikas.count()<<" s"<<endl;
    }
    catch(const std::exception& e)
    {
        cerr<<"Klaida: "<<e.what()<<endl;
        terminate();
    }
    auto start1 = high_resolution_clock::now();
    rikiuoti(studentai, 'd', "gal_vid");
    auto end = high_resolution_clock::now();
    duration<double> laikas=end-start1;
    cout<<"Rikiavimas uztruko "<<laikas.count()<<" s"<<endl;
    
    start1 = high_resolution_clock::now();
    Konteineris tinginiai;
    Konteineris darbstuoliai;
    dalinimas_i_kategorijas(studentai, tinginiai, darbstuoliai);
    end = high_resolution_clock::now();
    laikas=end-start1;
    cout<<n<<" dydzio faila i 2 kategorijas surusiuoti uztruko "<<laikas.count()<<" s"<<endl;

    // start1 = high_resolution_clock::now();
    // spausdinimas_i_faila(tinginiai);
    // end = high_resolution_clock::now();
    // laikas=end-start1;
    // cout<<"Prastai besimokanciu studentu spausdinimas i faila uztruko "<<laikas.count()<<" s"<<endl;

    // start1 = high_resolution_clock::now();
    // spausdinimas_i_faila(darbstuoliai);
    // end = high_resolution_clock::now();
    // laikas=end-start1;
    // cout<<"Gerai besimokanciu studentu spausdinimas i faila uztruko "<<laikas.count()<<" s"<<endl;

    laikas=end-start;
    cout<<n<<" irasu failo testo laikas: "<<laikas.count()<<" s"<<endl<<endl;
}
template <typename Konteineris>
void vector_list_deque(Konteineris&studentai)
{
    pasirinkimas(studentai);
    Konteineris tinginiai;
    Konteineris darbstuoliai;
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
}
