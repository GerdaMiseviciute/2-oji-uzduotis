#ifndef MYLIB_H
#define MYLIB_H
#include <iostream>
#include <ctime>
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
        string getVardas() const
        {
            return vardas;
        }
        string getVardas() { return vardas; }
        string getPavarde() const
        {
            return pavarde;
        }
        string getPavarde() { return pavarde; }
        int getEgzaminas() const
        {
            return egzaminas;
        }
        int getEgzaminas() { return egzaminas; }
        double getGalutinis() const
        {
            return galutinis;
        }
        double getGalutinis() { return galutinis; }
        double getGalutinis_mediana() const
        {
            return galutinis_mediana;
        }
        double getGalutinis_mediana() { return galutinis_mediana; }
        Studentas(const Studentas & s) : vardas{s.vardas}, pavarde{s.pavarde}, pazymiai{s.pazymiai}, egzaminas{s.egzaminas}, galutinis{s.galutinis}, galutinis_mediana{s.galutinis_mediana} {}
        Studentas(Studentas && s) : vardas{s.vardas}, pavarde{s.pavarde}, pazymiai{std::move(s.pazymiai)}, egzaminas{s.egzaminas}, galutinis{s.galutinis}, galutinis_mediana{s.galutinis_mediana}
        {
            s.vardas.clear();
            s.pavarde.clear();
            s.pazymiai.clear();
            s.egzaminas=0;
            s.galutinis=0;
            s.galutinis_mediana=0;
        }
        Studentas & operator=(const Studentas& s)
        {
            if(&s == this)
                return *this;
            pazymiai.clear();
            pazymiai=s.pazymiai;
            vardas=s.vardas;
            pavarde=s.pavarde;
            egzaminas=s.egzaminas;
            galutinis=s.galutinis;
            galutinis_mediana=s.galutinis_mediana;
            return *this;
        }
        Studentas & operator=(Studentas&& s)
        {
            if(&s == this)
                return *this;
            pazymiai.clear();
            pazymiai=s.pazymiai;
            vardas=s.vardas;
            pavarde=s.pavarde;
            egzaminas=s.egzaminas;
            galutinis=s.galutinis;
            galutinis_mediana=s.galutinis_mediana;

            s.vardas.clear();
            s.pavarde.clear();
            s.pazymiai.clear();
            s.egzaminas=0;
            s.galutinis=0;
            s.galutinis_mediana=0;
            return *this;
        }
        friend std::istream& operator>>(std::istream& in, Studentas& A)
        {
            in>>A.vardas>>A.pavarde;
            int x;
            while(in>>x)
            {
                A.pazymiai.push_back(x);
            }
            if(!A.pazymiai.empty())
            {
                A.egzaminas=A.pazymiai.back();
                A.pazymiai.pop_back();
            }
            A.galutinis = A.Galutinis();
            A.galutinis_mediana = A.Galutinis_mediana();
            return in;
        }
        friend std::ostream& operator<<(std::ostream& out, const Studentas& A)
        {
            out<<left<<setw(20)<<A.vardas<<setw(20)<<A.pavarde<<setw(20)<<fixed<<setprecision(2)<<A.galutinis<<setw(20)<<fixed<< setprecision(2)<<A.galutinis_mediana<<endl;
            return out;
        }
        double Galutinis() 
        {
            return (pazymiai.empty()) ? egzaminas*0.6 : accumulate(pazymiai.begin(), pazymiai.end(), 0.0)/pazymiai.size()*0.4 + egzaminas*0.6;
        }
        double Galutinis_mediana()
        {
            sort(pazymiai.begin(), pazymiai.end());
            if(pazymiai.empty())
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
        bool operator ==(const Studentas A) const
        {
            if(getVardas()==A.getVardas() && getPavarde()== A.getPavarde() && getEgzaminas()==A.getEgzaminas() && getGalutinis()==A. getGalutinis() && getGalutinis_mediana()==A.getGalutinis_mediana())
                return true;
            else return false;
        }
        bool Clear()
        {
            return (vardas.empty()) && (pavarde.empty()) && (pazymiai.empty()) && (egzaminas==0) && (galutinis==0) && (galutinis_mediana==0);
        }
};
#endif