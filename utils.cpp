#include "utils.hpp"

RandomGenerator::RandomGenerator()
    : rng(SEED),
      dist(std::numeric_limits<std::int32_t>::min(),
           std::numeric_limits<std::int32_t>::max())
{}

void RandomGenerator::reset() {
    rng.seed(SEED);
}

std::int32_t RandomGenerator::generate() {
    return dist(rng);
}
