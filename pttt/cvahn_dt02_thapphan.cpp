#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int nm = 1e7+3;
int a,b,tmp,l,i;
string cs,tp;
int du[nm];

void solve() 
{
    cs += to_string(a / b);
    a %= b;

    cout << cs << ",";
    
    tp = "";
    while (true) {
        a *= 10;
        if (a % b == 0) {
            tp += to_string(a / b);
            break;
        }
        else if (du[a] != 0) {
            l = du[a];
            break;
        }
        else {
            tp += to_string(a / b);
            du[a] = tp.size();
        }
        a %= b;
    }

    for (i=0; i<(int)tp.size(); i++) {;
        if (i == l-1) cout << "(";
        cout << tp[i];
    }
    if (l != 0) cout << ")";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("thapphan.INP", "r", stdin);
    freopen("thapphan.OUT", "w", stdout);
    
    cin >> a >> b;
    solve();
    
    return 0;
}
