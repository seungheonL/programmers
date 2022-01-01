#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<pair<int, int>> coordinates;
    pair<int, int> left = {3, 0}, right = {3, 2};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            coordinates.push_back({i, j});
        }
    }
    
    for(int number : numbers)
    {
        if(number == 2 || number == 5 || number == 8)
        {
            int x = coordinates[number-1].first;
            int y = coordinates[number-1].second;
            int dist_left = abs(left.first-x) + abs(left.second-y);
            int dist_right = abs(right.first-x) + abs(right.second-y);
            
            if(dist_left < dist_right)
            {
                answer += 'L';
                left = {x, y};
            }
            else if(dist_right < dist_left)
            {
                answer += 'R';
                right = {x, y};
            }
            else
            {
                if(hand == "left")
                {
                    answer += 'L';
                    left = {x, y};
                }
                else
                {
                    answer += 'R';
                    right = {x, y};
                }
            }
        }
        else if(number == 0)
        {
            int dist_left = abs(left.first-3) + abs(left.second-1);
            int dist_right = abs(right.first-3) + abs(right.second-1);
            
            if(dist_left < dist_right)
            {
                answer += 'L';
                left = {3, 1};
            }
            else if(dist_right < dist_left)
            {
                answer += 'R';
                right = {3, 1};
            }
            else
            {
                if(hand == "left")
                {
                    answer += 'L';
                    left = {3, 1};
                }
                else
                {
                    answer += 'R';
                    right = {3, 1};
                }
            }
        }
        else if(number == 1 || number == 4 || number == 7)
        {
            answer += 'L';
            left = {coordinates[number-1].first, coordinates[number-1].second};
        }
        else
        {
            answer += 'R';
            right = {coordinates[number-1].first, coordinates[number-1].second};
        }
    }
    
    return answer;
}
