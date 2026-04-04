#ifndef TIMEMEASURER_HPP
#define TIMEMEASURER_HPP

#include <vector>
#include <chrono>
#include <functional>

template <typename T>
class TimeMeasurer {
    T& original;
    int count;

public:
    TimeMeasurer(T& original, int count) : original(original), count(count) {}

    int measure(std::function<void(T&)> operation) {
        std::vector<T> copies;
        for (int i = 0; i < count; i++) {
            copies.push_back(original);
        }
        int total = 0;
        for (int i = 0; i < count; i++) {
            auto start = std::chrono::steady_clock::now();
            operation(copies[i]);
            auto end = std::chrono::steady_clock::now();
            total += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        }
        return total / count;
    }
};

#endif
