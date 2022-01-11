#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string s = to_string(x);
    int sum = 0;
    for(int i=0; i<s.size(); i++)
    {
        sum += stoi(s.substr(i, 1));
    }
    
    return x % sum == 0;
}
