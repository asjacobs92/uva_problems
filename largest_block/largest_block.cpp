#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <ctype.h>
#include <map>
#include <queue>
#include <climits>
#include <cstdio>
#include <iomanip>
#include <limits.h>

using namespace std;

int find_max_local_sum(vector<int> array, int n) {
    int max_local_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] < 0) {
            if (current_sum > max_local_sum) {
                max_local_sum = current_sum;
                current_sum = 0;
            }
        } else {
            current_sum += array[i];
        }
    }

    if (current_sum > max_local_sum) {
        max_local_sum = current_sum;
        current_sum = 0;
    }
    return max_local_sum;
}



int main () {
    int num_instances = 0;
    cin >> num_instances;

    for (int instance = 0; instance < num_instances; instance++) {
        int board_size = 0, num_blocks = 0;
        cin >> board_size >> num_blocks;
        vector<vector<int> > board(board_size, vector<int>(board_size, 1));

        for (int block = 0; block < num_blocks; block++) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            for (int row = r1 - 1; row <= r2 - 1; row++) {
                for (int col = c1 - 1; col <= c2 - 1; col++) {
                    board[row][col] = -1000000;
                }
            }
        }


        int max_sum = 0;
        vector<int> temp_array(board_size, 0);
        for (int i = 0; i < board_size; i++) {
            for (int j = i; j < board_size; j++) {
                for (int k = 0; k < board_size; k++) {
                    if (i == j) {
                        temp_array[k] = board[k][j];
                    } else {
                        temp_array[k] += board[k][j];
                    }
                }

                int max_local_sum = find_max_local_sum(temp_array, board_size);
                if (max_local_sum > max_sum) {
                    max_sum = max_local_sum;
                }
            }
        }

        cout << max_sum << endl;
    }

    return 0;
}