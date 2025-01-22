// LeetCode
// Problem 240. Search in a 2D Matrix II 
// Difficulty level: Medium
// O(M + N) solution, beats 97.52%

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size() - 1, y = 0;
        while(x >= 0 && y < matrix[0].size()) {
            if(matrix[x][y] == target) 
                return true;
            else if(matrix[x][y] < target)
                y++;
            else
                x--;
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

    vector<vector<int>> matrix3 = {{-5}};
    int target3 = -5;
    cout << solution.searchMatrix(matrix3, target3) << '\n';

    return 0;
}