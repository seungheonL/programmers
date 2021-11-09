#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    dist[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if(maps[nx][ny] == 1 && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                    
                    if(nx == n-1 && ny == m-1)
                    {
                        return answer = dist[nx][ny];
                    }
                }
            }
        }
    }
    
    return -1;
}
