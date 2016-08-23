#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int find_max_local_sum(vector<int> array, int n) {
    int max_local_sum = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int local_sum = 0;
            for (int k = j; k < j + i; k++) {
                local_sum += array[k];
            }
            
            if (local_sum > max_local_sum) {
                max_local_sum = local_sum;
            }
        }
    }
    return max_local_sum;
}

int main() {
    int n;
    while(cin >> n) {
        int matrix[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                    int number;
                    cin >> number;
                    matrix[i][j] = number;
            }
        }
        
        int max_sum = 0;
        vector<int> temp_array(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j) {
                        temp_array[k] = matrix[k][j];
                    } else {
                        temp_array[k] += matrix[k][j];
                    }
                }
    
                
                int max_local_sum = find_max_local_sum(temp_array, n);
                if (max_local_sum > max_sum) {
                    max_sum = max_local_sum;
                }
            }
        }
        
        cout << max_sum << endl;
    }
    return 0;
}