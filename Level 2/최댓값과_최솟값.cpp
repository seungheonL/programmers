#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    
    for(int i=0; i<s.size();)
    {
        int last = s.find(" ", i);
        
        if(last == string::npos)
        {
            v.push_back(stoi(s.substr(i)));
            break;
        }
        
        else
        {
            v.push_back(stoi(s.substr(i, last - i)));
            i = last + 1;
        }
        
    }
    
    answer += to_string(*min_element(v.begin(), v.end()));
    answer += " ";
    answer += to_string(*max_element(v.begin(), v.end()));                
    
    return answer;
}
