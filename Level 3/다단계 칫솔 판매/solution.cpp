#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    vector<int> profits(enroll.size());
    map<string, string> parents;
    map<string, int> getIndex;
    
    for(int i=0; i<enroll.size(); i++)
    {
        getIndex[enroll[i]] = i;
    }
    
    for(int i=0; i<referral.size(); i++)
    {
        parents[enroll[i]] = referral[i];
    }
    
    for(int i=0; i<seller.size(); i++)
    {
        profits[getIndex[seller[i]]] += amount[i] * 100 * 0.9;
        int remaining = amount[i] * 100 * 0.1;
        
        string child = seller[i];
        
        while(true)
        {
            string recommander = parents[child];
            
            if(recommander == "-")
            {  
                break;
            }
            
            if(remaining < 10)
            {
                profits[getIndex[recommander]] += remaining;
                break;        
            }
            else
            {
                profits[getIndex[recommander]] += remaining - remaining / 10;
            }
            
            remaining /= 10;
            
            child = recommander;
        }
    }
    
    for(int i=0; i<enroll.size(); i++)
    {
        answer.push_back(profits[i]);
    }    
    
    return answer;
}
