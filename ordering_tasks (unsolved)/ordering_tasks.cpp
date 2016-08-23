#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

void insert_task(vector<int> &tasks, vector<bool> &visited, vector<vector<int> > &orders, int task) {
    vector<int> tasks_after = orders[task];
    for (int i = 0; i < tasks_after.size(); i++) {
        if (!visited[tasks_after[i]]) {
            insert_task(tasks, visited, orders, tasks_after[i]);
        }
    }

    visited[task] = true;
    tasks.insert(tasks.begin(), task + 1);
    //tasks.push_back(task + 1);
}


int main() {
    int num_tasks, num_precedences = -1;

    while ((cin >> num_tasks >> num_precedences) && (num_tasks != 0) && (num_precedences != 0)) {
        vector<int> tasks;
        vector<bool> visited(num_tasks, false);
        vector<vector<int> > orders(num_tasks);

        for (int i = 0; i < num_precedences; i++) {
            int task_before, task_after;
            cin >> task_before >> task_after;
            orders[task_before-1].push_back(task_after-1);
        }

        for (int i = 0; i < num_tasks; i++) {
            if(!visited[i]) {
                insert_task(tasks, visited, orders, i);
            }
        }

        cout << tasks[0];
        for (int i = 1; i < tasks.size(); i++) {
            cout << " " << tasks[i];
        }
        cout << endl;
    }

    return 0;
}