// 60. Permutation Sequence
// Difficulty level: Hard
// Time: 16.32 (UTC +02.00), 8/1/2025, Helsinki
// O(n * n!) solution using next_permutation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a;
        string ans = "";

        for(int i = 1; i <= n; i++) {
            a.push_back(i);
        }
        k--;
        if(k > 0) {
            while(next_permutation(a.begin(), a.end()) && k > 1) {
                k--;
            }
        }
        for(int i = 0; i < a.size(); i++) {
            ans += a[i] + '0';
        }
        return ans;
    }
} solution;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << solution.getPermutation(3, 3) << '\n';
    cout << solution.getPermutation(4, 9) << '\n';
    cout << solution.getPermutation(3, 1) << '\n';
    cout << solution.getPermutation(2, 2) << '\n';

    return 0;
}