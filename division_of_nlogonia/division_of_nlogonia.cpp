#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    int num_queries = -1;
    while (cin >> num_queries && num_queries != 0) {
        int division_x, division_y;
        cin >> division_x >> division_y;
        for (int i = 0; i < num_queries; i++) {
            int x, y;
            cin >> x >> y;

            if (x == division_x || y == division_y) {
                cout << "divisa" << endl;
            } else if (x < division_x && y > division_y) {
                cout << "NO" << endl;
            } else if (x > division_x && y > division_y) {
                cout << "NE" << endl;
            } else if (x > division_x && y < division_y) {
                cout << "SE" << endl;
            } else {
                cout << "SO" << endl;
            }
        }
    }
    return 0;
}
