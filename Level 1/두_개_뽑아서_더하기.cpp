#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    set<int> s;
    
    for(int i=0; i<numbers.size()-1; i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            s.insert(numbers[i] + numbers[j]);
        }
    }
    
    for(auto& elem : s)
    {
        answer.push_back(elem);
    }
    
    return answer;
}
