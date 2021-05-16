/// \file libFunctions.cpp
/// Author: Charl van de Merwe

#include "libFunctions.h"
#include <cmath>

namespace {
    constexpr TE::float32_t PI {3.141592653589793238462643383279502F};
}

namespace TE {

    /// Bind the input angle to [0.0F, aBound). Basically calculates the modules of the
    /// input by the bound.
    [[nodiscard]] float32_t bindAngle(const float32_t aAngle, const float32_t aBound) noexcept {
        float32_t boundedAngle {aAngle};
        while (boundedAngle >= aBound) {
            boundedAngle -= aBound;
        }
        while (boundedAngle < 0.0F) {
            boundedAngle += aBound;
        }
        return boundedAngle;
    }

    /// Convert degrees to radians
    [[nodiscard]] float32_t degToRad(const float32_t deg) noexcept {
        constexpr float32_t HALF_CIRCLE_ANGLE_DEGREES {180.0F};
        return deg * (static_cast<float32_t>(PI) / HALF_CIRCLE_ANGLE_DEGREES);
    }

    /// Round a floating point value to the specified amount of decimal places and scale up to an integer value.
    /// The indented use for this function is comparing floating point values.
    [[nodiscard]] std::int64_t floatToScaledDecimal(const float32_t aVal, const std::uint8_t aScale) noexcept {
        constexpr float32_t TEN {10.0F}; // For complience with AutoSar: no literals in calculations
        const float32_t multiplier {std::pow(TEN, static_cast<float32_t>(aScale))};
        return static_cast<std::int64_t>(round(aVal * multiplier));
    }

} // namespace TE
