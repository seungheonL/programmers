#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    map<string, int> m;
    queue<string> q;
    
    m[begin] = 0;
    q.push(begin);
    
    while(!q.empty())
    {
        string s = q.front();
        q.pop();
        
        for(int i = 0; i < words.size(); i++)
        {
            if(m.find(words[i]) == m.end())
            {
                int cnt = 0;

                for(int j = 0; j < words[i].size(); j++)
                {
                    if(s[j] != words[i][j])
                    {
                        cnt++;
                    }
                }

                if(cnt == 1)
                {
                    q.push(words[i]);
                    m[words[i]] = m[s] + 1;
                    
                    if(words[i] == target)   
                    {
                        return m[words[i]];
                    }
                }
            }
            
        }
    }
    
    return 0;
}
