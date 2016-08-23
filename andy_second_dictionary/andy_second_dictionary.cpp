#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	vector<string> words;
	string next_word;
	while(cin >> next_word)
	{
		while (next_word.back() == '-')
		{
			next_word = next_word.substr(0, next_word.size()-1);
			string next_word_cont;
			cin >> next_word_cont;
			next_word += next_word_cont;
		}

		transform(next_word.begin(), next_word.end(), next_word.begin(), ::tolower);

		std::size_t prev = 0, pos;
		while ((pos = next_word.find_first_of(" .,!()1234567890@[]'<\">:/{}?_|=+;`~", prev)) != std::string::npos)
		{
			if (pos > prev)
			{
				string word = next_word.substr(prev, pos-prev);
				words.push_back(word);
			}

			prev = pos+1;
		}

		if (prev < next_word.length())
		{
			words.push_back(next_word.substr(prev, std::string::npos));
		}
	}


	sort(words.begin(), words.end());
	for (int i = 0; i < words.size(); i++)
	{
		if (i == 0 || (i > 0 && words[i-1] != words[i]))
		{
			cout << words[i] << endl;
		}
	}

	return 0;
}
