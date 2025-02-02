// cses
// Chessboard and Queens
// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
using namespace std;

string s[8];
int res;
int mark[8][8];

void PlaceQueen(int a) {
    if(a == 8) {
        res++;
        return;
    }
    for(int i = 0; i < 8; i++) {
        if(!mark[a][i] && s[a][i] != '*') {
            mark[a][i]++;
            for(int j = a + 1; j < 8; j++)
                mark[j][i]++;
            int b = a + 1, c = i + 1;
            while(b < 8 && c < 8) {
                mark[b][c]++;
                b++;
                c++;
            }
            b = a + 1, c = i - 1;
            while(b < 8 && c >= 0) {
                mark[b][c]++;
                b++;
                c--;
            }
            PlaceQueen(a + 1);
            mark[a][i]--;
            for(int j = a + 1; j < 8; j++) 
                mark[j][i]--;
            b = a + 1, c = i + 1;
            while(b < 8 && c < 8) {
                mark[b][c]--;
                b++;
                c++;
            }
            b = a + 1, c = i - 1;
            while(b < 8 && c >= 0) {
                mark[b][c]--;
                b++;
                c--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 8; i++)
        cin >> s[i];
    
    PlaceQueen(0);
    cout << res;
    
    return 0;
}