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
#pragma GCC optimize("ducanhlosthisbike")

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
#define sz(x) (int)x.size()
#define task "DTTG"

struct Gpoint
{
    int x,y;
};

using Gvector = Gpoint;

Gvector operator - (Gpoint a, Gpoint b)
{
    return {a.x-b.x, a.y-b.y};
}

ll operator * (Gvector u, Gvector v)
{
    ll calc = u.x*v.y - u.y*v.x;
    if (calc == 0) return 0;
    return (calc > 0) ? 1 : -1;
}

Gpoint t[10];
Gpoint s[10];

bool inseg(Gpoint a, Gpoint b, Gpoint c) // check if c in segment(a,b)
{
    Gvector u = b-a;
    Gvector v = c-a;
    if (u*v != 0)
        return 0;
    return (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) &&
            c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y));
}

bool check3()
{
    for (int i=1; i<=3; i++){
        Gvector u = t[i+1] - t[i];
        Gvector v = s[2] - s[1];
        if (u*v != 0) continue;
        if (inseg(t[i], t[i+1], s[1])) return 1;
        if (inseg(t[i], t[i+1], s[2])) return 1;
    }
    return 0;
}

int intersect(Gpoint a, Gpoint b, Gpoint c, Gpoint d) // 0 -> no intersection, 1 -> intersect but not at end point of segment, 2 -> intersect at end point of segment
{
    if (inseg(a, b, c)) return 2;
    if (inseg(a, b, d)) return 2;
    if (inseg(c, d, a)) return 2;
    if (inseg(c, d, b)) return 2;
    int o1 = (b - a) * (c - a);
    int o2 = (b - a) * (d - a);
    int o3 = (d - c) * (a - c);
    int o4 = (d - c) * (b - c);
    if (o1 != o2 && o3 != o4) return 1;
    return 0;
}

int check12()
{
    bool EndPoint = 0;
    int cnt = 0;
    for (int i=1; i<=3; i++){
        int calc = intersect(t[i], t[i+1], s[1], s[2]);
        //cout << i<<' '<<calc<<'\n';
        if (calc == 0) continue;
        cnt++;
        if (calc == 2)
            EndPoint = 1;
    }
    if (EndPoint) cnt--;
    //cout << cnt<<'\n';
    return cnt;
}

bool check4()
{
    int ori = 0;
    for (int i=1; i<=3; i++){
        int cross = (t[i+1] - t[i]) * (s[1] - t[i]);
        if (cross == 0) return 0;
        if (ori == 0)
            ori = cross;
        else if (ori * cross < 0) return 0;
    }
    ori = 0;
    for (int i=1; i<=3; i++){
        int cross = (t[i+1] - t[i]) * (s[2] - t[i]);
        if (cross == 0) return 0;
        if (ori == 0)
            ori = cross;
        else if (ori * cross < 0) return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    cin >> t[1].x >> t[1].y >> t[2].x >> t[2].y >> t[3].x >> t[3].y;
    cin >> s[1].x >> s[1].y >> s[2].x >> s[2].y;
    t[4] = t[1];
    if (check3()){
        cout << 3;
        return 0;
    }
    if (check12() == 1){
        cout << 1;
        return 0;
    }
    if (check12() == 2){
        cout << 2;
        return 0;
    }
    if (check4()){
        cout << 4;
        return 0;
    }
    cout << 0;
    return 0;
}
