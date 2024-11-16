#include <iostream>
#include <chrono>
#include <vector>
#include "fibonacci.h"

#include "gnuplot-iostream.h"


void measureTime(int n, std::vector<double>& classicTimes, std::vector<double>& optimizedTimes) {
    auto start = std::chrono::high_resolution_clock::now();
    long long classicResult = Fibonacci::classic(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> classicDuration = end - start;
    classicTimes.push_back(classicDuration.count());


    start = std::chrono::high_resolution_clock::now();
    long long optimizedResult = Fibonacci::optimized(n);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> optimizedDuration = end - start;
    optimizedTimes.push_back(optimizedDuration.count());

    std::cout << "Fibonacci(" << n << ") - Classic: " << classicResult
              << ", Time: " << classicDuration.count() << "s" << std::endl;
    std::cout << "Fibonacci(" << n << ") - Optimized: " << optimizedResult
              << ", Time: " << optimizedDuration.count() << "s" << std::endl;
}

int main() {
    std::vector<int> nValues;
    std::vector<double> classicTimes;
    std::vector<double> optimizedTimes;

    for (int i = 0; i <= 30; ++i) {
        nValues.push_back(i);
        measureTime(i, classicTimes, optimizedTimes);
        Fibonacci::clearCache();
    }

    Gnuplot gp;
    gp << "set title 'Fibonacci Calculation Time'\n";
    gp << "set xlabel 'n'\n";
    gp << "set ylabel 'Time (s)'\n";
    gp << "plot '-' using 1:2 with lines title 'Classic', '-' using 1:2 with lines title 'Optimized'\n";

    // Создаем вектор пар вручную
    std::vector<std::pair<int, double>> classicData;
    for (size_t i = 0; i < nValues.size(); ++i) {
        classicData.push_back(std::make_pair(nValues[i], classicTimes[i]));
    }

    std::vector<std::pair<int, double>> optimizedData;
    for (size_t i = 0; i < nValues.size(); ++i) {
        optimizedData.push_back(std::make_pair(nValues[i], optimizedTimes[i]));
    }

    // Отправляем данные
    gp.send1d(classicData);
    gp.send1d(optimizedData);

    return 0;
}
