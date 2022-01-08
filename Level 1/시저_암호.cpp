#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0; i<s.size(); i++)
    {
        if(islower(s[i]))
        {
            if(s[i] + n > 'z')
            {
                s[i] = 'a' + s[i] + n - 'z' - 1;
            }
            else
            {
                s[i] += n;
            }
        }
        else if(isupper(s[i]))
        {
            if(s[i] + n > 'Z')
            {
                s[i] = 'A' + s[i] + n - 'Z' - 1;
            }
            else
            {
                s[i] += n;
            }
        }
    }
    
    return s;
}
