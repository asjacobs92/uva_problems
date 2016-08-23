#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int get_cost(priority_queue<int, vector<int>, greater<int> > values) 
{
	int sum = 0;
	while (values.size() > 1) 
	{
		int inter_sum = values.top();
		values.pop();
		inter_sum += values.top();
		values.pop();
		sum += inter_sum;
		values.push(inter_sum);
	}
	return sum;
}

int main() 
{
	int input_length = -1;
	while ((cin >> input_length) && input_length != 0) 
	{
		priority_queue<int, vector<int>, greater<int> > values;
		for (int i = 0; i < input_length; i++) 
		{
			int number;
			cin >> number;
			values.push(number);
		}

		int cost = get_cost(values);
		cout << cost << endl;  	
	}

	return 0;
}
