#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 1;
    
    long long n = num;
    
    if(n == 1)
    {
        return 0;
    }
    
    while(true)
    {        
        if(n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = (n * 3) + 1;
        }
        
        if(answer > 500)
        {
            return -1;
        }
        
        else if(n == 1)
        {
            return answer;
        }
        
        answer++;
    }
}
