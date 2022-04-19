#include <iostream>

int main (int argc, char *argv[])
{
    int n, p;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> p;
        if (p > 8000) {
            std::cout << "Mais de 8000!\n";
        } else{
            std::cout << "Inseto!\n";
        }
    }
    return 0;
}
