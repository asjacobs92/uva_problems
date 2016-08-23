#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int num_cases;
    cin >> num_cases;

    for(int i = 0; i < num_cases; i++)
    {
        int num_objects;
        cin >> num_objects;

        int prices[num_objects];
        int weights[num_objects];

        for(int j = 0; j < num_objects; j++) {
            cin >> prices[j] >> weights[j];
        }

        int max_values[31];
        for(int j = 0; j < 31; j++) {
            max_values[j] = 0;
        }

        for(int j = 0; j < num_objects; j++)
        {
            for(int k = 30; k >= 0; k--)
            {
                if((weights[j] <= k) && (max_values[k] < max_values[k - weights[j]] + prices[j])) {
                    max_values[k] = max_values[k - weights[j]] + prices[j];
                }
            }
        }

        int  num_people, people_weight, max_value = 0;
        cin >> num_people;
        for(int j = 0; j < num_people; j++)
        {
            cin >> people_weight;
            max_value += max_values[people_weight];
        }

        cout << max_value << endl;
    }
    return 0;
}