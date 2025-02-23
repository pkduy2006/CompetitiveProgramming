#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) setprecision(n) << fixed

struct rect
{
    int a,b,c,d;
};

const int mxn = 1e4+1;

int n,lis[mxn],res;
rect a[mxn];

int width(rect x)
{
    return x.c - x.a;
}

bool cmp(rect l, rect h)
{
    return (width(l) < width(h));
}

bool inside(rect x, rect y)
{
    return (y.a <= x.a && y.c >= x.c && y.b <= x.b && y.d >= x.d);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("hcnbn.inp","r",stdin); freopen("hcnbn.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y,z,t; cin >> x>>y>>z>>t;
        a[i] = {x, y, z, t};
    }
    sort(a+1, a+n+1, cmp);
    lis[1] = 1;
    res = 1;
    for (int i=2; i<=n; i++){
        lis[i] = 0;
        for (int j=1; j<i; j++){
            if (inside(a[j], a[i])){
                lis[i] = max(lis[i], lis[j]);
            }
        }
        lis[i]++;
        res = max(res, lis[i]);
    }
    cout << res;
    return 0;
}
