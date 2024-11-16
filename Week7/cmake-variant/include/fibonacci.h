#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <unordered_map>

class Fibonacci {
public:
    static long long classic(int n);
    static long long optimized(int n);
    static void clearCache(); // Метод для очистки кеша

private:
    static std::unordered_map<int, long long> cache; // Кеш для оптимизированной реализации
};

#endif // FIBONACCI_H

