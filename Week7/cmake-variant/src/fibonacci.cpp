#include "fibonacci.h"

// Инициализация кеша
std::unordered_map<int, long long> Fibonacci::cache;

long long Fibonacci::classic(int n) {
    if (n < 0) throw std::invalid_argument("Negative input not allowed");
    if (n <= 1) return n;
    return classic(n - 1) + classic(n - 2);
}

long long Fibonacci::optimized(int n) {
    if (n < 0) throw std::invalid_argument("Negative input not allowed");
    if (n <= 1) return n;

    // Проверка кеша
    auto it = cache.find(n);
    if (it != cache.end()) {
        return it->second;
    }

    // Рекурсивный вызов с кешированием
    cache[n] = optimized(n - 1) + optimized(n - 2);
    return cache[n];
}

void Fibonacci::clearCache() {
    cache.clear();
}

