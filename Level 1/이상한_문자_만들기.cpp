#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int i = 0;
    while(i < s.size())
    {
        if(isalpha(s[i]))
        {
            bool upper = true;
            for(; s[i] != ' ' && i<s.size(); i++)
            {
                if(upper)
                {
                    s[i] = toupper(s[i]);
                }
                else
                {
                    s[i] = tolower(s[i]);
                }
                upper = !upper;
            }
        }
        i++;
    }
        
    return s;
}
