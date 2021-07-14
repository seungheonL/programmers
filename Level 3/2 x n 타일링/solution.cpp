#include <string>
#include <vector>

using namespace std;

vector<int> cache;

int count(int n)
{
    if(cache[n] != -1)
    {
        return cache[n];
    }
    
    if(n == 2)
    {
        return cache[n] = 2;
    }
    
    if(n == 1)
    {
        return cache[n] = 1;
    }
    
    return cache[n] = (count(n-1) % 1000000007 + count(n-2) % 1000000007) % 1000000007;
}

int solution(int n) {
    cache = vector<int>(n+1, -1);
    return count(n);
}
