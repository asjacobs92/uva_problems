#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int find_max_sum_lower_than_n(vector<int> coins, int n) {
    vector<bool> possible_sums(25001, false);
    possible_sums[0] = true;
    for (int i = 1; i < coins.size(); i++) {
        for (int j = n; j >= 1; j--) {
            if(!possible_sums[j]) {
                possible_sums[j] = (coins[i] <= j) ? possible_sums[j - coins[i]] : false; 
            }
        }
    }
    
    int max_lower_sum = 0;
    for (int i = n; i >= 1; i--) {
        if (possible_sums[i]) {
            max_lower_sum = i;
            break;
        }
    }
    return max_lower_sum;
}

int main() {
    int num_cases;
    cin >> num_cases;
    
    for (int i = 0; i < num_cases; i++) {
        int num_coins, max_value = 0;
        cin >> num_coins;
        
        vector<int> coins(num_coins + 1);
        for(int i = 1; i <= num_coins; i++) {
            cin >> coins[i];
            max_value += coins[i];
        }
        
        int half_value = max_value / 2;
        int max_lower_sum = find_max_sum_lower_than_n(coins, half_value);
        cout << max_value - (max_lower_sum * 2) << endl;
    }
    
    return 0;
}