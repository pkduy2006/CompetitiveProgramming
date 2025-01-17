// 15. 3Sum
// Difficulty level: Medium
// Time: 01.47 (UTC +02.00), 6/1/2025, Helsinki
// N^2 log(N) solution using map

#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        map<pair<int, int>, bool> mp;
        for(int i = 1; i < nums.size() - 1; i++) {
            int l = 0, r = nums.size() - 1;
            while(l < i && i < r) {
                if(nums[l] + nums[i] + nums[r] < 0) {
                    l++;
                }
                else if(nums[l] + nums[i] + nums[r] > 0) {
                    r--;
                }
                else {
                    if(!mp[{nums[l], nums[r]}]) {
                        result.push_back({nums[l], nums[i], nums[r]});
                        mp[{nums[l], nums[r]}] = true;
                    }
                    l++;
                    r--;
                }
            }
        }
        return result;
    }
} solution;

void solve(vector<int>& x) {
    vector<vector<int>> ans = solution.threeSum(x);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> testCase1 = {-1, 0, 1, 2, -1, -4};
    vector<int> testCase2 = {0, 1, 1};
    vector<int> testCase3 = {0, 0, 0};
    vector<int> testCase4 = {0, 0, 0, 0};
    vector<int> testCase5 = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    solve(testCase1);
    solve(testCase2);
    solve(testCase3);
    solve(testCase4);
    solve(testCase5);

    return 0;
}