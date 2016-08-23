#include <iostream>
#include <cstdlib>
#include <tuple>
#include <thread>        
#include <chrono> 
#include <algorithm>

using namespace std;

int main()
{
	int h, w;
	while ((cin >> h >> w) && (h != 0 && w != 0))
	{
		int visits[5] = {0, 0, 0, 0, 0};
		int maze[h][w];
		for (int i = 0; i < h; i++)
		{
			string line;
			cin >> line;
			for (int j = 0; j < line.size(); j++)
			{
				int cell =  line[j] - '0';
				if (cell == 1)
				{
					maze[i][j] = -1;
				} else if (cell == 0) {
					visits[0]++;
					maze[i][j] = cell;
				}
			}
		}

		int look_at = 0;
		tuple<int,int> robot(h - 1, 0);
		array<tuple<int, int>, 4> directions = { make_tuple(0,1), make_tuple(-1,0), make_tuple(0,-1), make_tuple(1,0) }; // east, north, west and south
		do 
		{
			visits[maze[get<0>(robot)][get<1>(robot)]]--;
			maze[get<0>(robot)][get<1>(robot)]++;
			visits[maze[get<0>(robot)][get<1>(robot)]]++;

			int move_y, move_x, next_y, next_x;
			bool turn = false;
			do 
			{
				if (turn)
				{
					look_at = (look_at + 1) % 4;
				}

				// robot tries to move to right of where he is looking
				int move_dir = look_at - 1;
				if (move_dir < 0)
					move_dir = 3;
				tie(move_y, move_x) = directions[max(0, move_dir)];

				next_y = get<0>(robot) + move_y;
				next_x = get<1>(robot) + move_x;

				turn = true; // next time it tries, turn the robot 
			} while (next_y >= h || next_y < 0 || next_x >= w || next_x < 0 || maze[next_y][next_x] < 0);

			// reset robot to look to where he moved
			for (int i = 0; i < 4; i++)
			{
				if (make_tuple(move_y, move_x) == directions[i])
				{
					look_at = i;
				}
			}

			get<0>(robot) += move_y;
			get<1>(robot) += move_x;
		} while(get<0>(robot) != h-1 || get<1>(robot) != 0);

		for (int i = 0; i < 5; i++) {
            std::cout.width(3); std::cout << std::right << visits[i];
        }
        cout << endl;
	}
	return 0;
}