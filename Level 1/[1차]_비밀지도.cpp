#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    
    vector<vector<int>> v1(n), v2(n);
    
    for(int i=0; i<arr1.size(); i++)
    {
        int num = arr1[i];
        while(true)
        {
            if(num >= 2)
            {
                v1[i].push_back(num % 2);
                num /= 2;
            }
            else
            {
                v1[i].push_back(num);
                break;
            }
        }
        
        if(v1[i].size() < n)
        {
            int diff = n - v1[i].size();
            
            while(diff--)
            {
                v1[i].push_back(0);
            }
        }
        
        num = arr2[i];
        while(true)
        {
            if(num >= 2)
            {
                v2[i].push_back(num % 2);
                num /= 2;
            }
            else
            {
                v2[i].push_back(num);
                break;
            }
        }
        
        if(v2[i].size() < n)
        {
            int diff = n - v2[i].size();
            
            while(diff--)
            {
                v2[i].push_back(0);
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        reverse(v1[i].begin(), v1[i].end());
        reverse(v2[i].begin(), v2[i].end());
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(v1[i][j] == 0 && v2[i][j] == 0)
            {
                answer[i] += " ";
            }
            else
            {
                answer[i] += "#";
            }
        }
    }
    
    return answer;
}
