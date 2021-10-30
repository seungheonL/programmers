#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int> numbers, int index, int target, int sum, int& answer)
{
    if(index == numbers.size() - 1)
    {
        if(sum + numbers[index] == target || sum - numbers[index] == target)
        {
            answer++;
        }
        
        return;
    }
    
    dfs(numbers, index + 1, target, sum + numbers[index], answer);
    dfs(numbers, index + 1, target, sum - numbers[index], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, 0, target, 0, answer);
    
    return answer;
}
