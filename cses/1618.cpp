// cses
// Trailing Zeros
// https://cses.fi/problemset/task/1618/

#include <bits/stdc++.h>
using namespace std;

int n, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 5; i <= (int)1e9; i *= 5) 
        res += n / i;
    cout << res;

    return 0;
}