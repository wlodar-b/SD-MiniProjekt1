#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdint>
#include <limits>
#include <random>

// generator losowych liczb int32 z ustalonym seedem 
class RandomGenerator {
    static constexpr std::uint32_t SEED = 123456789u; // staly seed
    std::mt19937 rng;                                  // silnik Mersenne Twister
    std::uniform_int_distribution<std::int32_t> dist;  // rozklad rownomierny

public:
    RandomGenerator();          // inicjalizuje generator
    void reset();               // resetuje do stanu poczatkowego
    std::int32_t generate();    // zwraca losowa liczbe
};

#endif
