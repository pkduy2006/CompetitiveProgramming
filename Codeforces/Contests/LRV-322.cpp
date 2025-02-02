// Codeforces Round 1002 (Div. 2) C - Customer Service
// https://codeforces.com/contest/2059/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 321;
int ntests, n, a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ntests;
    while(ntests--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cin >> a[i][j];
        }

        vector<int> b;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for(int j = n; j >= 1; j--) {
                if(a[i][j] == 1) {
                    cnt++;
                    if(cnt == n)
                        b.push_back(cnt);
                }
                else {
                    b.push_back(cnt);
                    break;
                }
            }
        }
        sort(b.begin(), b.end());
        //for(int c : b)
         //   cout << c << ' ';
      //  cout << '\n';
        int res = 0;
        for(int c : b) {
            if(c >= res + 1)
                res++;
        }
        if(res < n)
            res++;
        cout << res << '\n';
    }

    return 0;
}