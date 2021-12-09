#include <string>
#include <vector>

using namespace std;

vector<unsigned long long> cache;

unsigned long long F(unsigned long long n)
{
    if(n == 0)
    {
        return 0;
    }
    
    if(n == 1)
    {
        return 1;
    }
    
    if(cache[n] != -1)
    {
        return cache[n];
    }
    
    return cache[n] = (F(n-1) % 1234567 + F(n-2) % 1234567) % 1234567;
}

int solution(int n) {
    cache = vector<unsigned long long>(100001, -1);
    
    return F(n);
}
