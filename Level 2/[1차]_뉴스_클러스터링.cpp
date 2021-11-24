#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

bool valid(const string& s)
{
    return (65 <= s[0] && s[0] <= 90 || 97 <= s[0] && s[0] <= 122) &&
           (65 <= s[1] && s[1] <= 90 || 97 <= s[1] && s[1] <= 122);
}

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> m1, m2;
    set<string> s1, s2;
    
    for(int i=0; i<str1.size(); i++)
    {
        string sub = str1.substr(i, 2);
        
        if(valid(sub))
        {
            for(int j=0; j<=1; j++)
            {
                if(65 <= sub[j] && sub[j] <= 90)
                {
                    sub[j] += 32;
                }
            }
            
            m1[sub]++;
            s1.insert(sub);
        }
    }
    
    for(int i=0; i<str2.size(); i++)
    {
        string sub = str2.substr(i, 2);
        
        if(valid(sub))
        {
            for(int j=0; j<=1; j++)
            {
                if(65 <= sub[j] && sub[j] <= 90)
                {
                    sub[j] += 32;
                }
            }
            
            m2[sub]++;
            s2.insert(sub);
        }
    }
    
    double up = 0; 
    double down = 0;
    
    for(const auto& elem : s1)
    {
        auto itr = m2.find(elem);
        
        if(itr != m2.end())
        {
            up += min(m1[elem], itr->second);
        }
    }
    
    for(const auto& elem : s1)
    {
        auto itr = m2.find(elem);
        
        if(itr != m2.end())
        {
            down += max(m1[elem], itr->second);
            s2.erase(s2.find(elem));
        }   
        else
        {
            down += m1[elem];
        }
    }
    
    for(const auto& elem : s2)
    {
        down += m2[elem];
    }
    
    if(up == 0 && down == 0)
    {
        return 65536;
    }
    
    return (int)((up / down) * 65536);
}
