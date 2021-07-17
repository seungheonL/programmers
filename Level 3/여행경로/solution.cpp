#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<string> answer;

bool dfs(const vector<vector<string>>& tickets, const string& start, int cnt)
{
    answer.push_back(start);
    
    if(cnt == tickets.size())
    {
        return true;
    }
   
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i][0] == start && !visited[i])
        {
            visited[i] = true;   
            
            if(dfs(tickets, tickets[i][1], cnt + 1))
            {
                return true;
            }
            
            visited[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    visited = vector<bool>(tickets.size(), false);
    
    dfs(tickets, "ICN", 0);
    
    return answer;
}
