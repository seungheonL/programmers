#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<int> cnt(n + 1, 0);
    set<string> s;
    char last;
    
    for(int i=0; i<words.size(); i++)
    {   
        cnt[(i % n) + 1]++;
        
        if(i == 0)
        {
            last = words[i][words[i].size()-1];
            s.insert(words[i]);          
        }
        else
        { 
            if(words[i][0] != last || s.find(words[i]) != s.end() || words[i].size() <= 1)
            {
                answer.push_back((i % n) + 1);
                answer.push_back(cnt[(i % n) + 1]);
                
                return answer;
            }
            else
            {
                last = words[i][words[i].size()-1];
                s.insert(words[i]);
            }
        }        
        
    }
    
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}
