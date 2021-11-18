#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int startIndex = -1;
    
    k = number.size() - k;
    
    while(k--)
    {
        char largest = 0;
        
        for(int i=startIndex+1; i<number.size()-k; i++)
        {
            if(largest < number[i])
            {
                largest = number[i];
                startIndex = i;
            }
        }
        
        answer += largest;
    }
    
   return answer;
}
