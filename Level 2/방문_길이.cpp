#include <string>
#include <vector>
#include <set>
using namespace std;

bool valid(int x, int y)
{
    return 0 <= x && x <= 10 && 0 <= y && y <= 10;
}

int solution(string dirs) {
    int answer = 0;
    
    int x = 5;
    int y = 5;
    
    set<pair<pair<int, int>, pair<int, int>>> s;
    
    for(int i=0; i<dirs.size(); i++)
    {
        switch(dirs[i])
        {
            case 'U':
                if(valid(x-1, y))
                {
                    x--;
                    
                    if(s.find({{x, y}, {x+1, y}}) == s.end())
                    {
                        s.insert({{x, y}, {x+1, y}});
                        s.insert({{x+1, y}, {x, y}});
                        answer++;
                    }   
                }               
                break;
                
            case 'D':
                if(valid(x+1, y))
                {
                    x++;
                    
                    if(s.find({{x, y}, {x-1, y}}) == s.end())
                    {
                        s.insert({{x, y}, {x-1, y}});
                        s.insert({{x-1, y}, {x, y}});
                        answer++;
                    }   
                }               
                break;
                
            case 'R':
                if(valid(x, y+1))
                {
                    y++;
                    
                    if(s.find({{x, y}, {x, y-1}}) == s.end())
                    {
                        s.insert({{x, y}, {x, y-1}});
                        s.insert({{x, y-1}, {x, y}});
                        answer++;
                    }   
                }               
                break;
                
            case 'L':
                if(valid(x, y-1))
                {
                    y--;
                    
                    if(s.find({{x, y}, {x, y+1}}) == s.end())
                    {
                        s.insert({{x, y}, {x, y+1}});
                        s.insert({{x, y+1}, {x, y}});
                        answer++;
                    }   
                }               
                break;
        }
    }
    
    return answer;
}
