#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for(int i=2; i<=n/2; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i=0; i<nums.size()-2; i++)
    {
        for(int j=i+2; j<nums.size(); j++)
        {
            for(int k=i+1; k<=j-1; k++)
            {
                if(isPrime(nums[i]+nums[k]+nums[j]))
                {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}
