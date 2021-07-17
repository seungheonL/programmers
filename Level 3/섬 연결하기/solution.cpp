#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int from;
    int to;
    int weight;
    
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
    
    bool operator<(const Edge& rhs)
    {
        return weight < rhs.weight;
    }
};

vector<int> parents;

int find(int a)
{
    if(parents[a] == a)
    {
        return a;
    }
    return parents[a] = find(parents[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a < b)
    {
        parents[a] = b;
    }
    else
    {
        parents[b] = a;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int totalCost = 0;
    
    parents = vector<int>(n);
    
    for(int i=0; i<parents.size(); i++)
    {
        parents[i] = i;
    }
    
    vector<Edge> edges;
    
    for(int i=0; i<costs.size(); i++)
    {
        edges.push_back(Edge(costs[i][0], costs[i][1], costs[i][2]));
    }
    
    sort(edges.begin(), edges.end());
    
    for(int i=0; i<edges.size(); i++)
    {
        int a = edges[i].from;
        int b = edges[i].to;
        int cost = edges[i].weight;
        
        if(find(a) != find(b))
        {
            merge(a, b);
            totalCost += cost;
        }
    }
    
    return totalCost;
}
