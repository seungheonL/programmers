#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;

bool correct(const deque<char>& s)
{
    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if(st.empty()) 
        {
            return false;
        }
        else if(s[i] == ')')
        {
            if(st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if(s[i] == ']')
        {
            if(st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if(s[i] == '}')
        {
            if(st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    deque<char> dq;
    
    for(int i=0; i<s.size(); i++)
    {
        dq.push_back(s[i]);
    }
    
    for(int x=0; x<s.size(); x++)
    {
        dq.push_back(dq.front());
        dq.pop_front();
        
        if(correct(dq))
        {
            answer++;
        }
    }
    
    return answer;
}
