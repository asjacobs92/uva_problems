#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;


int main() {
    int num_cases = 0, node_a = 0, node_b = 0;
    while (cin >> node_a && cin >> node_b && node_a != 0 && node_b != 0) {
        vector<vector<int> > graph(101, vector<int>(101,100000));
        graph[node_a][node_b] = 1;
        int largest_node = max(node_a,node_b);
        while (cin >> node_a && cin >> node_b && node_a != 0 && node_b != 0) {
            graph[node_a][node_b] = 1;
            largest_node = max(largest_node, max(node_a, node_b));
        }


        for (int i = 1; i <= largest_node; i++) {
            for (int j = 1; j <= largest_node; j++) {
                for (int k = 1; k <= largest_node; k++) {
                    if (i != j) {
                        graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                    }
                }
            }
        }

        int sum_clicks = 0, num_combs = 0;
        for (int i = 1; i <= largest_node; i++) {
            for (int j = 1; j <= largest_node; j++) {
                if (i != j && graph[i][j] != 100000) {
                    num_combs++;
                    sum_clicks += graph[i][j];
                }
            }
        }
        float num_clicks = (float) sum_clicks / num_combs;


        cout << fixed << setprecision(3) << "Case "<< ++num_cases <<": average length between pages = " << (float) num_clicks << " clicks" << endl;
    }
    return 0;
}