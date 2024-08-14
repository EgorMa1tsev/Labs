#include <iostream>
#include <string>
#include <cmath>

int main() {
    char act;
    double a, b;
    std::cin >> a >> act >> b;

    switch(act) {
        case '+':
            std::cout << a + b << "\n";
            break;
        case '-':
            std::cout << a - b << "\n";
            break;
        case '^':
            int power = (int)b;
            if (power < 0) {
                power = - power;
                a = 1 / a;
            }
            double result = 1;
            for (int i = 0; i != power; ++i) {
                result *= a;
            }
            std::cout << result << "\n";
            break;
    }
}