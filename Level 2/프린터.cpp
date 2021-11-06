#include <string>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque<pair<int, int>> dq;
    
    for(int i=0; i<priorities.size(); i++)
    {
        dq.push_back({priorities[i], i});
    }
    
    int time = 1;
    
    while(!dq.empty())
    {
        if(dq.size() == 1)
        {
            return time;
        }
        
        bool found = false;
                
        for(int i=1; i<dq.size(); i++)
        {
            if(dq[i].first > dq.front().first)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                found = true;
                break;
            }
        }
        
        if(!found)
        {
            if(dq.front().second == location)
            {
                return time;
            }
            
            dq.pop_front();
            time++;
        }
    }
    
    return time;
}
