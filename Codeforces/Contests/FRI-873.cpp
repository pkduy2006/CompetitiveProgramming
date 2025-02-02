// Codeforces Round 1002 (Div. 2) A. Milya and Two Arrays
// https://codeforces.com/contest/2059/problem/A

#include <bits/stdc++.h>
using namespace std;

const int N = 57;
int ntests, a[N], b[N], n;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int cnta = 1, cntb = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i - 1])
            cnta++;
        if(b[i] != b[i - 1])
            cntb++;
    }
    if(cnta + cntb >= 4)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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