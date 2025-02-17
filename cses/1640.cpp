// cses 
// Sum of Two Values
// https://cses.fi/problemset/task/1640/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, x, res1 = -1, res2 = -1;
pair<int, int> a[N];

int chop(int value, int start) {
    int l = start, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid].first < value)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a + 1, a + 1 + n);
    //for(int i = 1; i <= n; i++)
        //cout << a[i].first << ' ' << a[i].second << '\n';
    for(int i = 1; i <= n; i++) {
        int it = chop(x - a[i].first, i + 1);
        //cout << a[i].first << ' ' << a[it].first << '\n';
        if(a[it].first + a[i].first == x && i != it && a[it].first != 0) {
            //cout << a[i] << ' ' << *it << '\n';
            res1 = a[i].second;
            res2 = a[it].second;
            break;
        }
    }
    if(res1 == -1 && res2 == -1)
        cout << "IMPOSSIBLE";
    else
        cout << res1 << ' ' << res2;
    return 0;
}