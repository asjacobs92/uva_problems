#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int dijkstra(vector<vector<pair<int,int> > > g, int source, int target)
{
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
    vector<int> d(g.size(), -1);
    pair<int, int> p;
    int v, w;
    q.push(make_pair(0, source));
    while (!q.empty())
    {
        p = q.top(); q.pop();
        v = p.second;
        w = p.first;

        if (d[v] != -1)
            continue;
        if (v == target)
            return w;
        d[v] = w;

        for (int i = 0; i < g[v].size(); ++i)
        {
            if (d[ g[v][i].first ] == -1)
            {
                q.push(make_pair(w+g[v][i].second, g[v][i].first));
            }
        }
    }
    return -1;
}


int main() {
    int set_count = 1;
    int num_borders = 0;

    while (cin >> num_borders) {
        vector<vector<pair<int,int> > > map = vector<vector<pair<int,int> > >(20);
        for (int i = 0; i < num_borders; i++) {
            int country;
            cin >> country;
            map[0].push_back(make_pair(country - 1, 1));
            map[country - 1].push_back(make_pair(0, 1));
        }

        for (int i = 1; i < 19; i++) {
            cin >> num_borders;
            for (int j = 0; j < num_borders; j++) {
                int country;
                cin >> country;
                map[i].push_back(make_pair(country - 1, 1));
                map[country - 1].push_back(make_pair(i, 1));
            }
        }

        cout << left << "Test Set #" << set_count++ << endl;
        int num_tests = 0;
        cin >> num_tests;
        for (int i = 0; i < num_tests; i++) {
            int source, target;
            cin >> source >> target;
            int answer = dijkstra(map, source - 1, target - 1);
            cout << right << setw(2) << source << setw(3) << " to " << setw(2) <<  target << setw(2) << ": " << left << answer << endl;
        }
        cout << endl;
    }

    return 0;
}





