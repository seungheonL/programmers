#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int round = 1;
    
    if(a > b)
    {
        swap(a, b);
    }
    
    while(true)
    {
        if(a + 1 == b && a % 2 == 1 && b % 2 == 0)
        {
            return round;
        }
        
        if(a % 2 == 0)
        {
            a /= 2;
        }
        else
        {
            a = a / 2 + 1;
        }
        
        if(b % 2 == 0)
        {
            b /= 2;
        }
        else
        {
            b = b / 2 + 1;
        }
        
        round++;
    }
}
