#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    
    for(int i=0; i<scoville.size(); i++)
    {
        pq.push(-scoville[i]);
    }
    
    while(true)
    {
        answer++;
        
        int first = -pq.top();
        pq.pop();
        
        int second = -pq.top();
        pq.pop();
        
        pq.push(-(first + second * 2));
        
        if(-pq.top() >= K)
        {
            return answer;
        }
        
        else if(pq.size() == 1)
        {
            return -1;
        }
}
