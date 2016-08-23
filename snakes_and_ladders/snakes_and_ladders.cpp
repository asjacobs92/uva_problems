#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() 
{
	int num_cases = 0;

	cin >> num_cases;
	for (int i = 0; i < num_cases; i++) 
	{
		bool end_game = false;

		int num_players = 0;
		int num_warps = 0;
		int num_dice_rolls = 0;

		map<int, int> players;
		map<int, int> warps;

		cin >> num_players >> num_warps >> num_dice_rolls;
		for (int j = 0; j < num_players; j++)
		{
			players[j] = 1;
		}

		for (int j = 0; j < num_warps; j++) 
		{
			int warp_start;
			int warp_end;

			cin >> warp_start >> warp_end;
			warps[warp_start] = warp_end;
		}

		for (int j = 0; j < num_dice_rolls; j++) 
		{
			int dice_roll = 0;
			cin >> dice_roll;

			if (!end_game)
			{
				int player = j % num_players;
				int new_player_pos = min(players[player] + dice_roll, 100);
				if (warps[new_player_pos] != 0)
					new_player_pos = warps[new_player_pos];
				
				players[player] = new_player_pos;
				if (players[player] == 100)
					end_game = true;
			}
		}

		for (int j = 0; j < num_players; j++)
		{
			cout << "Position of player " << j + 1 << " is " << players[j] << "." << endl;
		}	
	}
	return 0;
}