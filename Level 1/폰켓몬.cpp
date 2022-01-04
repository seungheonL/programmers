#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> s;
    
    for(auto& num : nums)
    {
        s.insert(num);
    }
    
    answer = min(s.size(), nums.size() / 2);
    
    return answer;
}
