#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int num = x;
    while(n--)
    {
        answer.push_back(num);
        num += x;
    }
    
    return answer;
}
