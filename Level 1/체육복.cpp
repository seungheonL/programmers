#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> count(n + 1, 1);
    
    for(int i=0; i<lost.size(); i++)
    {
        count[lost[i]]--;
    }
    
    for(int i=0; i<reserve.size(); i++)
    {
        count[reserve[i]]++;
    }
    
    for(int i=1; i<=n; i++)
    {
        if(i == 1 && count[i] == 2 && count[i+1] == 0)
        {
            count[i+1]++;
            count[i]--;
        }
        else if(i == n && count[i] == 2 && count[i-1] == 0)
        {
            count[i-1]++;
            count[i]--;
        }
        else
        {
            if(count[i] == 2 && count[i-1] == 0)
            {
                count[i-1]++;
                count[i]--;
            }
            else if(count[i] == 2 && count[i+1] == 0)
            {
                count[i+1]++;
                count[i]--;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if(count[i] >= 1)
        {
            answer++;
        }
    }
    
    return answer;
}
