#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> dq;
    int currentSize = 0;
    
    for(int i=0; i<cities.size(); i++)
    {
        for(int j=0; j<cities[i].size(); j++)
        {
            if(cities[i][j] >= 65 && cities[i][j] <= 90)
            {
                cities[i][j] += 32;
            }
        }
        
        bool found = false;
        
        if(cacheSize == 0)
        {
            answer += 5 * cities.size();
            return answer;
        }
        
        if(dq.empty())
        {
            dq.push_back(cities[i]);
            answer += 5;
            currentSize++;
        }
        
        else
        {
            for(auto itr = dq.begin(); itr != dq.end(); itr++)
            {
                if(*itr == cities[i])
                {
                    dq.erase(itr);
                    found = true;
                    answer++;

                    break;
                }
            }

            if(!found)
            {
                if(currentSize >= cacheSize)
                {
                    dq.pop_front();
                }

                answer += 5;
                currentSize++;
            }  

            dq.push_back(cities[i]);
        }
    }
    
    return answer;
}
