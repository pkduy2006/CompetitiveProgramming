// LeetCode
// 4. Median of Two Sorted Arrays
// Difficulty Level: Hard
// (M + N) solution 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> ans;
        for(int i = 0; i < nums1.size(); i++)
            ans.push_back(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            ans.push_back(nums2[i]);
        sort(ans.begin(), ans.end());
        if(ans.size() % 2 == 0)
            return (ans[ans.size() / 2 - 1] + ans[ans.size() / 2]) / 2;
        else
            return ans[ans.size() / 2];
    }
} solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> testCase1_nums1 = {1, 3};
    vector<int> testCase1_nums2 = {2};
    cout << solution.findMedianSortedArrays(testCase1_nums1, testCase1_nums2) << '\n';

    vector<int> testCase2_nums1 = {1, 2};
    vector<int> testCase2_nums2 = {3, 4};
    cout << solution.findMedianSortedArrays(testCase2_nums1, testCase2_nums2) << '\n';

    return 0;
}