#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> m;
    
    for(int i=0; i<skill.size(); i++)
    {
        m[skill[i]] = i+1;
    }
        
    for(int i=0; i<skill_trees.size(); i++)
    {
        int currentIndex = 1;
        bool success = true;
        
        for(int j=0; j<skill_trees[i].size(); j++)
        {
            char c = skill_trees[i][j];
            
            if(m[c] == currentIndex)
            {
                currentIndex++;
            }
            else if(m[c] != 0)
            {
                success = false;
                break;
            }
        }
        
        if(success)
        {
            answer++;
        }
    }
    
    return answer;
}
