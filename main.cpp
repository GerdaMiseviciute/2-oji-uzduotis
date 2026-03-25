#include "funkcijos.h"
int main()
{
    srand(time(NULL));

    int choice;
    cout<<"===Meniu==="<<endl;
    cout<<"1. Naudoti vektorius"<<endl;
    cout<<"2. Naudoti list"<<endl;
    cout<<"3. Naudoti deque"<<endl;
    cout<<"4. Testavimas"<<endl;
    cout<<"5. Baigti darba"<<endl;
    while(true)
    {
        try
        {
            cin>>choice;
            if(cin.fail() || choice<1 || choice>5)
                throw std::runtime_error("Iveskite skaiciu 1-5: ");

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
        {
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

            // vector<Studentas> studentai;
            // vector<Studentas> tinginiai;
            // vector<Studentas> darbstuoliai;
            // vector_list_deque(studentai, tinginiai, darbstuoliai);

            //skaitymas(studentai);
            break;
        }
        case 2:
        {    
            list<Studentas> studentai;

            pasirinkimas(studentai);

            list<Studentas> tinginiai;
            list<Studentas> darbstuoliai;
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

            // list<Studentas> studentai1;
            // list<Studentas> tinginiai1;
            // list<Studentas> darbstuoliai1;
            // vector_list_deque(studentai1, tinginiai1, darbstuoliai1);
            //pazymiu_generavimas(studentai);
            break;
        }
        case 3:
        {
            deque<Studentas> studentai;

            pasirinkimas(studentai);

            deque<Studentas> tinginiai;
            deque<Studentas> darbstuoliai;
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

            // deque<Studentas> studentai2;
            // deque<Studentas> tinginiai2;
            // deque<Studentas> darbstuoliai2;
            // vector_list_deque(studentai2, tinginiai2, darbstuoliai2);
            //generuoti_viska(studentai);
            break;
        }
        case 4:
            //skaitymas_is_failo(studentai); 
            break; 
        case 5:
            exit(0);
    }


    // //vector<Studentas> studentai;

    // pasirinkimas(studentai);
    
    // // vector<Studentas> tinginiai;
    // // vector<Studentas> darbstuoliai;
    // dalinimas_i_kategorijas(studentai, tinginiai, darbstuoliai);

    // if(tinginiai.size()>1)
    // {
    //     cout<<"Prastai besimokanciu studentu rikiavimas"<<endl;
    //     rikiavimas(tinginiai);
    // }
    
    // if(darbstuoliai.size()>1)
    // {
    //     cout<<"Gerai besimokanciu studentu rikiavimas"<<endl;
    //     rikiavimas(darbstuoliai);
    // }

    // cout<<"Prastai besimokanciu studentu spausdinimas"<<endl;
    // spausdinimas(tinginiai);
    // cout<<"Gerai besimokanciu studentu spausdinimas"<<endl;
    // spausdinimas(darbstuoliai);

    return 0;
}