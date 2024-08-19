#include <iostream>
#include <string>
#include <list>

void Solver(char a, char b, char c, int n, std::list<std::string>& actions) {
    if (n == 1) {
        std::string str;
        str += a;
        str += " -> ";
        str += b;
        actions.push_back(str);
    } else {
        Solver(a, c, b, n - 1, actions);
        std::string str;
        str += a;
        str += " -> ";
        str += b;
        actions.push_back(str);
        Solver(c, b, a, n - 1, actions);
    }
        
}

int main() {
    std::list<std::string> actions;
    int n;
    std::cin >> n;
    Solver('A', 'C', 'B', n, actions);
    for (std::string act : actions) {
        std::cout << act << "\n";
    }
    actions.clear();
}