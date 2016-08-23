#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    
    long possible_combs[30001] = { 0 };
    int coins[5] = {1, 5, 10, 25, 50};
    int value;
    
    possible_combs[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = coins[i]; j < 30001; j++) {
            possible_combs[j] += possible_combs[j - coins[i]];
        }
    }
    
    while (cin >> value) {
        if (possible_combs[value] == 1) {
            cout << "There is only 1 way to produce " << value << " cents change." << endl;
        } else {
            cout << "There are " << possible_combs[value] << " ways to produce "<< value << " cents change." << endl;
        }
    }

    return 0;   
}