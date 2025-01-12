// Codeforces Round 996 (Div. 2) C. The Trail
//https://codeforces.com/contest/2055/problem/C

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int ntests, n, m;
long long a[N][N], sx[N], sy[N];
string s;

void solve() {
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    }

    long long sum = 0;
    int cur_x = 1, cur_y = 1;
    fill(sx + 1, sx + 1 + n, 0);
    fill(sy + 1, sy + 1 + m, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            sx[i] += a[i][j];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++)
            sy[i] += a[j][i];
    }
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'D') {
            a[cur_x][cur_y] = -sx[cur_x];
            sy[cur_y] += a[cur_x][cur_y];
            //cout << cur_y << ' ' << sy[cur_y] << '\n';
            cur_x++;
        }
        else {
            //cout << cur_y << ' ' << sy[cur_y] << '\n';
            a[cur_x][cur_y] = -sy[cur_y];
            sx[cur_x] += a[cur_x][cur_y];
            cur_y++;
        }
    }
    a[cur_x][cur_y] = - sx[cur_x];
    //cout << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
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