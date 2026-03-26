#include "utils.hpp"

#include <limits>
#include <random>

std::int32_t generateRandom4ByteNumber() {
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_int_distribution<std::int32_t> dist(
        std::numeric_limits<std::int32_t>::min(),
        std::numeric_limits<std::int32_t>::max()
    );

    return dist(rng);
}
