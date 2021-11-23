#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    deque<int> p;
    
    for(int i=0; i<people.size(); i++)
    {
        p.push_back(people[i]);
    }
    
    while(!p.empty())
    {
        int sum = p.back();
        p.pop_back();
        
        while(!p.empty())
        {
            sum += p.front();
            
            if(sum < limit)
            {
                 p.pop_front();
            }
            else if(sum > limit)
            {
                break;
            }
            else
            {
                p.pop_front();
                break;
            }
        }
        
        answer++;   
    }  
    
    return answer;
}
