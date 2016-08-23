#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int num_cases = 0;
    cin >> num_cases;
    for (int i = 0; i < num_cases; i++) 
    {
        int ball = 1;
	    int num_pegs = 0;
        int current_peg = 0;

        cin >> num_pegs;
        vector<int> pegs(num_pegs, 0);
        do 
	{
	    int root = round(sqrt(pegs[current_peg] + ball));
            if (pegs[current_peg] == 0 || (root * root) == (pegs[current_peg] + ball))
            {
                pegs[current_peg] = ball++;
		current_peg = 0;
            } else {
                current_peg++;
            }
        } while (current_peg < pegs.size());
        cout << ball - 1 << endl;
    }
}
