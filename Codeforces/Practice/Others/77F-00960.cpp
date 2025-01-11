// Codeforces Round 545 (Div. 2) A. Sushi for Two
// https://codeforces.com/problemset/problem/1138/A

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N], n, cnt = 1, pre, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i - 1]) {
            res = max(res, min(cnt, pre) * 2);
            pre = cnt;
            cnt = 1;
        }
        else
            cnt++;
    }
    res = max(res, min(cnt, pre) * 2);
    cout << res;

    return 0;
}