#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{    
    stack<char> stk;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            stk.push('(');
        }
        else if(s[i] == ')')
        {
            if(!stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return stk.empty();
}
