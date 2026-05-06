#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mylib.h"
TEST_CASE("Default konstruktorius", "[Default] [konstruktorius]")
{
    Studentas stud;
    REQUIRE(stud==Studentas("Vardas", "Pavarde", { }, 0));
}