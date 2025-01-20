#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
int ntests, n, m, res[N];

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    
    for(int i = 0; i < n; i++) 
        sort(a[i].begin(), a[i].end());
    bool check = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            if(a[i][j + 1] - a[i][j] != n) {
                check = false;
                break;
            }
        }
    }
    if(!check)
        cout << -1 << '\n';
    else {
        for(int i = 0; i < n; i++) 
            res[a[i][0]] = i;
        for(int i = 0; i < n; i++)
            cout << res[i] + 1 << ' ';
        cout << '\n';
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