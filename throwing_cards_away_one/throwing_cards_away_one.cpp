#include <iostream>
#include <deque>

using namespace std;

int main() {
	
	int num_cards = -1;
	while (cin >> num_cards && num_cards != 0)
	{
		deque<int> cards;
		for (int i = 1; i <= num_cards; i++)
		{
			cards.push_back(i);
		}
		
		cout << "Discarded cards:";
		while(cards.size() != 1)
		{
			cout << " " << cards.front();
			cards.pop_front();
			int new_top = cards.front();
			cards.pop_front();
			cards.push_back(new_top);
			if (cards.size() != 1)
				cout << ",";
		}
		cout << endl;
		cout << "Remaining card: " << cards.front() << endl;
	}
	
	return 0;
}
