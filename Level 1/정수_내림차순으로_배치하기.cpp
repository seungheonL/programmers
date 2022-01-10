#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    string answer;
    
    string s = to_string(n);
    
    for(int i=0; i<s.size(); i++)
    {
        answer += s[i]; 
    }
    
    sort(answer.rbegin(), answer.rend());
    
    return stol(answer);
}
