// Codeforces Round 1003 (Div. 4) C1. Skibidus and Fanum Tax (easy version)
// https://codeforces.com/contest/2065/problem/C1 

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, m, a[N], b[N];

bool check() {
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int j = 1; j <= m; j++)
            cin >> b[j];
        
        if(check())
            cout << "YES" << '\n';
        else {
            a[1] = min(b[1] - a[1], a[1]);
            for(int i = 2; i <= n; i++) {
                if(a[i - 1] > a[i]) {
                    if(b[1] - a[i] >= a[i - 1])
                        a[i] = b[1] - a[i];
                } else {
                    if(b[1] - a[i] >= a[i - 1])
                        a[i] = min(a[i], b[1] - a[i]);
                }
            }
            /*for(int i = 1; i <= m; i++)
                cout << b[i] << ' ';
            cout << '\n';*/
            if(check())
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }

            //cout << value << ' ' << a[i] << '\n';
        //cout << '\n';
       // for(int i = 1; i <= n; i++)
       //     cout << a[i] << ' ';
       // cout << '\n';
    }

    return 0;
}