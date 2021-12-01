#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> transform(int num, int n)
{
    vector<string> result;
    
    while(num >= n)
    {
        int val = num % n;
        
        if(val >= 10)
        {
            string temp = "";
            temp += 'A' + (val - 10);
            result.push_back(temp);
        }
        else
        {
            result.push_back(to_string(val));
        }
        
        num = num / n;
    }
        
    if(num >= 10)
    {
        string temp = "";
        temp += 'A' + (num - 10);
        result.push_back(temp);
    }
    else
    {
        result.push_back(to_string(num));
    }  
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    vector<string> sequence;
    
    int num = 0;
    
    while(sequence.size() <= (t + 1) * (m + 1))
    {
        vector<string> result = transform(num, n);
        
        for(int i=0; i<result.size(); i++)
        {
            sequence.push_back(result[i]);
        }
        
        num++;
    }
    
    p--;
    
    for(int i=0; i<t; i++)
    {
        string temp = "";
        temp += sequence[p];
        answer += temp;
        p += m;
    }
    
    return answer;
}
