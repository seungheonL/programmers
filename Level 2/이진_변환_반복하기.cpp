#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(true)
    {
        if(s == "1")
        {
            break;
        }
        
        int cnt = 0;
        
        for(auto itr = s.begin(); itr != s.end(); itr++)
        {
            if(*itr == '0')
            {
                s.erase(itr);
                itr--;
                cnt++;
            }
        }
        
        int num = s.size();
        string temp;
        
        while(true)
        {
            if(num == 1)
            {
                temp += '1';
                break;
            }
            else
            {
                temp += to_string(num % 2);
                num /= 2;
            }
        }
        
        reverse(temp.begin(), temp.end());
        s = temp;
        
        answer[0]++;
        answer[1] += cnt;
    }
    
    return answer;
}
