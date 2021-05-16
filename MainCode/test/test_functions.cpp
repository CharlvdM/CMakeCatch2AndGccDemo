/// \file test_functions.cpp
/// Author: Charl van de Merwe

#include <catch2/catch.hpp>
// Include the header files of the units to be tested here
#include "functions.h"

TEST_CASE("Test the rotatingVector function") {
    TE::float32_t angle {180.0F};
    angle = TE::runRotatingVector(angle, 180.0F);
    REQUIRE(static_cast<std::uint32_t>(angle) == 0U);
    angle = 90.0F;
    angle = TE::runRotatingVector(angle, 360.0F);
    REQUIRE(static_cast<std::uint32_t>(angle) == 90U);
}

