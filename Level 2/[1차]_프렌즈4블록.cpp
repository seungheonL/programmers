#include <string>
#include <vector>
#include <utility>
#include <set>
using namespace std;

const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    set<pair<int, int>> coordinates;
    
    while(true)
    {
        bool finish = true;
        
        coordinates.clear();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                bool match = true;
                
                for(int k=0; k<3; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    
                    if(!(0 <= nx && nx < m && 0 <= ny && ny <n))
                    {
                        match = false;
                        break;
                    }
                    
                    if((board[i][j] != board[nx][ny]) || board[i][j] == 'X')
                    {
                        match = false;
                        break;
                    }
                }
                
                if(match)
                {
                    finish = false;
                    coordinates.insert({i, j});
                    
                    for(int k=0; k<3; k++)
                    {
                        coordinates.insert({i + dx[k], j + dy[k]});
                    }
                }
                
            }
        }
        
        if(finish)
        {
            break;
        }
        
        for(const auto& elem : coordinates)
        {
            board[elem.first][elem.second] = 'X';
            answer++;
        }
        
        for(int j=0; j<n; j++)
        {
            for(int i=m-2; i>=0; i--)
            {
                if(board[i][j] != 'X')
                {
                    int k = i;
                    
                    while(k < m-1 && board[k+1][j] == 'X')
                    {
                        swap(board[k+1][j], board[k][j]);
                        k++;
                    }
                }
            }
        }
        
        
    }
    
    return answer;
}
