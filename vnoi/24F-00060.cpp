// VNOI
// Wooden Sticks
// https://oj.vnoi.info/problem/mstick

#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
int ntests, n;
pair<int, int> a[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].first >> a[i].second;
    
    sort(a + 1, a + 1 + n);
    vector<int> res;
    res.push_back(a[n].second);
    for(int i = n - 1; i >= 1; i--) {
        auto it = lower_bound(res.begin(), res.end(), a[i].second);
        if(it == res.end())
            res.push_back(a[i].second);
        else
            res[it - res.begin()] = a[i].second;
    }

    cout << res.size() << '\n';
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