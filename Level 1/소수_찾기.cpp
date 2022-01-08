#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<bool> isPrime(n+1, true);
    
    isPrime[1] = false;
    
    for(int i=2; i<=sqrt(n); i++)
    {
        if(isPrime[i] == true)
        {
            for(int j=i+i; j<=n; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if(isPrime[i])
        {
            answer++;
        }
    }
    
    return answer;
}
