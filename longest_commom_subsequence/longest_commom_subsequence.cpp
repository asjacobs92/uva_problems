#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int m[1001][1001];

int main() {
    string sequenceOne;
    string sequenceTwo;

    while (getline(cin,sequenceOne)) {
      getline(cin,sequenceTwo);

      for(int i = 0; i <= sequenceOne.length(); i++) {
          m[i][0] = 0;
      }

      for(int i = 0; i <= sequenceOne.length(); i++) {
          m[0][i] = 0;
      }

      for(int i = 1; i <= sequenceOne.length(); i++){
          for(int j = 1; j <= sequenceTwo.length(); j++){
              m[i][j] = max(max(m[i-1][j], m[i][j-1]), (sequenceOne[i-1] == sequenceTwo[j-1]) + m[i-1][j-1]);
          }
      }

        cout << m[sequenceOne.length()][sequenceTwo.length()] << endl;
    }

    return 0;
}