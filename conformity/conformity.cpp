#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int main ()
{
    int num_frosh = -1;
    while (cin >> num_frosh && num_frosh != 0)
    {
        multiset<string> classes_by_frosh;
        for (int i = 0; i < num_frosh; i++)
        {
            vector<int> classes(5);
            for (int j = 0; j < 5; j++)
            {
                int frosh_class;
                cin >> frosh_class;
                classes[j] = frosh_class;
            }

            stringstream classes_as_string;
            sort(classes.begin(), classes.end());
            copy(classes.begin(), classes.end(), ostream_iterator<int>(classes_as_string, ""));
            classes_by_frosh.insert(classes_as_string.str());
        }

        multiset<int> popularity;
        int most_popular = 0;
        for (multiset<string>::const_iterator i(classes_by_frosh.begin()), end(classes_by_frosh.end()); i != end; ++i)
        {
            int count = classes_by_frosh.count(*i);
            popularity.insert(count);
            most_popular = max(count, most_popular);
        }

        cout << popularity.count(most_popular) << std::endl;
    }
    return 0;
}
