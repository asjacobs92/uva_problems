#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <ctype.h>
#include <map>
#include <queue>
#include <climits>
#include <cstdio>

using namespace std;


bool myComparison(const pair<int,int> &left, const pair<int,int> &right) {
   if (left.second == right.second) {
        return left.first < right.first;
    } else {
        return left.second > right.second;
    }
}

int main()
{
	int lines;
	char c;
	map<int, int> alphabet;

	cin >> lines;

    c = 'a';

	for(int i=0; i<26; i++)
	{
	    alphabet[(int)c] = 0;
	    c++;
	}

	while(cin.get(c))
        alphabet[(int)tolower(c)]++;

    vector<pair<int, int> > vec;

    typedef map<int, int>::iterator it_type;
    for(it_type it = alphabet.begin(); it != alphabet.end(); it++)
    {
        if (it->first < 123 && it->first > 96)
            vec.push_back(make_pair(it->first, it->second));
        // iterator->first = key
        // iterator->second = value
        // Repeat if you also want to iterate through the second map.
    }

    std::sort(vec.begin(), vec.end(), myComparison);

    for (int i = 0; i < vec.size(); i++) {
        if(vec[i].second != 0) {
            char ch = (char)vec[i].first;
            ch = toupper(ch);
            cout << ch << " " << vec[i].second << endl;
        }
    }

 	return 0;
}
