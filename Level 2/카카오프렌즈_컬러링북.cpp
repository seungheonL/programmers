#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool valid(int x, int y, int M, int N)
{
    return 0 <= x && x < M && 0 <= y && y < N;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int number_of_area = 0;
    int max_size_of_one_area = -1;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j] && picture[i][j] != 0)
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int area = 1;

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int i=0; i<4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(valid(nx, ny, m, n) && !visited[nx][ny] && (picture[nx][ny] == picture[x][y]))
                        {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            area++;    
                        }
                    }
                }

            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
