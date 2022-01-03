#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> p1 = {1,2,3,4,5};
    vector<int> p2 = {2,1,2,3,2,4,2,5};
    vector<int> p3 = {3,3,1,1,2,2,4,4,5,5};
    
    deque<pair<int, int>> v = {{0, 1}, {0, 2}, {0, 3}};
    
    for(int i=0; i<answers.size(); i++)
    {
        if(p1[i % 5] == answers[i])
        {
            v[0].first--;
        }
        if(p2[i % 8] == answers[i])
        {
            v[1].first--;
        }
        if(p3[i % 10] == answers[i])
        {
            v[2].first--;
        }
    }
    
    sort(v.begin(), v.end());
    
    while(true)
    {
        answer.push_back(v.front().second);
        
        if(!v.empty() && v.front().first == v[1].first)
        {
            v.pop_front();
        }
        else
        {
            break;
        }
    }
    
    return answer;
}
