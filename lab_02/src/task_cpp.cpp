#include <iostream>
#include <string>
#include <chrono>

int Calculate(int x) {
    return x * x - x * x + x * 4 - x * 5 + x + x;
}

int main() {   
    while (true) {
        std::string str;
        std::cin >> str;
        
        for (char ch : str) {
            if (ch < '0' || ch > '9') {
                return 0;
            }
        }
        
        
        int n = std::stoi(str);
        int x = 2;
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i != n; ++i) {
            x =  Calculate(x);
        }
        auto finish = std::chrono::steady_clock::now();
        auto t = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
        std::cout << t.count() << "\n";
    }
}