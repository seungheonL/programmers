#include <string>
#include <vector>
#include <stack>
using namespace std;

bool correct(const string& str)
{
    stack<char> s;
    
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(')
        {
            s.push('(');
        }
        else if(str[i] == ')')
        {
            if(s.empty())
            {
                return false;
            }
            else if(s.top() == '(')
            {
                s.pop();
            }
        }
    }
    
    return s.empty();
}

string solution(string p) {
    if(p.empty())
    {
        return "";
    }
    
    int left = 0, right = 0;
    
    string u, v;
    
    for(int i=0; i<p.size(); i++)
    {
        if(p[i] == '(')
        {
            left++;
        }
        else if(p[i] == ')')
        {
            right++;
        }
        
        if(left == right && left != 0 && right != 0)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            
            break;
        }
    }
    
    if(correct(u))
    {
        return u + solution(v);
    }
    
    string answer = "";
    
    answer += '(';
    answer += solution(v);
    answer += ')';
    
    u.erase(u.begin());
    u.pop_back();
    
    for(int i=0; i<u.size(); i++)
    {
        if(u[i] == '(')
        {
            u[i] = ')';
        }
        else if(u[i] == ')')
        {
            u[i] = '(';
        }
    }
    
    answer += u; 
}
