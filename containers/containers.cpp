#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main ()
{
    string containers;
    int num_cases = 1;
    while (cin >> containers && containers != "end")
    {
        vector<stack<char> > stacks;
        for (int i = 0; i < containers.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < stacks.size(); j++)
            {
                if (stacks[j].top() >= containers[i] && !found)
                {
                    stacks[j].push(containers[i]);
                    found = true;
                }
            }

            if (!found)
            {
                stack<char> new_stack;
                new_stack.push(containers[i]);
                stacks.push_back(new_stack);
            }
        }
        cout << "Case " << num_cases++ << ": " << stacks.size() << endl;
    }
    return 0;
}
