#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int a[] = {1, 2, 4};
const int b[] = {0, 1, 2, 4};

string solution(int n) {
    string answer = "";
    
    vector<int> v;
    
    n--;
    int cnt = 0;
    
    while(n > 3)
    {
        if(cnt == 0)
        {
            v.push_back(n % 3);
            n /= 3;
        }
        else
        {
            if(n % 3 == 0)
            {
                v.push_back(3);
                n /= 3;
                n--;
            }
            else
            {
                v.push_back(n % 3);
                n /= 3;
            }
        }
        
        cnt++;
    }
    
    v.push_back(n);
    
    reverse(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++)
    {
        if(i == v.size()-1)
        {
            answer += to_string(a[v[i]]);
        }
        else
        {
            answer += to_string(b[v[i]]);
        }
    }
    
    return answer;
}
