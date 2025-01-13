// Codeforces Round 996 (Div. 2) B. Crafting
// https://codeforces.com/contest/2055/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;
int a[N], b[N], n, lack, excess, cnt;

void solve() {
    lack = cnt = 0;
    excess = INF;

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    for(int i = 1; i <= n; i++) {
        if(a[i] < b[i]) {
            lack = max(lack, b[i] - a[i]);
            cnt++;
        }
        else
            excess = min(excess, a[i] - b[i]);
    }
    if(cnt >= 2)
        cout << "NO" << '\n';
    else {
        if(lack > excess)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ntests;
    cin >> ntests;
    while(ntests--)
        solve();
    
    return 0;
}