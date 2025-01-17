// Codeforces Round 997 (Div. 2) C. Palindromic Subsequences
// https://codeforces.com/contest/2056/problem/C

#include <bits/stdc++.h>
using namespace std;

int ntests, n;

void solve() {
    cin >> n;
    
    if(n == 6)
        cout << 1 << ' ' << 1 << ' ' << 2 << ' ' << 3 << ' ' << 1 << ' ' << 2 << '\n';
    else {
        for(int i = 1; i <= n - 2; i++)
            cout << i << ' ';
        cout << 1 << ' ' << 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}