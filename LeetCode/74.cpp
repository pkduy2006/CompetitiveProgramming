// 74. Search a 2D Matrix
// Difficulty level: Medium
// Time: 16.43 (UTC +02.00), 13/1/2025

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int vasen = 0, oikea = matrix.size() - 1;
        while(vasen <= oikea) {
            int keskella = (vasen + oikea) / 2;
            if(matrix[keskella][0] <= target)
                vasen = keskella + 1;
            else
                oikea = keskella - 1;
        }
        if(oikea < 0)
            return false;
        auto it = lower_bound(matrix[oikea].begin(), matrix[oikea].end(), target);
        if(it == matrix[oikea].end())
            return false;
        return *it == target;
    }
} solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> matrix1 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target1 = 3;
    cout << solution.searchMatrix(matrix1, target1) << '\n';

    vector<vector<int>> matrix2 = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target2 = 13;
    cout << solution.searchMatrix(matrix2, target2) << '\n';

    vector<vector<int>> matrix3 = {{1}};
    int target3 = 0;
    cout << solution.searchMatrix(matrix3, target3);

    return 0;
}