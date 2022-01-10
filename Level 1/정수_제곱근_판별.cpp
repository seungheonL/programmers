#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    if((long)sqrt(n) * (long)sqrt(n) == n)
    {
        answer += sqrt(n) + 1;
        return pow(answer, 2);
    }
    
    return -1;
}
