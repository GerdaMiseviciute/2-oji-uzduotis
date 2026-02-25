#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <numeric>
#include <chrono>
using std::cin;
using std::cout;
using std::vector;
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
using std::stringstream;

struct Studentas
{
    string vardas, pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};