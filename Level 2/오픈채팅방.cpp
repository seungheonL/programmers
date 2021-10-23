#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map<string, string> m;
    
    vector<pair<pair<string, string>, bool>> v;
    for(int i=0; i<record.size(); i++)
    {
        string id = record[i].substr(6, record[i].find(" ", 6) - 6);
        string nickname = record[i].substr(record[i].find(" ", 6) + 1);
        
        if(record[i].substr(0, 5) == "Enter")
        {
            m[id] = nickname;
            
            v.push_back({{id, nickname}, true});
        }
        
        else if(record[i].substr(0, 5) == "Leave")
        {
            id = record[i].substr(6);
            
            for(auto& elem : v)
            {
                if(elem.first.first == id)
                {
                    v.push_back({{id, elem.first.second}, false});
                    break;
                }
            }     
        }
        
        else //change
        {
            id = record[i].substr(7, record[i].find(" ", 7) - 7);
            nickname = record[i].substr(record[i].find(" ", 7) + 1);
            
            m[id] = nickname;
        }
    }
    
    for(auto& elem : v)
    {
        if(elem.second == true)
        {
            answer.push_back(m[elem.first.first] + "님이 들어왔습니다.");
        }
        else
        {
            answer.push_back(m[elem.first.first] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}
