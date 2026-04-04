#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdint>
#include <limits>
#include <random>

class RandomGenerator {
    static constexpr std::uint32_t SEED = 123456789u;
    std::mt19937 rng;
    std::uniform_int_distribution<std::int32_t> dist;

public:
    RandomGenerator();
    void reset();
    std::int32_t generate();
};

#endif
