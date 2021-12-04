#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> cache;

int getMax(int row, int prevCol)
{
    if(row == arr.size() - 1)
    {
        int result = -1;
        
        for(int i=0; i<4; i++)
        {
            if(i != prevCol)
            {
                result = max(result, arr[row][i]);
            }
        }
        
        return result;
    }
    
    if(cache[row][prevCol] != -1)
    {
        return cache[row][prevCol];
    }
    
    int result = -1;
    
    for(int i=0; i<4; i++)
    {
        if(i != prevCol)
        {
            result = max(result, arr[row][i] + getMax(row + 1, i));
        }
    }
    
    return cache[row][prevCol] = result;
}

int solution(vector<vector<int> > land)
{
    arr = land;
    cache = vector<vector<int>>(100001, vector<int>(4, -1));
    
    int result = -1;
    
    for(int i=0; i<4; i++)
    {
        result = max(result, arr[0][i] + getMax(1, i));
    }
    
    return result;
}
