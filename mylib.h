#include <iostream>
#include <stdexcept>
#include <exception>
#include <list>
#include <deque>
#include <type_traits>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <chrono>
using std::cin;
using std::cout;
using std::vector;
using std::list;
using std::deque;
using std::left;
using std::setw;
using std::string;
using std::endl;
using std::fixed;
using std::setprecision;
using std::sort;
using std::accumulate;
using std::ofstream;
using std::ifstream;
using std::cerr;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::istringstream;
using std::ostringstream;
using std::terminate;

// struct Studentas
// {
//     string vardas, pavarde;
//     vector<int> pazymiai;
//     int egzaminas;
//     double galutinis;
//     double galutinis_mediana;
// };
class Studentas
{
    private:
        string vardas;
        string pavarde;
        int egzaminas;
        double galutinis;
        double galutinis_mediana;
        vector<int>pazymiai;
    public:
        Studentas()
        {
            vardas="Vardas";
            pavarde="Pavarde";
            egzaminas=0;
            galutinis=0;
            galutinis_mediana=0;
        }
        Studentas(string A, string B, vector<int>C, int D) : vardas{A}, pavarde{B}, pazymiai{C}, egzaminas{D} 
        {
            galutinis = Galutinis();
            galutinis_mediana = Galutinis_mediana();
        }
        double Galutinis() 
        {
            return (pazymiai.size()!=0) ? accumulate(pazymiai.begin(), pazymiai.end(), 0.0)/pazymiai.size()*0.4 + egzaminas*0.6 : egzaminas*0,6;
        }
        double Galutinis_mediana()
        {
            sort(pazymiai.begin(), pazymiai.end());
            if(pazymiai.size()==0)
                return egzaminas*0.6;
            else return (pazymiai.size()%2==1) ? pazymiai[pazymiai.size()/2]*0.4+egzaminas*0.6 : (pazymiai[pazymiai.size()/2]+pazymiai[pazymiai.size()/2-1])/2.0*0.4+egzaminas*0.6;
        }
        
        ~Studentas()
        {
            vardas.clear();
            pavarde.clear();
            pazymiai.clear();
            egzaminas=0;
            galutinis=0;
            galutinis_mediana=0;
        }
};