#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5+1;
int t,dem1[nm],dem2[nm],d1,d2;
string x;
char a1[nm],a2[nm];
bool ok;

struct vanban {
    string mau,go;
} vb[1001];

int main () {
    freopen ("BANPHIM.inp", "r", stdin);
    freopen ("BANPHIM.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++) 
        cin >> vb[i].mau >> vb[i].go;
    for (int i = 1; i <= t; i++) {
        d1 = 1;
        d2 = 1;
        memset(dem1,0,sizeof(dem1));
        memset(dem2,0,sizeof(dem2));
        for (int j = 0; j < (int)vb[i].mau.length(); j++) {
            dem1[d1]++;
            if (vb[i].mau[j] != vb[i].mau[j+1]) {
                a1[d1] = vb[i].mau[j];
                d1++;
            }
        }
        for (int k = 0; k < (int)vb[i].go.length(); k++) {
            dem2[d2]++;
            if (vb[i].go[k] != vb[i].go[k+1]) {
                a2[d2] = vb[i].go[k];
                d2++;
            }
        }
        ok = 1;
        for (int g = 1; g < max(d1,d2); g++) {
            if (dem1[g] > dem2[g] || a1[g] != a2[g]) {
                ok = 0;
                cout << "NO";
                break;
            }
        }
        if (ok) cout << "YES";
        cout << endl;
    }
    return 0;
}
