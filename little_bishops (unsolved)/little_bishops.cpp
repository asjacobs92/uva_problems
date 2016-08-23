#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

unsigned int factorial(unsigned int n)
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}

int binomial(int n, int k)
{
    if (k > n)
        return 0;

    if (k == 0 || k == n)
        return 1;

    return binomial(n-1, k-1) + binomial(n-1, k);
}

int stirling_2(int n, int k) {
    if (k > n)
        return 0;

    if (k == 0 || k == n)
        return 1;

    return stirling_2(n-1, k-1) + (k * stirling_2(n-1, k));
}


int knbishops(int k, int n) {
    if(n == 1) {
        if (k == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int result = factorial(pow((-1), k)/((2*n)-k));
        int sum_final = 0;
        for (int i = max(0, k - n); i <= min(k, n); i++) {
            int b = binomial((2*n)-k, n-k+i);
            int sum_a = 0;
            for (int j = 1; j <= n - i; j++) {
                sum_a += pow((-1), i) * binomial(n-i, j) * pow(j, floor(n/2)) * pow(j+1, floor(n+1/2));
            }

            int sum_b = 0;
            for (int j = 1; j <= n + i - k; j++) {
                sum_b += pow(-1, j) * binomial(n-k+i, j) * pow(j, floor(n+1/2)) * pow(j+1, floor(n/2));
            }
            sum_final += sum_a * sum_b;
        }
        return result * sum_final;
    }
}


int main() {
    int n = -1, k = -1;
    while ((cin >> n >> k) && n != 0 && k != 0) {
        cout << knbishops(k, n) << endl;
    }

    return 0;
}
