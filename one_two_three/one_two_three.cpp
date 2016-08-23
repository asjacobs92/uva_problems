#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int num_cases = 0;
    cin >> num_cases;

    for (int i = 0; i < num_cases; i++) {
        string number;
        cin >> number;

        if (number.size() > 3) {
            cout << 3 << endl;
        } else {
            int mistakes = 0;
            if (number[0] != 'o') {
                mistakes++;
            }

            if (number[1] != 'n') {
                mistakes++;
            }

            if (number[2] != 'e') {
                mistakes++;
            }

            if (mistakes > 1) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }

        }
    }

    return 0;
}