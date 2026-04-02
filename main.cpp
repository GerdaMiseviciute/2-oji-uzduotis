#include "funkcijos.h"
int main()
{
    srand(time(NULL));

    int choice;
    cout<<"===Meniu==="<<endl;
    cout<<"1. Naudoti vektorius"<<endl;
    cout<<"2. Naudoti list"<<endl;
    cout<<"3. Naudoti deque"<<endl;
    cout<<"4. Programos testavimas 1 (failu generavimas)"<<endl;
    cout<<"5. Programos testavimas 2 (generuotu failu apdorojimas)"<<endl;
    cout<<"6. Programos testavimas 3 (strategiju lyginimas)"<<endl;
    cout<<"7. Greiciausios strategijos spartos analize su skirtingais optimizavimo flag'ais"<<endl;
    cout<<"8. Baigti darba"<<endl;
    while(true)
    {
        try
        {
            cin>>choice;
            if(cin.fail() || choice<1 || choice>8)
                throw std::runtime_error("Iveskite skaiciu 1-8: ");

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
            vector_list_deque(studentai);
            break;
        }
        case 2:
        {    
            list<Studentas> studentai;
            vector_list_deque(studentai);
            break;
        }
        case 3:
        {
            deque<Studentas> studentai;
            vector_list_deque(studentai);
            break;
        }
        case 4:
        {
            testas_1(1000);
            testas_1(10000);
            testas_1(100000);
            testas_1(1000000);
            testas_1(10000000);
            exit(0);
        }
        case 5:
        {
            vector<Studentas> studentai;
            list<Studentas> studentai1;
            deque<Studentas> studentai2;
            cout<<"1000 irasu failai:"<<endl;
            cout<<"Vector testas:"<<endl;
            testas_2(studentai, 1000);
            cout<<"List testas:"<<endl;
            testas_2(studentai1, 1000);
            cout<<"Deque testas:"<<endl;
            testas_2(studentai2, 1000);

            cout<<"10000 irasu failai:"<<endl;
            cout<<"Vector testas:"<<endl;
            testas_2(studentai, 10000);
            cout<<"List testas:"<<endl;
            testas_2(studentai1, 10000);
            cout<<"Deque testas:"<<endl;
            testas_2(studentai2, 10000);

            cout<<"100000 irasu failai:"<<endl;
            cout<<"Vector testas:"<<endl;
            testas_2(studentai, 100000);
            cout<<"List testas:"<<endl;
            testas_2(studentai1, 100000);
            cout<<"Deque testas:"<<endl;
            testas_2(studentai2, 100000);

            cout<<"1000000 irasu failai:"<<endl;
            cout<<"Vector testas:"<<endl;
            testas_2(studentai, 1000000);
            cout<<"List testas:"<<endl;
            testas_2(studentai1, 1000000);
            cout<<"Deque testas:"<<endl;
            testas_2(studentai2, 1000000);

            cout<<"10000000 irasu failai:"<<endl;
            cout<<"Vector testas:"<<endl;
            testas_2(studentai, 10000000);
            cout<<"List testas:"<<endl;
            testas_2(studentai1, 10000000);
            cout<<"Deque testas:"<<endl;
            testas_2(studentai2, 10000000);
            exit(0);
        }
        case 6:
        {
            vector<Studentas> studentai;
            list<Studentas> studentai1;
            deque<Studentas> studentai2;
            cout<<"1000 irasu failai:"<<endl;
            cout<<"--Vector--"<<endl;
            testas_3(studentai, 1000);
            cout<<"--List--"<<endl;
            testas_3(studentai1, 1000);
            cout<<"--Deque--"<<endl;
            testas_3(studentai2, 1000);
            
            cout<<endl<<"10000 irasu failai:"<<endl;
            cout<<"--Vector--"<<endl;
            testas_3(studentai, 10000);
            cout<<"--List--"<<endl;
            testas_3(studentai1, 10000);
            cout<<"--Deque--"<<endl;
            testas_3(studentai2, 10000);

            cout<<endl<<"100000 irasu failai:"<<endl;
            cout<<"--Vector--"<<endl;
            testas_3(studentai, 100000);
            cout<<"--List--"<<endl;
            testas_3(studentai1, 100000);
            cout<<"--Deque--"<<endl;
            testas_3(studentai2, 100000);
            
            cout<<endl<<"1000000 irasu failai:"<<endl;
            cout<<"--Vector--"<<endl;
            testas_3(studentai, 1000000);
            cout<<"--List--"<<endl;
            testas_3(studentai1, 1000000);
            cout<<"--Deque--"<<endl;
            testas_3(studentai2, 1000000);

            cout<<endl<<"10000000 irasu failai:"<<endl;
            cout<<"--Vector--"<<endl;
            testas_3(studentai, 10000000);
            cout<<"--List--"<<endl;
            testas_3(studentai1, 10000000);
            cout<<"--Deque--"<<endl;
            testas_3(studentai2, 10000000);

            break;
        }
        case 7:
        {
            vector<Studentas> studentai;
            dar_vienas_testas(studentai, 100000);
            dar_vienas_testas(studentai, 1000000);
        }
        case 8:
            exit(0);
    }

    return 0;
}