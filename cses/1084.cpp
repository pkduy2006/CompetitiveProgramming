// cses
// Apartments
// https://cses.fi/problemset/task/1084/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, m, k, a[N], b[N], res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int j = 1;
    for(int i = 1; i <= n; i++) {
        while(j <= m && b[j] < a[i] - k)
            j++;
        if(a[i] - k <= b[j] && b[j] <= a[i] + k) {
            res++;
            j++;
        }
    }
    cout << res;

    return 0;
}