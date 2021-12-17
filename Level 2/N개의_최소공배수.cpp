#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int n = *max_element(arr.begin(), arr.end());
    
    while(true)
    {
        bool found = true;
        for(int i=0; i<arr.size(); i++)
        {
            if(n % arr[i] != 0)
            {
                found = false;
                break;
            }
        }
        
        if(found)
        {
            return n;
        }
        
        n++;
    }
}
