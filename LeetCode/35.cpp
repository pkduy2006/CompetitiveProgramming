// LeetCode
// Problem No. 35: Search Insert Position

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it == nums.end())
            return nums.size();
        return it - nums.begin();
    }
} solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << solution.searchInsert(nums1, target1) << '\n';

    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << solution.searchInsert(nums2, target2) << '\n';

    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << solution.searchInsert(nums3, target3);

    return 0;
}