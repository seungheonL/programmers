#include <string>
#include <vector>

using namespace std;

string solution(string s) {   
    string result;
    
    if(s.size() % 2 == 0)
    {   
        result += s[s.size() / 2 - 1];
        result += s[s.size() / 2];
        return result;
    }
    else
    {
        result += s[s.size() / 2];
        return result;
    }
}
