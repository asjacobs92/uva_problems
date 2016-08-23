#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main ()
{
    int num_sets = 0;
    cin >> num_sets;
    for (int i = 0; i < num_sets; i++)
    {
        int packages_to_deliver = 0;
        int num_stations, carrier_capacity, queue_capacity;
        cin >> num_stations >> carrier_capacity >> queue_capacity;

        vector<queue<int> > stations(num_stations);
        for (int j = 0; j < num_stations; j++)
        {
            int station_cargos;
            cin >> station_cargos;
            queue<int> station;
            for (int k = 0; k < station_cargos; k++)
            {
                int cargo;
                cin >> cargo;
                station.push(cargo - 1);
                packages_to_deliver++;
            }
            stations[j] = station;
        }

        int j = 0;
        int time_to_deliver = -2;
        stack<int> carrier;
        while (packages_to_deliver > 0)
        {
            while (!carrier.empty() && (carrier.top() == j || stations[j].size() < queue_capacity))
            {
                if (carrier.top() != j)
                    stations[j].push(carrier.top());
                else
                    packages_to_deliver--;

                carrier.pop();
                time_to_deliver++;
            }

            while (carrier.size() < carrier_capacity && !stations[j].empty())
            {
                carrier.push(stations[j].front());
                stations[j].pop();
                time_to_deliver++;
            }

            j = (j + 1) % num_stations;
            time_to_deliver += 2;
        }

        if (time_to_deliver < 0)
            time_to_deliver = 0;

        cout << time_to_deliver << endl;
    }
    return 0;
}
