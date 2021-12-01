#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> m;
    
    int index = 1;
    
    for(char c = 'A'; c <= 'Z'; c++)
    {
        string str;
        str += c;
        m[str] = index;
        index++;
    }

    int start = 0;
    
    while(start < msg.size())
    {
        int length;
        for(length = 1; start + length <= msg.size() + 1; length++)
        {
            string s = msg.substr(start, length);
            
            if(m.find(msg.substr(start, length)) == m.end())
            {
                answer.push_back(m[msg.substr(start, length - 1)]);
                
                m[msg.substr(start, length)] = index;
                index++;
                start += length - 1;
                break;
            }
        }
        
        if(start + length == msg.size() + 2)
        {
            answer.push_back(m[msg.substr(start, length - 1)]);
            break;
        }
    }
    
    return answer;
}
