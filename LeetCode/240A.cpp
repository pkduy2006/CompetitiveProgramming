// LeetCode
// Problem 240. Search in a 2D Matrix II
// Difficulty: Medium
// O(N * log(N)) solution, beats 15.05%

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(it != matrix[i].end() && *it == target)
                return true;
        }
        return false;
    }
} solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> matrix1 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target1 = 5;
    cout << solution.searchMatrix(matrix1, target1) << '\n';

    vector<vector<int>> matrix2 = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target2 = 20;
    cout << solution.searchMatrix(matrix2, target2) << '\n';

    return 0;
}