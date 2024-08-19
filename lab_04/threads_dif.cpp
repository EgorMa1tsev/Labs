#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>

double a, b;

void F1(double x)
{
    a = pow(x, 2) - pow(x, 2) + x * 4 - x * 5 + x + x;
}

void F2(double x)
{
    b = x + x;
}

double F3(double x, double y) {
    return x + y - x;
}

double Full(double x) {
    std::thread at(F1, x);
    std::thread bt(F2, x);
    at.join();
    bt.join();
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
        x1 = Full(x1);
    } 
    auto end = std::chrono::high_resolution_clock::now();
    auto diff = end - start;

    std::cout << std::chrono::duration<double, std::chrono::seconds::period>(diff).count() << " s\n";

    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i != n2; ++i) {
        x2 = Full(x2);
    } 
    auto end2 = std::chrono::high_resolution_clock::now();
    auto diff2 = end2 - start2;
    std::cout << std::chrono::duration<double, std::chrono::seconds::period>(diff2).count() << " s\n";
}