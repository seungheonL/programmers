#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    map<int, int> m;
    vector<pair<double, int>> v;
    
    for(int i=0; i<stages.size(); i++)
    {
        if(stages[i] != N+1)
        {
            m[stages[i]]++;  
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        if(m.find(i) == m.end())
        {
            m[i] = 0;
        }
    }
    
    double n = stages.size();
    int stage = 1;
    
    for(auto& elem : m)
    {
        if(n != 0)
        {
            v.push_back({-(double)elem.second / n, stage});
            n -= elem.second;        
        }      
        else
        {
            v.push_back({0, stage});
        }  
        stage++;
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++)
    {
        answer.push_back(v[i].second);
    }
    
    return answer;
}
