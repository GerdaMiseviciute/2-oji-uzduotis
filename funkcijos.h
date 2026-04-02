#include "mylib.h"
char raides(char a, char b);
void skaiciavimai(Studentas& A);
template <typename Konteineris>
void skaitymas_is_failo(Konteineris&studentai);
template <typename Konteineris>
void skaitymas(Konteineris&studentai);
template <typename Konteineris>
void pazymiu_generavimas(Konteineris&studentai);
template <typename Konteineris>
void generuoti_viska(Konteineris&studentai);
template <typename Konteineris>
void spausdinimas_i_ekrana(const Konteineris&studentai);
template <typename Konteineris>
void spausdinimas_i_faila(const Konteineris&studentai);
template <typename Konteineris>
void pasirinkimas(Konteineris&studentai);
bool did_var(Studentas& A, Studentas& B);
bool maz_var(Studentas& A, Studentas& B);
bool did_pav(Studentas& A, Studentas& B);
bool maz_pav(Studentas& A, Studentas& B);
bool did_gal_med(Studentas& A, Studentas& B);
bool maz_gal_med(Studentas& A, Studentas& B);
bool did_gal_vid(Studentas& A, Studentas& B);
bool maz_gal_vid(Studentas& A, Studentas& B);
void rikiuoti(vector<Studentas>&studentai, char tvarka, string b);
void rikiuoti(deque<Studentas>&studentai, char tvarka, string b);
void rikiuoti(list<Studentas>&studentai, char tvarka, string b);
template <typename Konteineris>
void rikiavimas(Konteineris&studentai);
template <typename Konteineris>
void spausdinimas(const Konteineris&studentai);
void failu_generavimas(int n);
template <typename Konteineris>
void dalinimas_i_kategorijas_1(Konteineris&studentai, Konteineris&tinginiai, Konteineris&darbstuoliai);
template <typename Konteineris>
void dalinimas_i_kategorijas_2(Konteineris&studentai, Konteineris&tinginiai);
template <typename Konteineris>
void dalinimas_i_kategorijas_3(Konteineris&studentai, Konteineris&tinginiai, Konteineris&darbstuoliai);
void testas_1(int n);
template <typename Konteineris>
void testas_2(Konteineris&studentai, int n);
template <typename Konteineris>
void vector_list_deque(Konteineris& studentai);
template <typename Konteineris>
void testas_3(Konteineris&studentai, int n);
template <typename Konteineris>
void dar_vienas_testas(Konteineris&studentai, int n);
#include "funkcijos.tpp"