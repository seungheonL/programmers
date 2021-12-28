#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int cnt_zero = 0;
    int match = 0;
    
    for(int i=0; i<6; i++)
    {
        if(lottos[i] == 0)
        {
            cnt_zero++;
        }
        else if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            match++;
        }
    }
    
    int best = match + cnt_zero;
    int worst = match;
    
    if(best <= 1)
    {
        answer.push_back(6);
    }
    else
    {
        answer.push_back(7-best);
    }
    if(worst <= 1)
    {
        answer.push_back(6);
    }
    else
    {
        answer.push_back(7-worst);
    }
    
    return answer;
}
