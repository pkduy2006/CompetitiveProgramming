//Codeforces Round 976 (Div. 2) and Divide By Zero 9.0 A. Find Minimum Operations
//https://codeforces.com/contest/2020/problem/A
// 15/50

#include <bits/stdc++.h>
using namespace std;
 
int ntests;
long long n, k, cnt, res;
 
void solve() {
    cin >> n >> k;
    
    cnt = 1, res = 0;
    if(k == 1)
        cout << n << '\n';
    else {
        while(n > 0) {
            while (cnt * k <= n && k != 1) 
                cnt *= k;
            long long tmp = n / cnt;
            n -= tmp * cnt;
            cnt = 1;
            res += tmp;
        }

        cout << res << '\n';
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