/// \file functions.cpp
/// Author: Charl van de Merwe

#include "functions.h"
#include "TE_Float.h"
#include "libFunctions.h"

namespace TE {
    float32_t runRotatingVector(const float32_t aAngle, const float32_t aAngleIncrement) noexcept {
        return bindAngle(aAngle + aAngleIncrement, 360.0F);
    }
} // namespace TE