// LeetCode
// 167. Two Sum II - Input Array Is Sorted
// Difficulty level: Medium
// Solution using 2 pointers, beats 100%

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int links = 0, rechts = numbers.size() - 1;
        while(links < rechts) {
            if(numbers[links] + numbers[rechts] < target) 
                links++;
            else if(numbers[links] + numbers[rechts] > target)
                rechts--;
            else
                break;
        }
        return {links + 1, rechts + 1};
    }
}solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> numbers1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> answer1 = solution.twoSum(numbers1, target1);
    cout << answer1[0] << ' ' << answer1[1] << '\n';

    vector<int> numbers2 = {2, 3, 4};
    int target2 = 6;
    vector<int> answer2 =  solution.twoSum(numbers2, target2);
    cout << answer2[0] << ' ' << answer2[1] << '\n';

    vector<int> numbers3 = {-1, 0};
    int target3 = -1;
    vector<int> answer3 = solution.twoSum(numbers3, target3);
    cout << answer3[0] << ' ' << answer3[1] << '\n';
    
    vector<int> numbers4 = {3, 24, 50, 79, 88, 150, 345};
    int target4 = 200;
    vector<int> answer4 =  solution.twoSum(numbers4, target4);
    cout << answer4[0] << ' ' << answer4[1] << '\n';

    return 0;
}