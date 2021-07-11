#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> cache;

int getMax(int row, int col)
{
    if(cache[row][col] != -1)
    {
        return cache[row][col];
    }
    
    if(row == arr.size()-1)
    {
        return cache[row][col] = arr[row][col];
    }    
    
    return cache[row][col] = arr[row][col] + max(getMax(row+1, col), getMax(row+1, col+1));
}

int solution(vector<vector<int>> triangle) {    
    arr= triangle;
    cache = vector<vector<int>>(arr.size(), vector<int>(arr.size(), -1));
    
    return getMax(0, 0);
}
