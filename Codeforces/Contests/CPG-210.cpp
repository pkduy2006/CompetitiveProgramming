// Codeforces Round 997 (Div. 2) A. Shape Perimeter
// https://codeforces.com/contest/2056/problem/A

#include <bits/stdc++.h>
using namespace std;

const int N = 506;
int n, m, ntests;
pair<int, int> a[N];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    
    int res = 4 * m, pre_x = a[1].first + m, pre_y = a[1].second + m, cur_x = a[1].first, cur_y = a[1].second;
    for(int i = 2; i <= n; i++) {
        res += 4 * m;
        cur_x += a[i].first;
        cur_y += a[i].second;
        if(cur_x < pre_x && cur_y < pre_y)
            res -= 2 * (pre_x - cur_x) + 2 * (pre_y - cur_y);
        else if(cur_y == pre_y)
            res -= 2 * (pre_x - cur_x);
        else if(cur_x == pre_x)
            res -= 2 * (pre_y - cur_y);
        pre_x = cur_x + m;
        pre_y = cur_y + m;
        //cout << res << '\n';
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