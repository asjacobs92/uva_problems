#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int num_nodes = -1;
    
    while ((cin >> num_nodes) && num_nodes != 0) {
        int num_edges;
        cin >> num_edges;
        
        vector< vector<int> > graph(num_nodes, vector<int>(num_nodes, 0));
        for (int i = 0; i < num_edges; i++) {
            int start, end;
            cin >> start >> end;
            graph[start][end] = 1;
        }
        
        bool bicolorable = true;
        vector<int> colors(num_nodes, -1);
        colors[0] = 1;
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (graph[i][j] == 1) {
                    if (colors[i] == -1 && colors [j] != -1) { 
                        colors[i] = 1 - colors[j];
                    } else if (colors[j] == -1 && colors [i] != -1) {
                        colors[j] = 1 - colors[i];
                    }
                }        
            }
        }
        
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (graph[i][j] == 1 && colors[i] == colors[j]) {
                    bicolorable = false;
                }        
            }
        }
        
        
        if (bicolorable)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
}