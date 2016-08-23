#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>


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
            if ( d[ g[v][i].first ] == -1 )
            {
                q.push(make_pair(w+g[v][i].second, g[v][i].first));
            }
        }
    }
    return -1;
}


int main() {
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++){
        int n, m, sourceNode, targetNode;
        cin >> n >> m >> sourceNode >> targetNode;

        vector<vector<pair<int,int> > > graph = vector<vector<pair<int,int> > >(n);
        for (int j = 0; j < m; j++) {
            int u, v, latency;
            cin >> u >> v >> latency;

            graph[u].push_back(make_pair(v, latency));
            graph[v].push_back(make_pair(u, latency));
        }

        int answer = dijkstra(graph, sourceNode, targetNode);
        cout << "Case #" << i << ": ";
        if (answer == -1) {
            cout << "unreachable" << endl;
        } else {
            cout << answer << endl;
        }
    }
    return 0;
}





