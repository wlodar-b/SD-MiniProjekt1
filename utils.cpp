#include "utils.hpp"

// inicjalizuje generator z ustalonym seedem i zakresem int32
RandomGenerator::RandomGenerator()
    : rng(SEED),
      dist(std::numeric_limits<std::int32_t>::min(),
           std::numeric_limits<std::int32_t>::max())
{}

// resetuje generator do stanu poczatkowego (ten sam seed = te same liczby)
void RandomGenerator::reset() {
    rng.seed(SEED);
}

// zwraca losowa liczbe z zakresu int32
std::int32_t RandomGenerator::generate() {
    return dist(rng);
}
