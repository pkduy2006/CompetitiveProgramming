// Codeforces Round 1004 (Div. 2) B. Two Large Bags
// https://codeforces.com/contest/2067/problem/B

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int ntests, n, a[N], freq[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        fill(freq, freq + N, 0);
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        bool res = true;
        for(int i = 1000; i >= 1; i--) {
            if(freq[i] % 2 == 1) {
                bool check = false;
                int cnt = 0;
                for(int j = i - 1; j >= 1; j--) {
                    if(cnt + freq[j] >= 2 * (i - j) + 1) {
                        check = true;
                        freq[j] -= 2 * (i - j) + 1 - cnt;
                        break;
                    } else {
                        cnt += freq[j];
                        freq[j] = 0;
                    }
                }
                if(!check) {
                    res = false;
                    break;
                }
            }
        }
        if(res)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}