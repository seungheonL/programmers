#include <string>
#include <vector>

using namespace std;

int countOne(int n)
{
    int result = 0;
    
    while(n >= 2)
    {
        if(n % 2 == 1)
        {
            result++;
        }
        
        n /= 2;
    }
    
    if(n == 1)
    {
        result++;
    }
    
    return result;
}

int solution(int n) {
    int answer = n+1;
    
    while(true)
    {
        if(countOne(n) == countOne(answer))
        {
            return answer;
        }
        answer++;
    }
}
