#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char> stk;
    
    for(auto& c : s)
    {
        if(!stk.empty())
        {
            if(stk.top() == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        else
        {
            stk.push(c);
        }
    }

    return answer = stk.empty();
}
