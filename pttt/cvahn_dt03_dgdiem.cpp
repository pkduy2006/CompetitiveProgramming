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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define task "DGDIEM"

struct Gpoint
{
    ll x,y;
};

using Gvector = Gpoint;

Gvector operator - (Gpoint a, Gpoint b)
{
    return {a.x-b.x, a.y-b.y};
}

ll operator * (Gvector a, Gvector b)
{
    return a.x*b.y - a.y*b.x;
}

bool cw(Gpoint a, Gpoint b, Gpoint c)
{
    Gvector u = b - a; Gvector v = c - b;
    return (u*v > 0);
}

const int maxN = 1e2;
const int INF = 1e9;
const ld EPS = 1e-9;

int n,m;
Gpoint a[maxN];

ld dis(Gpoint p, Gpoint q)
{
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

bool inside(Gpoint p)
{
    ll res = 0;
    for (int i=1; i<=n; i++){
        Gvector u = a[i+1] - a[i];
        Gvector v = p - a[i];
        if (u*v == 0){
            if (abs(dis(a[i], p) + dis(a[i+1], p) - dis(a[i], a[i+1])) > EPS)
                return 0;
        }
        else{
            if (res == 0){
                res = (u*v > 0) ? 1 : -1;
            }
            else if (res * (u*v) < 0) return 0;
        }
    }
    return 1;
}

main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    freopen("DGDIEM.inp","r",stdin); 
    freopen("DGDIEM.out","w",stdout);
    
    cin >> n >> m;
    int stid = 1;
    for (int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].y;
        if (a[i].x < a[stid].x || (a[i].x == a[stid].x && a[i].y < a[stid].y)){
            stid = i;
        }
    }
    swap(a[1], a[stid]);
    sort(a+2, a+n+1, [](Gpoint lo, Gpoint hi){
        Gvector u = lo - a[1];
        Gvector v = hi - a[1];
        return (u*v >= 0);
    });
    a[n+1] = a[1];
    int cnt = 0;
    for (int i=1; i<=m; i++){
        Gpoint p;
        cin >> p.x >> p.y;
        if (inside(p)){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
