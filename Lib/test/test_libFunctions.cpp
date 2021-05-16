/// \file test_libFunctions.cpp
/// Author: Charl van de Merwe

#include <catch2/catch.hpp>
// Include the header files of the units to be tested here
#include "libFunctions.h"

namespace {
    constexpr TE::float32_t PI{ 3.141592653589793238462643383279502F };
} // namespace

SCENARIO("Test the roundToDecimal function") {
    GIVEN("A float value of 12.654895 to round off") {
        constexpr TE::float32_t val{ 12.654895F };
        WHEN("The roundToDecimal function is called with different decimal places") {
            THEN("The float is rounded accordingly") {
                REQUIRE(TE::floatToScaledDecimal(val, 0U) == 13UL);
                REQUIRE(TE::floatToScaledDecimal(val, 2U) == TE::floatToScaledDecimal(12.65F, 2U));
                REQUIRE(TE::floatToScaledDecimal(val, 5U) == TE::floatToScaledDecimal(12.65490F, 5U));
            }
        }
    }
}

SCENARIO("Test the degToRad function") {
    GIVEN("...") {
        WHEN("The bindAngle function is called with various angles") {
            THEN("The returned angle is bounded to within 2 pi") {
                REQUIRE(TE::floatToScaledDecimal(TE::degToRad(0.0F), 5U) == 0UL);
                REQUIRE(TE::floatToScaledDecimal(TE::degToRad(45.0F), 5U) == TE::floatToScaledDecimal(PI / 4.0F, 5U));
                REQUIRE(TE::floatToScaledDecimal(TE::degToRad(-15.65F), 5U) == TE::floatToScaledDecimal(-0.27314F, 5U));
            }
        }
    }
}

SCENARIO("Test the bindAngle function") {
    GIVEN("A bound of 2 pi") {
        constexpr TE::float32_t bound{ 2.0F * PI };
        WHEN("The bindAngle function is called with various angles") {
            THEN("The returned angle is bounded to within 2 pi") {
                REQUIRE(TE::floatToScaledDecimal(TE::bindAngle(2.0F * PI, bound), 5U) == 0UL);
                REQUIRE(TE::floatToScaledDecimal(TE::bindAngle(TE::degToRad(412.5F), bound), 5U) ==
                    TE::floatToScaledDecimal(TE::degToRad(52.5F), 5U));
            }
        }
    }
}

