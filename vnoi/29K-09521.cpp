// VNOI 
// Hang động
// https://oj.vnoi.info/problem/c11cave

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, h, a[N], res[N], answer;
vector<int> stalactite, stalagmite;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> h;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i % 2 == 0)
            stalactite.push_back(a[i]);
        else
            stalagmite.push_back(a[i]);
    }

    answer = n;
    n /= 2;
    sort(stalactite.begin(), stalactite.end());
    sort(stalagmite.begin(), stalagmite.end());
    for(int i = 1; i <= h; i++) {
        int cnt = 0;
        cnt += n - (lower_bound(stalagmite.begin(), stalagmite.end(), i) - stalagmite.begin());
        cnt += n - (lower_bound(stalactite.begin(), stalactite.end(), h - i + 1) - stalactite.begin());
        //cout << cnt << '\n';
        answer = min(answer, cnt);
        res[cnt]++;
    }
    cout << answer << ' ' << res[answer];

    return 0;
}   