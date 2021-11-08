#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int answer = 0;
string s;
map<char, int> m;
set<string> used;

bool isPrime(int num)
{
    if(num == 1)
    {
        return false;
    }
    
    if(num == 2)
    {
        return true;
    }
    
    for(int i=2; i<=num/2; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void brute_force(const string& numbers, int cnt)
{
    for(int i=0; i<numbers.size(); i++)
    {
        if(cnt == 0 && numbers[i] == '0')
        {
            continue;
        }
        
        bool found = false;
        
        if(m.find(numbers[i]) != m.end() && m[numbers[i]] == 0)
        {
            found = true;
        }
        
        if(!found)
        {
            s += numbers[i];
            
            if(used.find(s) != used.end())
            {
                s.pop_back();
                continue;
            }
            
            m[numbers[i]]--;
            used.insert(s);
            
            if(isPrime(stoi(s)))
            {
                answer++;
            }
            
            brute_force(numbers, cnt + 1);
            s.pop_back();
            m[numbers[i]]++;
        }
    }
}

int solution(string numbers) {
    
    for(int i=0; i<numbers.size(); i++)
    {
        m[numbers[i]]++;
    }
    
    brute_force(numbers, 0);
    
    return answer;
}
