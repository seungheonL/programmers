#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    string result = "";
    
    vector<string> dict = {"zero", "one", "two", "three", "four", "five",
                           "six", "seven", "eight", "nine"};
    
    while(!s.empty()) 
    {
		if(isdigit(s[0]))
		{
			result += to_string(s[0] - '0');
			s.erase(s.begin());
			continue;
		}
        for(int i=0; i<dict.size(); i++) 
        {
            string word = dict[i];
            
            bool match = true;
            
            for(int j=0; j<word.size(); j++)
            {
                if(j >= s.size() || s[j] != word[j])
                {
                    match = false;
                    break;
                }
            }
            
            if(match)
            {
                result += to_string(find(dict.begin(), dict.end(), word) - dict.begin());
                s.erase(s.begin(), s.begin() + word.size());
				
                break;
            }       
        }
    }
    
    return stoi(result);
}
