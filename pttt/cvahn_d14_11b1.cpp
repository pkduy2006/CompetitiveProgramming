// vegnim
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
#define task ""

struct Gpoint
{
    int x,y;
};

using Gvector = Gpoint;

Gvector operator - (Gpoint a, Gpoint b)
{
    return {a.x - b.x, a.y - b.y};
}

int operator * (Gvector a, Gvector b)
{
    return a.x*b.y - a.y*b.x;
}

bool cw(Gpoint a, Gpoint b, Gpoint c)
{
    Gvector u = b-a; Gvector v = c-b;
    return (u*v < 0);
}

const ld eps = 1e-9;

int d,n,r,ans;
Gpoint a[11];
vector <Gpoint> tree,hull,v;

ld dis(Gpoint a, Gpoint b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

ld peri()
{
    ld ans = 0.0;
    for (int i=0; i<(int)hull.size()-1; i++){
        ans += dis(hull[i], hull[i+1]);
    }
    return ans;
}

bool check()
{
    v.clear(); hull.clear();
    int m = (int)tree.size();
    sort(tree.begin(), tree.end(), [](Gpoint lo, Gpoint hi){
        if (lo.x != hi.x) return (lo.x < hi.x);
        return (lo.y < hi.y);
    });
    for (int i=0; i<m; i++){
        while ((int)v.size() >= 2 && cw(v[(int)v.size()-2], v.back(), tree[i]))
            v.pop_back();
        v.pb(tree[i]);
    }
    hull = v;
    hull.pop_back();
    v.clear();
    for (int i=m-1; i>=0; i--){
        while ((int)v.size() >= 2 && cw(v[(int)v.size()-2], v.back(), tree[i]))
            v.pop_back();
        v.pb(tree[i]);
    }
    hull.insert(hull.end(), v.begin(), v.end());
    ld rope = peri() + 2.0*3.14*r;
    return ((ld)d - rope >= eps);
}

void solve()
{
    cin >> d >> n >> r;
    for (int i=1; i<=n; i++){
        cin >> a[i].x >> a[i].y;
    }
    ans = 0;
    for (int mask = 0; mask < (1 << n); mask++){
        tree.clear();
        for (int i=n; i>=1; i--){
            if (mask >> (n-i) & 1){
                tree.pb(a[i]);
            }
        }
        if (check()){
            ans = max(ans, (int)tree.size());
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(task".inp","r",stdin); freopen(task".out","w",stdout);
    //freopen("inp.txt","r",stdin);
    int t; cin >> t;
    while (t--){
        solve();
        cout << '\n';
    }
    return 0;
}
