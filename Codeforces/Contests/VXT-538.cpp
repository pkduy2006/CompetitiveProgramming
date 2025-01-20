#include <bits/stdc++.h>
using namespace std;

int ntests, a1, a2, a4, a5, res, cnt;

void solve() {
    cin >> a1 >> a2 >> a4 >> a5;
    
    res = 0;
    for(int i = -200; i <= 200; i++) {
        cnt = 0;
        if(a1 + a2 == i)
            cnt++;
        if(a2 + i == a4)
            cnt++;
        if(i + a4 == a5)
            cnt++;
        res = max(res, cnt);
    }
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