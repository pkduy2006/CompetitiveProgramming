// Codeforces Round 997 (Div. 2) B. Find the Permutation
// https://codeforces.com/contest/2056/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int ntests, res[N], n;
string g[N];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> g[i];

    for(int i = 1; i <= n; i++)
        res[i] = i;
    sort(res + 1, res + 1 + n, [] (int me, int her) {
        if(me < her) 
            return g[me][her - 1] == '1';
        return g[me][her - 1] == '0';
    });
    for(int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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