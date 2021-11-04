#include <string>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool valid(int x, int y)
{
	return 0 <= x && x < 5 && 0 <= y && y < 5;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
	
	for(const auto& place : places)
	{
		bool okay = true;
		
		for(int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				if(place[i][j] == 'P')
				{
					vector<vector<int>> dist(5, vector<int>(5, INF));
					queue<pair<pair<int, int>, int>> q;
							
					q.push({{i, j}, 0});
					dist[i][j] = 0;
							
					while(!q.empty())
					{
						int x = q.front().first.first;
						int y = q.front().first.second;
						int cnt = q.front().second;
						q.pop();
						
						if(!(x == i && y == j) && place[x][y] == 'P')
						{
							okay = false;
							break;
						}
						
						if(dist[x][y] == 2)
						{
							continue;
						}
							
						for(int k=0; k<4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							
							if(valid(nx, ny) && dist[nx][ny] == INF && place[nx][ny] != 'X')
							{
								dist[nx][ny] = dist[x][y] + 1;
								q.push({{nx, ny}, cnt + 1});
							}
						}
					}
					
					if(!okay)
					{
						break;
					}
				}
				
				if(!okay)
				{
					break;
				}
			}
			if(!okay)
			{
				break;
			}
		}
		
		if(okay)
		{
			answer.push_back(1);
		}
		else
		{
			answer.push_back(0);
		}
	}
	
    return answer;
}
