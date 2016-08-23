#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    string num_cases_str;
    getline(cin, num_cases_str);
    int num_cases = atoi(num_cases_str.c_str());


    for (int i = 0; i < num_cases; i++) {
        string numbers_str;
        getline(cin, numbers_str);
        istringstream iss(numbers_str);
        vector<int> numbers;
        int number = 0;
        while(iss >> number) {
            numbers.push_back(number);
        }

        int max_gcd = 0;
        for (int j = 0; j < numbers.size() - 1; j++) {
            for (int k = j + 1; k < numbers.size(); k++) {
                int pair_gcd = gcd(numbers[j], numbers[k]);
                max_gcd = (pair_gcd > max_gcd) ? pair_gcd : max_gcd;
            }
        }
        cout << max_gcd << endl;
    }

    return 0;
}