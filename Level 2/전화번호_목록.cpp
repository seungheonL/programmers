#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

bool solution(vector<string> phone_book) {    
    map<string, pair<int, int>> m;
    
    for(int i=0; i<phone_book.size(); i++)
    {
        for(int j=1; j<=phone_book[i].size(); j++)
        {
            auto itr = m.find(phone_book[i].substr(0, j));
            
            if(itr == m.end())
            {
                m[phone_book[i].substr(0, j)] = {i, 1};
            }
            else
            {
                itr->second.second++;
            }
        }
    }
    
    for(int i=0; i<phone_book.size(); i++)
    {
        auto itr = m.find(phone_book[i]);
        
        if(itr->second.second >= 2 || (itr->second.first != i))
        {
            return false;
        }
    }
    
    return true;
}
