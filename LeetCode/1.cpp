// 1. Two Sum
// Difficulty level: Easy
// Time: 02.36 (UTC +02.00), 6/1/2025, Helsinki

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
} solution;

void solve(vector<int>& nums, int target) {
    vector<int> res = solution.twoSum(nums, target);
    if(!res.size())
        cout << "No answer";
    else {
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> testCase1 = {2, 7, 11, 15}, testCase2 = {3, 2, 4}, testCase3 = {3, 3};
    int target1 = 9, target2 = 6, target3 = 6;
    solve(testCase1, target1);
    solve(testCase2, target2);
    solve(testCase3, target3);

    return 0;
}