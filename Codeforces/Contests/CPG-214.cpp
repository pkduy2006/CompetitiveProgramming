#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int ntests, n, k, x[N], res;

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    
    unordered_map<int, int> cnt;
    res = 0;
    for(int i = 1; i <= n; i++)
        cnt[x[i]]++;
    for(int i = 1; i <= n; i++) {
        if(cnt[x[i]] > 0) {
            if(2 * x[i] == k) {
                if(cnt[x[i]] >= 2) {
                    res++;
                    cnt[x[i]] -= 2;
                }
            }
            else {
                if(cnt[k - x[i]] > 0) {
                    cnt[x[i]]--;
                    cnt[k - x[i]]--;
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
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