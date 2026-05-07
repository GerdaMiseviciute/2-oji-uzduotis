#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "mylib.h"
TEST_CASE("Default konstruktorius", "[Default] [konstruktorius]")
{
    Studentas stud;
    REQUIRE(stud==Studentas("Vardas", "Pavarde", { }, 0));
}
TEST_CASE("Konstruktorius su parametrais", "[Konstruktorius] [su] [parametrais]")
{
    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    REQUIRE(Stud==Studentas("Vardenis", "Pavardenis", {5, 8, 3}, 9));
}
TEST_CASE("Destruktorius", "[Destruktorius]")
{
    {
        Studentas s("Vardenis", "Pavardenis", {5,8,3}, 9);
    }
    SUCCEED("Destruktorius: [OK]");
}
TEST_CASE("Kopijavimo konstruktorius", "[Kopijavimo] [konstruktorius]")
{
    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    Studentas stud(Stud);
    REQUIRE(stud==Stud);
}
TEST_CASE("Kopijavimo priskyrimas", "[Kopijavimo] [priskyrimas]")
{
    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    Studentas stud;
    stud=Stud;
    REQUIRE(stud==Stud);
}
TEST_CASE("Move konstruktorius", "[Move] [konstruktorius]")
{
    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    Studentas stud(std::move(Stud));
    REQUIRE(stud==Studentas("Vardenis", "Pavardenis", {5, 8, 3}, 9));
    REQUIRE(Stud.Clear()==true);
}
TEST_CASE("Move priskyrimas", "[Move] [priskyrimas]")
{
    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    Studentas stud;
    stud=std::move(Stud);
    REQUIRE(stud==Studentas("Vardenis", "Pavardenis", {5, 8, 3}, 9));
    REQUIRE(Stud.Clear()==true);
}
TEST_CASE("Ivesties metodas", "[Ivesties] [metodas]")
{
    std::istringstream in("Jonas Jonaitis 10 9 8 7");
    Studentas s;
    in >> s;
    REQUIRE(s.getVardas()=="Jonas");
    REQUIRE(s.getPavarde()=="Jonaitis");
    REQUIRE(s.getEgzaminas()==7);
}
TEST_CASE("Isvesties metodas", "[Isvesties] [metodas]")
{
    Studentas s1("Jonas", "Jonaitis", {10, 9, 8}, 7);
    std::ostringstream out;
    out << s1;
    REQUIRE(out.str().find("Jonas") != string::npos);
    REQUIRE(out.str().find("Jonaitis") != string::npos);
}
TEST_CASE("Getteriai", "[Getteriai]")
{
    Studentas Stud("Vardenis", "Pavardenis", {5, 8, 3}, 9);
    REQUIRE(Stud.getVardas()=="Vardenis");
    REQUIRE(Stud.getPavarde()=="Pavardenis");
    REQUIRE(Stud.getEgzaminas()==9);
    REQUIRE(Stud.getGalutinis()==Stud.Galutinis());
    REQUIRE(Stud.getGalutinis_mediana()==Stud.Galutinis_mediana());
}

void testuoti()
{
    int argc=1;
    char* argv[]={(char*)"testai"};
    Catch::Session().run(argc, argv);
}