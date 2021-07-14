#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr;
int a;
int b;

vector<vector<int>> cache;

bool valid(int x, int y)
{
    return 0 <= x && x < a && 0 <= y && y < b;
}

int count(int x, int y)
{
    if(cache[x][y] != -1)
    {
        return cache[x][y];
    }
    if(x == a-1 && y == b-1)
    {
        return cache[x][y] = 1;
    }
    
    int result = 0;
    
    if(valid(x, y+1) && arr[x][y+1])
    {
        result += count(x, y+1) % 1000000007;
    }
    
    if(valid(x+1, y) && arr[x+1][y])
    {
        result += count(x+1, y) % 1000000007;
    }
    
    return cache[x][y] = result % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    arr = vector<vector<int>>(n, vector<int>(m, 1));
    a = n;
    b = m;
    
    cache = vector<vector<int>>(n, vector<int>(m, -1));
    
    for(int i=0; i<puddles.size(); i++)
    {
        arr[puddles[i][1]-1][puddles[i][0]-1] = 0;
    }
    
    return count(0, 0);
}
