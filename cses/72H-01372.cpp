// cses
// Ferris Wheel
// https://cses.fi/problemset/task/1090/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, x, p[N], res;
bool mark[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    sort(p + 1, p + 1 + n);
    int l = 1, r = n;
    while(l <= r) {
        while(p[l] + p[r] > x && l < r)
            r--;
        if(p[l] + p[r] <= x) {
            mark[l] = true;
            mark[r] = true;
            res++;
            r--;
        }
        l++;
    }
    for(int i = 1; i <= n; i++) {
        if(!mark[i])
            res++;
    }
    cout << res;
    
    return 0;
}