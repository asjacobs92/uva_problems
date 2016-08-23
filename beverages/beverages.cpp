#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;

int main() {
    int case_count = 0;
    int num_beverages, num_relations = 0;

    while (cin >> num_beverages) {
        case_count++;

        map<string, int> beverages_by_name;
        map<int, string> beverages_by_index;
        vector<int> ordered_beverages;
        vector<int> in_degree(num_beverages, 0);
        map<int, vector<int> > beverages_relations;

        for (int i = 0; i < num_beverages; i++) {
            string beverage;
            cin >> beverage;
            beverages_by_name[beverage] = i;
            beverages_by_index[i] = beverage;
        }

        cin >> num_relations;
        for (int i = 0; i < num_relations; i++) {
            string beverage_before, beverage_after;
            cin >> beverage_before >> beverage_after;
            beverages_relations[beverages_by_name[beverage_before]].push_back(beverages_by_name[beverage_after]);
            in_degree[beverages_by_name[beverage_after]]++;
        }

        priority_queue<int, vector<int>, greater<int> > beverage_orders;
        for (int i = 0; i < num_beverages; i++) {
            if (in_degree[i] == 0) {
                beverage_orders.push(i);
            }
        }

        while (!beverage_orders.empty()) {
            int beverage = beverage_orders.top();
            beverage_orders.pop();
            ordered_beverages.push_back(beverage);

            vector<int> beverages_after = beverages_relations[beverage];
            for (int i = 0; i < beverages_after.size(); i++) {
                in_degree[beverages_after[i]]--;
                if (in_degree[beverages_after[i]] == 0) {
                    beverage_orders.push(beverages_after[i]);
                }
            }
        }

        cout << "Case #" << case_count << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < num_beverages; i++) {
            cout << " " << beverages_by_index[ordered_beverages[i]];
        }
        cout << "." << endl;

        string blank_line;
        getline(cin, blank_line);
        cout << endl;
    }

    return 0;
}