// Codeforces Round 967 (Div. 2) B. Generate Permutation
// https://codeforces.com/problemset/problem/2001/B

#include <bits/stdc++.h>
using namespace std;

int ntests, n;

void solve() {
    cin >> n;
    
    if(n % 2 == 0)  
        cout << -1;
    else {
        for(int i = 1; i <= n; i += 2)
            cout << i << ' ';
        for(int i = 2; i <= n; i += 2)
            cout << i << ' ';
    }
    cout << '\n';
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