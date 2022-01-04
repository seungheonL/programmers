#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> result;
    
    while(true)
    {
        if(n >= 3)
        {
            result.push_back(n % 3);
            n = n / 3;
        }
        else
        {
            result.push_back(n);
            break;
        }
    }
    
    int count = 0;
    for(auto itr = result.rbegin(); itr != result.rend(); itr++)
    {
        answer += *itr * pow(3, count);
        count++;
    }
    
    return answer;
}
