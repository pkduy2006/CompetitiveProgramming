#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define PB push_back
#define MP make_pair
#define S second
#define pii pair <int,int>

using namespace std;

struct xyz
{
    int x,y,z;
};

const int mxn=1e3+1;

int n,m,u,v,w,i,F[mxn],ans;
vector <xyz> A;

bool cmp(xyz l, xyz r)
{
    if (l.z != r.z) return (l.z < r.z);
    if (l.y != r.y) return (l.y < r.y);
    return (l.x <= r.x);
}

bool ktlt(int u, int v) // true: u va v cung 1 cay
{
    while (u != F[u]) u=F[u];
    while (v != F[v]) v=F[v];
    return (u == v);
}

void kethop(int u, int v) // ket hop 2 cay thanh 1
{
    while (u != F[u]) u=F[u];
    while (v != F[v]) v=F[v];
    if (u<v)
        F[v] = u;
    else
        F[u] = v;
}

void kruskal(int n)
{
    int i,dem,u,v,w;
    sort(A.begin(),A.end(),cmp);
    dem = 0;
    for (i=0; i<m; i++){
        u=A[i].x; v=A[i].y; w=A[i].z;
        if (ktlt(u,v) == 0){
            kethop(u,v);
            dem++;
            ans = max(ans,w);
            if (dem == n-1)
                break;
        }
    }
}

int main()
{
    freopen("xaydungd.inp","r",stdin); freopen("xaydungd.out","w",stdout);
    cin >> n >> m;
    for (i=1; i<=m; i++){
        cin >> u >> v >> w;
        A.PB({u,v,w});
    }
    for (i=1; i<=n; i++){
        F[i] = i;
    }
    ans = 0;
    kruskal(n);
    cout << ans;
    return 0;
}
