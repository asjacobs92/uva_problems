#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

int main ()
{
    string first_line;
    getline(cin, first_line);
    stringstream ss(first_line);
    int num_cases;
    ss >> num_cases;
    for (int i = 0; i < num_cases; i++)
    {
        string answer;
        string team_out, judge_out;
        getline(cin, team_out);
        getline(cin, judge_out);

        string temp_team, temp_judge;
        temp_team = team_out;
        temp_judge = judge_out;

        temp_team.erase(remove_if(temp_team.begin(), temp_team.end(), (int(*)(int))isspace), temp_team.end());
        temp_judge.erase(remove_if(temp_judge.begin(), temp_judge.end(), (int(*)(int))isspace), temp_judge.end());

        if (temp_judge == temp_team && judge_out.size() != team_out.size())
        {
            answer = "Output Format Error";
        } else if (team_out != judge_out) {
            answer = "Wrong Answer";
        } else {
            answer = "Yes";
        }

        cout << "Case " << i + 1 << ": " << answer << endl;
    }
    return 0;
}
