#include <bits/stdc++.h>
using namespace std;

const int N = 25;
const int INF = 1e9 + 7;
int n, a[N];
long long res = INF;
bool mark[N];

void AppleDivision(int x) {
    if(x > n) {
        long long cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++) {
            if(mark[i])
                cnt1 += a[i];
            else
                cnt2 += a[i];
        }
        res = min(res, abs(cnt1 - cnt2));
        return;
    }
    mark[x] = true;
    AppleDivision(x + 1);
    mark[x] = false;
    AppleDivision(x + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    AppleDivision(1);
    cout << res;
    
    return 0;
}