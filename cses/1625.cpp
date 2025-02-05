// cses 
// Grid Paths
// https://cses.fi/problemset/task/1625/

#include <bits/stdc++.h>
using namespace std;

string s;
int res;
bool vis[57][57];

void chooseDirection(int x, int y, int step) {
    if(x == 7 && y == 1) {
        if(step == 48) 
            res++;
        return;
    }
    if(step == 48) 
        return;
    if(vis[x][y - 1] && vis[x][y + 1] && !vis[x - 1][y] && !vis[x + 1][y])
        return;
    if(vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1])
        return;
    vis[x][y] = true;
    if(s[step] == '?' || s[step] == 'L') {
        if(!vis[x][y - 1])
            chooseDirection(x, y - 1, step + 1);
    }
    if(s[step] == '?' || s[step] == 'R') {
        if(!vis[x][y + 1])
            chooseDirection(x, y + 1, step + 1);
    }
    if(s[step] == '?' || s[step] == 'U') {
        if(!vis[x - 1][y])
            chooseDirection(x - 1, y, step + 1);
    }
    if(s[step] == '?' || s[step] == 'D') {
        if(!vis[x + 1][y]) 
            chooseDirection(x + 1, y, step + 1);
    }

    vis[x][y] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for(int i = 1; i <= 7; i++)
        vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = true;
    chooseDirection(1, 1, 0);
    cout << res;

    return 0;
}