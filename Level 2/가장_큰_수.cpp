#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& lhs, const string& rhs)
{
    return lhs + rhs < rhs + lhs;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    for(int i=0; i<numbers.size(); i++)
    {
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), compare);
    
    if(v.back() == "0")
    {
        return "0";
    }
    
    for(int i=v.size()-1; i>=0; i--)
    {
        answer += v[i];
    }
    
    return answer;
}
