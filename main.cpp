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
            //skaitymas_is_failo(studentai); 
            break; 
        case 5:
            exit(0);
    }

    return 0;
}