#include <iostream>
#include <vector>

void RE(int n) {
    std::vector<bool> Prime(n + 1, true);

    for (int p = 2; p * p <= n; ++p) {
        if (Prime[p]) {
            for (int i = p * p; i <= n; i += p)
                Prime[i] = false;
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (Prime[p]) std::cout << p << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter number n: ";
    std::cin >> n;
    RE(n);
    std::cout << "Press any key";
    std::cin.ignore();
    std::cin.get();;
    return 0;
}
