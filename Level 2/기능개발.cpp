#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    deque<int> prog;
    deque<int> sp;
    
    for(int i=0; i<progresses.size(); i++)
    {
        prog.push_back(progresses[i]);
        sp.push_back(speeds[i]);
    }
    
    while(!prog.empty())
    {
        int cnt = 1;
        int diff = 100 - prog.front();
        int days = diff % sp.front() == 0 ? diff / sp.front() : (diff / sp.front()) + 1;
        
        prog.pop_front();
        sp.pop_front();
        
        for(int i=0; i<prog.size(); i++)
        {
            prog[i] += days * sp[i];
        }
        
        while(!prog.empty())
        {
            if(prog.front() >= 100)
            {
                prog.pop_front();
                sp.pop_front();
                
                cnt++;
            }
            else
            {
                break;
            }
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}
