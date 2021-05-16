#ifndef TE_FLOAT_H_
#define TE_FLOAT_H_

/// \file TE_Float.h
/// Author: Philip Botha
/// Float is defined and the size is validated to ensure AUTOSAR compliance.

#include <limits>

namespace TE {
    using float32_t = float; // polyspace AUTOSAR-CPP14:A3-9-1 [Justified:Low] "Is tested to ensure 32 bits and IEEE-754"
    static_assert(sizeof(float32_t) == 4U, "Float is not 32 bits");
    static_assert(std::numeric_limits<float32_t>::is_iec559, "Not IEEE-754 float");

    using float64_t = double; // polyspace AUTOSAR-CPP14:A3-9-1 [Justified:Low] "Is tested to ensure 64 bits and IEEE-754"
    static_assert(sizeof(float64_t) == 8U, "double is not 64 bits");
    static_assert(std::numeric_limits<float64_t>::is_iec559, "Not IEEE-754 float");
} // namespace TE

#endif //TE_FLOAT_H_