// 85. Maximal Rectangle 
// Difficulty level: Hard
// Time: 01.42 (UTC +02.00), 7/1/2025, Helsinki
// N^3 log (N) solution, beats only 5.01%, sadly

#include <bits/stdc++.h>
using namespace std;

const int N = 207;

class Solution {
public:
    int sum[N][N], res, a[N][N], h, w;

    bool check(int c, int d) {
        for(int i = 1; i <= h - c + 1; i++) {
            for(int j = 1; j <= w - d + 1; j++) {
                if(sum[i + c - 1][j + d - 1] - sum[i - 1][j + d - 1] - sum[i + c - 1][j - 1] + sum[i - 1][j - 1] == c * d)
                    return true;
            }
        }
        return false;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        /*for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }*/
        
        for(int i = 0; i <= 200; i++) {
            for(int j = 0; j <= 200; j++) {
                a[i][j] = 0;
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == '1')
                    a[i + 1][j + 1] = 1;
                //cout << matrix[i][j] << ' ' << a[i + 1][j + 1] << '\n';
            }
           // cout << '\n';
        }
        /*for(int i = 1; i <= matrix.size(); i++) {
            for(int j = 1; j <= matrix[i - 1].size(); j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        */
        for(int i = 0; i <= 200; i++) {
            for(int j = 0; j <= 200; j++)
                sum[i][j] = 0;
        }
        res = 0;
        h = matrix.size();
        w = matrix[0].size();

        for(int i = 1; i <= matrix.size(); i++) {
            for(int j = 1; j <= matrix[i - 1].size(); j++) {
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
                if(a[i][j] == 1)
                    sum[i][j]++;
            }
        }

        for(int x = 1; x <= matrix.size(); x++) {
            int l = 1, r = matrix[0].size();
            while(l <= r) {
                int mid = (l + r) / 2;
                if(check(x, mid)) {
                    res = max(res, x * mid);
                    //res = max(res, mid);
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        //cout << a[1][1] << '\n';
        
        return res;
    }
} solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<char>> testCase1 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    /*for(int i = 0; i < testCase1.size(); i++) {
        for(int j = 0; j < testCase1[i].size(); j++) {
            cout << testCase1[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    vector<vector<char>> testCase2 = {{'0'}};
    vector<vector<char>> testCase3 = {{'1'}};
    
    cout << solution.maximalRectangle(testCase1) << '\n';
    cout << solution.maximalRectangle(testCase2) << '\n';
    cout << solution.maximalRectangle(testCase3);

    return 0;
}