#include <iostream>
#include <vector>

// Функция заполняет массив Prime[],
// где Prime[x] = true, если x — простое число, и false в противном случае.
void sieve(int n, std::vector<bool>& Prime) {
    Prime.assign(n + 1, true); // Изначально считаем все числа простыми
    Prime[0] = false;
    Prime[1] = false; // 0 и 1 простыми числами не считаются

    for (int p = 2; p * p <= n; ++p) {
        if (Prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                Prime[i] = false;
            }
        }
    }
}

// Функция печатает все простые числа от 2 до n
void print_primes_up_to_n(int n, const std::vector<bool>& Prime) {
    std::cout << "Primes up to " << n << ": ";
    for (int p = 2; p <= n; ++p) {
        if (Prime[p]) {
            std::cout << p << " ";
        }
    }
    std::cout << "\n";
}

// Функция проверяет, простое ли число n (с опорой на результаты решета)
bool is_prime(int n, const std::vector<bool>& Prime) {
    if (n < 2) {
        return false;
    }
    // Предполагается, что вектор Prime заполнялся решетом до n
    return Prime[n];
}

// Функция факторизации числа n: выводит его простые множители
void factorize(int n, const std::vector<bool>& Prime) {
    std::cout << "Factorization of " << n << ": ";

    // Метод простой факторизации, используя список простых чисел (Prime)
    // или просто перебор делителей.
    // Так как у нас есть вектор простоты, используем primes.
    int temp = n;
    for (int p = 2; p * p <= temp; ++p) {
        // Если p — простое и делит temp, выводим p в факторизацию
        while (Prime[p] && (temp % p == 0)) {
            std::cout << p << " ";
            temp /= p;
        }
    }
    // Если после этого temp > 1, значит temp — либо 1, либо остаток, который сам прост
    if (temp > 1) {
        std::cout << temp;
    }
    std::cout << "\n";
}

int main() {
    int n;
    std::cout << "Enter number n: ";
    std::cin >> n;

    // Создаём вектор для отметки простых чисел
    std::vector<bool> Prime;
    sieve(n, Prime);              // Заполняем решето Эратосфена до n
    print_primes_up_to_n(n, Prime); // Выводим все простые числа до n

    // Проверка, простое ли само число n
    if (is_prime(n, Prime)) {
        std::cout << n << " is prime.\n";
    }
    else {
        std::cout << n << " is not prime.\n";
    }

    // Факторизация числа n
    factorize(n, Prime);

    // Ожидание ввода для паузы
    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}