#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end());
    
    for(int i=citations.back(); i>=0; i--)
    {
        bool success = true;
        int a = citations.size()-1;
        int b = citations.size()-i;
        
        for(a; a >= b; a--)
        {
            if(citations[a] < i) //0 1 3 5 6
            {
                success = false;
                break;
            }
        }
        if(success)
        {
            return i;
        }
    }
}
