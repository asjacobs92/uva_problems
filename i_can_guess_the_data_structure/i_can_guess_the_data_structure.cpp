#include <iostream>
#include <stack>
#include <queue>
#include <vector>


using namespace std;

int main()
{
    int num_operation;
    while (cin >> num_operation) {
        int possible_structs[3] = {1, 2, 4} ; // 0 - stack, 1 - queue, 2 - priority_queue
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> priority_queue;

        for (int i = 0; i < num_operation; i++)
        {
            int operation, value;
            cin >> operation >> value;

            if (operation == 1)
            {
                stack.push(value);
                queue.push(value);
                priority_queue.push(value);
            } else {
                if (!stack.empty())
                {
                    if (stack.top() != value)
                        possible_structs[0] = 0;
                    stack.pop();
                } else {
                    possible_structs[0] = 0;
                }

                if (!queue.empty())
                {
                    if (queue.front() != value)
                        possible_structs[1] = 0;
                    queue.pop();
                } else {
                    possible_structs[1] = 0;
                }

                if (!priority_queue.empty())
                {
                    if (priority_queue.top() != value)
                        possible_structs[2] = 0;

                    priority_queue.pop();
                } else {
                    possible_structs[2] = 0;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += possible_structs[i];

        switch (sum) {
            case 0:
                cout << "impossible" << endl;
                break;
            case 1:
                cout << "stack" << endl;
                break;
            case 2:
                cout << "queue" << endl;
                break;
            case 4:
                cout << "priority queue" << endl;
                break;
            default:
                cout << "not sure" << endl;
                break;
        }
    }
    return 0;
}
