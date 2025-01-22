// IAEPC Preliminary Contest (Codeforces Round 999, Div. 1 + Div. 2) B. Kevin and Geometry
// https://codeforces.com/contest/2061/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, a[N], res1, res2, res3, res4;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    res1 = res2 = res3 = res4 = -1;
    map<int, int> mp;
    for(int i = 1; i <= n; i++)
        mp[a[i]]++;
    for(int i = 1; i <= n; i++) {
        if(mp[a[i]] >= 2) {
            if(res1 == -1 && res2 == -1) {
                res1 = res2 = a[i];
                mp[a[i]] -= 2;
            }
            else if(res3 == -1 && res4 == -1) {
                res3 = res4 = a[i];
                mp[a[i]] -= 2;
            }
        }
    }
    //cout << res1 << ' ' << res2 << '\n';
    if(res1 != -1 && res2 != -1 && res3 != -1 && res4 != -1)
        cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << '\n';
    else {
        if(res1 == -1 && res2 == -1)
            cout << -1 << '\n';
        else {
            vector<int> rest;
            for(int i = 1; i <= n; i++) {
                if(mp[a[i]] > 0) {
                    rest.push_back(a[i]);
                    mp[a[i]]--;
                }
            }
            /*for(int x : rest)
                cout << x << ' ';
            cout << '\n';*/
            sort(rest.begin(), rest.end());
            for(int i = 0; i < rest.size() - 1; i++) {
                if(abs(rest[i] - rest[i + 1]) < 2 * res1) {
                    res3 = rest[i];
                    res4 = rest[i + 1];
                    break;
                }
            }
            if(res3 == -1 && res4 == -1)
                cout << -1 << '\n';
            else
                cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << '\n';
        }
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