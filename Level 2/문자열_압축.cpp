#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 987654321;
    
    if(s.size() == 1){
        return 1;
    }
    
    for(int length = 1; length <= s.size() / 2; length++)
    {
        int result = 0;
        
        for(int i=0; i<s.size();)
        {
            string temp = s.substr(i, length);
            
            int cnt = 0;
            
            bool flag = false;
            
            while(true)
            {
                if(s.size() - i < length)
                {
                   result += s.size() - i;
                   flag = true;
                }
                
                if(s.substr(i, length) == temp)
                {
                    cnt++;                    
                    i += length;                
                }
                else
                {
                    break;
                }
                
                if(i >= s.size()) break;
            }    
            
            if(cnt == 1)
            {
                result += length;
            }
            else
            {
                result += to_string(cnt).size() + length;
            }
            
            if(flag) break;
        }
        
        answer = min(answer, result);
    }
    
    return answer;
}
