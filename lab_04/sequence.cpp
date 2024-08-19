#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

double F1(double x) {
    return x * x - x * x + x * 4 - x * 5 + x + x;
}

double F2(double x) {
    return x + x;
}

double F3(double x, double y) {
    return x + y - x;
}

double Full(double x) {
    double a, b;
    a = F1(x);
    b = F2(x);
    return F3(a, b);
} 

int main() {
    double x1, x2;
    int n1 = 10000;
    int n2 = 100000;
    std::cin >> x1;
    x2 = x1;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i != n1; ++i) {
        Full(x1);
    } 
    auto end = std::chrono::high_resolution_clock::now();
    auto diff = end - start;

    std::cout << std::chrono::duration<double, std::chrono::seconds::period>(diff).count() << " s\n";

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i != n2; ++i) {
        Full(x2);
    } 
    auto end2 = std::chrono::high_resolution_clock::now();
    auto diff2 = end2 - start2;
    std::cout << std::chrono::duration<double, std::chrono::seconds::period>(diff2).count() << " s\n";
}