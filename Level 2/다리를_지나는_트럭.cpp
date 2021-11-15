#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {    
    deque<pair<int, int>> bridge;
    queue<int> trucks;
    
    for(int i=0; i<truck_weights.size(); i++)
    {
        trucks.push(truck_weights[i]);
    }
    
    int time = 1;
    int current_weight = 0;
    
    bridge.push_back({trucks.front(), 1});
    current_weight += trucks.front();      
    trucks.pop();
    
    while(!bridge.empty())
    {
        if(bridge.front().second == bridge_length)
        {
            current_weight -= bridge.front().first;
            bridge.pop_front();
        }
        
        if(!trucks.empty())
        {
            if(weight - current_weight >= trucks.front())
            {
                bridge.push_back({trucks.front(), 0});
                current_weight += trucks.front();
                
                trucks.pop();
            }
        }
        
        for(int i=0; i<bridge.size(); i++)
        {
            bridge[i].second++;
        }
        
        time++;
    }
    
    return time;
}
