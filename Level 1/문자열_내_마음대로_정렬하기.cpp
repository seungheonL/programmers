#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    vector<pair<char, string>> p;
    
    for(int i=0; i<strings.size(); i++)
    {
        p.push_back({strings[i][n], strings[i]});
    }
    
    sort(p.begin(), p.end());
    
    for(const auto& elem : p)
    {
        answer.push_back(elem.second);
    }
    
    return answer;
}
