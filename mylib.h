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