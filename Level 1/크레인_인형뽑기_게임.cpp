#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> s;
    
    for(int i=0; i<moves.size(); i++)
    {
        int index = moves[i] - 1;
        
        for(int j=0; j<board[index].size(); j++)
        {
            if(board[j][index] != 0)
            {
                if(!s.empty())
                {
                    if(s.top() == board[j][index])
                    {
                        answer += 2;
                        s.pop();
                        board[j][index] = 0;
                    }
                    else
                    {
                        s.push(board[j][index]);
                        board[j][index] = 0;
                    }
                }
                else
                {
                    s.push(board[j][index]);
                    board[j][index] = 0;
                }
                
                break;
            }
        }
    }
    
    return answer;
}
