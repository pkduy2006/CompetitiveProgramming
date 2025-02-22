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

struct pnt
{
    int x,y,id;
};

const int mxn = 1e3+1;
const int INF = 1e4;

int n,ans[mxn],cv[mxn];
pnt a[mxn];

int ccw(pnt a, pnt b, pnt c)
{
    int x,y,z,t;
    x = b.x - a.x; y = b.y - a.y;
    z = c.x - b.x; t = c.y - b.y;
    int val = x*t - z*y;
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

int sqrdis(pnt a, pnt b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(pnt l, pnt h)
{
    int d = ccw(a[1], l, h);
    if (d == -1) return 1;
    if (d == 0 && sqrdis(a[1], l) < sqrdis(a[1], h)) return 1;
    return 0;
}

bool cmp2(pnt l, pnt h)
{
    return (ans[l.id] == 0 && ans[h.id] > 0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("phaodai.inp","r",stdin); freopen("phaodai.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        a[i] = {x,y,i};
        ans[i] = 0;
    }
    int notcv = n;
    int cnt = 0;
    while (notcv > 2){
        cnt++;
        int num = 0;
        // tim diem goc tren trai
        sort(a+1, a+n+1, cmp2);
        int s = 0;
        for (int i=1; i<=notcv; i++){
            if (s == 0 || a[i].y > a[s].y || (a[i].y == a[s].y && a[i].x < a[s].x))
                s = i;
        }
        swap(a[1], a[s]);
        // sort
        sort(a+2, a+notcv+1, cmp);
        // tim 3 diem dau tien cua convex hull
        int m = 1;
        cv[m] = 1;
        ans[a[1].id] = cnt;
        num++;
        int i;
        for (i=2; i<=notcv; i++){
            if (m == 3) break;
            ++m;
            cv[m] = i;
            ans[a[i].id] = cnt;
            num++;
        }
        // tim convex hull
        for (; i<=notcv; i++){
            while (m > 1 && ccw(a[cv[m-1]], a[cv[m]], a[i]) == 1){
                ans[a[cv[m]].id] = 0;
                num--;
                m--;
            }
            m++;
            cv[m] = i;
            ans[a[i].id] = cnt;
            num++;
        }
        notcv -= num;
    }
    cnt++;
    for (int i=1; i<=n; i++){
        if (ans[i] == 0)
            cout << cnt;
        else
            cout << ans[i];
        cout << '\n';
    }
    return 0;
}
