#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, a[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    bool check = true;
    for(int i = 1; i < n; i++) {
        int cnt = min(a[i], a[i + 1]);
        a[i] -= cnt;
        a[i + 1] -= cnt;
        if(a[i] != 0) {
            check = false;
            break;
        }
    }
    if(check)
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