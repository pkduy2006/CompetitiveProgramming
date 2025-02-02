// Codeforces Round 1002 (Div. 2) B. Cost of the Array
// https://codeforces.com/contest/2059/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, k, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        int res = 0;
        if(n == k) {
            for(int i = 2; i <= n; i += 2) {
                if(a[i] != i / 2) {
                    res = i / 2;
                    break;
                }
            }
            if(!res)
                res = n / 2 + 1;
        } else {
            bool check = false;
            for(int i = 2; i <= n - k + 2; i++) {
                if(a[i] != 1) {
                    check = true;
                    break;
                }
            }
            if(check)
                res = 1;
            else
                res = 2;
        }
        cout << res << '\n';
    }
    
    return 0;
}