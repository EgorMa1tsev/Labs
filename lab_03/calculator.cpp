#include <vector>
#include <iostream>



double sum(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double div(double a, double b) {
    return a / b;
}

double powf(double a, int b) {
    if (b == 0) {
        return 1;
    } 
    if(b < 0) {
        return 1 / powf(a, -b);
    }

    b = static_cast<int>(b);
    double temp = powf(a, b/2);
    return b % 2 == 0 ? temp * temp : temp * temp * a;
}




int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Input error" << std::endl;
        return 1;
    }

    char op = *argv[2];
    double a = std::stod(argv[1]);
    double b = std::stod(argv[3]);

    if (op == '^') {
        std::cout << powf(a, static_cast<int>(b)) << std::endl;
    }

    if (op == '+') {
        std::cout << sum(a, b) << std::endl;
    }

    if (op == '*') {
        std::cout << multiply(a, b) << std::endl;
    }

    if (op == '-') {
        std::cout << sub(a, b) << std::endl;
    }

    if (op == '/') {
        std::cout << div(a, b) << std::endl;
    }

    return 0;
}