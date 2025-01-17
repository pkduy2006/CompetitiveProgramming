// 26. Remove Duplicates from Sorted Array
// Difficulty Level: Easy
// Time: 23.51 (UTC +02.00), 5/1/2025,

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       bool mark[207];
       fill(mark, mark + 207, false);
       for(int x : nums)
            mark[x + 100] = true;
        nums.clear();
        for(int i = -100; i <= 100; i++)    {
            if(mark[i + 100])
                nums.push_back(i);
        }
        return nums.size();
    }
}solution;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> testCase1 = {1, 1, 2};
    vector<int> testCase2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << solution.removeDuplicates(testCase1) << '\n';
    cout << solution.removeDuplicates(testCase2) << '\n';

    return 0;
}