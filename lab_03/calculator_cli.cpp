#include <vector>
#include <cstdlib>
#include <stdexcept>
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

double convertToDouble(char* str) 
{
    char* endptr{};
    double value = strtod(str, &endptr);
    if (*endptr != '\0' || endptr == str) {
        throw std::invalid_argument("Error");
    }
    return value;
}




int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Input error" << std::endl;
        return 1;
    }

    char op = *argv[argc - 1];
    std::vector<double> vecnew;

    try {
        for (int i = 1; i < argc - 1; ++i) {
            vecnew.push_back(convertToDouble(argv[i]));
        }

        if (op == '^') {
            for (int i = 1; i < argc - 1; ++i) {
                if (static_cast<int>(vecnew[i]) != vecnew[i]) {
                    throw std::invalid_argument("error");
                }
            }
            std::cout << powf(vecnew[0], static_cast<int>(vecnew[1])) << std::endl;
            return 0;
        }

        if (op == '+') {
            std::cout << sum(vecnew[0], vecnew[1]) << std::endl;
        }

        if (op == 'x') {
            std::cout << multiply(vecnew[0], vecnew[1]) << std::endl;
        }

        if (op == '-') {
            std::cout << sub(vecnew[0], vecnew[1]) << std::endl;
        }

        if (op == '/') {
            std::cout << div(vecnew[0], vecnew[1]) << std::endl;
        }


    } catch (const std::invalid_argument& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    } catch (const std::exception& ex2) {
        std::cerr << "Error: " << ex2.what() << '\n';
        return 1;
    }

    return 0;
}