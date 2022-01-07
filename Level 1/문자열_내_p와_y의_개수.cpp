#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{    
    int cntP = 0, cntY = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        s[i] = tolower(s[i]);
        
        if(s[i] == 'p')
        {
            cntP++;
        }
        else if(s[i] == 'y')
        {
            cntY++;
        }
    }
    
    return cntP == cntY;
}
