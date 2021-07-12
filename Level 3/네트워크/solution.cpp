#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;    
    
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            stack<int> s;
            s.push(i);
            visited[i] = true;
            
            while(!s.empty())
            {
                int current = s.top();
                s.pop();
                
                for(int j=0; j<n; j++)
                {
                    if(computers[current][j] && !visited[j])
                    {
                        s.push(j);
                        visited[j] = true;
                    }
                }
            }
            
            answer++;
        }
    }
    
    return answer;
}
