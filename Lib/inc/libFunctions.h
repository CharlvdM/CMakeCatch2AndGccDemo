#ifndef LIBFUNCTIONS_H_
#define LIBFUNCTIONS_H_

/// \file libFunctions.h
/// Author: Charl van de Merwe

#include "TE_Float.h"
#include <cstdint>

namespace TE {
    /// Bind the input angle to [0.0F, aBound). Basically calculates the modules of the
    /// input by the bound.
    /// \param aAngle   input angle
    /// \return         the bounded angle
    [[nodiscard]] float32_t bindAngle(const float32_t aAngle, const float32_t aBound) noexcept;

    /// Convert degrees to radians
    /// \param deg      degrees
    /// \return         radians
    [[nodiscard]] float32_t degToRad(const float32_t deg) noexcept;

    /// Round a floating point value to the specified amount of decimal places and scale up to an integer value.
    /// The indented use for this function is comparing floating point values.
    /// \param aVal     value to round and scale
    /// \param aScale   specifies how far to "move" the comma to the right
    /// \return         the scaled and rounded value
    [[nodiscard]] std::int64_t floatToScaledDecimal(const float32_t aVal, const std::uint8_t aScale) noexcept;
} // namespace TE


#endif // LIBFUNCTIONS_H_