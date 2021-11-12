#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(N+1);
    
    for(int i=0; i<road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        
        bool found = false;        
        for(const auto& elem : graph[a])
        {
            if(elem.first == b)
            {
                if(elem.second < c)
                {
                    found = true;
                    break;
                }
            }
        }
        
        if(!found)
        {
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
    }
    
    vector<int> dist(N+1, INF);
    priority_queue<pair<int, int>> pq;
    dist[1] = 0;
    pq.push({-dist[1], 1});
    
    while(!pq.empty())
    {
        int current = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(dist[current] < cost)
        {
            continue;
        }
        
        for(const auto& elem : graph[current])
        {
            int next = elem.first;
            int weight = elem.second;
            
            if(dist[current] + weight < dist[next])
            {
                dist[next] = dist[current] + weight;
                pq.push({-dist[next], next});
            }
        }
    }
    
    for(int i=1; i<=N; i++)
    {
        if(dist[i] <= K)
        {
            answer++;
        }
    }
    
    
    return answer;
}
