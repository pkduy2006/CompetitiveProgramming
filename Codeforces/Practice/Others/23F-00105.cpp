// Codeforces Round 674 (Div. 3) C. Increase and Copy
// https://codeforces.com/problemset/problem/1426/C

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int ntests, n, res;

void solve() {
    cin >> n;
    res = INF;

    for(int i = 1; i <= ceil(sqrt(n)); i++) 
        res = min(res, n / i - 1 + (n % i != 0) + i - 1);
    cout << res << '\n';
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