#include "catch.hpp"
#include <iostream>

#include "../args.h"

TEST_CASE("Test argument handling", "[args]")
{
    SECTION("Only backslashes")
    {
        auto args = Args(1, new char*[1] { "c:\\programs\\application\\executable.exe" });

        REQUIRE(args.executable() == "c:/programs/application/executable.exe");
    }

    SECTION("Mixed slashes and backslashes")
    {
        auto args = Args(1, new char*[1] { "c:\\programs\\application/executable.exe" });

        REQUIRE(args.executable() == "c:/programs/application/executable.exe");
    }

    SECTION("Only slashes")
    {
        auto args = Args(1, new char*[1] { "c:/programs/application/executable.exe" });

        REQUIRE(args.executable() == "c:/programs/application/executable.exe");
    }
}
