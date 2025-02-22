#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define pii pair <int,int>

using namespace std;

struct dg
{
    int a,b;
    ld w;
    // a va b : 2 dau mut, w : do dai
};

const int mxn=1e3+1;

int n,m,i,x[mxn],y[mxn],u,v,F[mxn];
ld cost;
vector <dg> B;
bool path[mxn][mxn];

void gop(int a, int b)
{
    while (a != F[a]) a = F[a];
    while (b != F[b]) b = F[b];
    if (F[a] < F[b])
        F[b] = F[a];
    else
        F[a] = F[b];
}

ld dist(int x1, int yy1, int x2, int y2)
{
    return sqrt(pow(x1-x2,2) + pow(yy1-y2,2));
}

bool cmp(dg l, dg r)
{
    return (l.w < r.w);
}

bool ktlt(int a, int b)
{
    while (a != F[a]) a = F[a];
    while (b != F[b]) b = F[b];
    return (a == b);
}

void kruskal(int n)
{
    int dem,i,u,v;
    ld dd;
    sort(B.begin(),B.end(),cmp);
    dem = 0;
    for (i=0; i<B.size(); i++){
        u=B[i].a; v=B[i].b; dd=B[i].w;
        if (ktlt(u,v) == 0){
            gop(u,v);
            cost += dd;
            dem++;
            if (dem == n-1)
                break;
        }
    }
}

int main()
{
    freopen("Highway.inp","r",stdin); freopen("Highway.out","w",stdout);
    cin >> n;
    for (u=1; u<=n; u++){
        F[u] = u;
    }
    for (i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    cin >> m;
    for (i=1; i<=m; i++){
        cin >> u >> v;
        gop(u,v);
        path[u][v] = 1; path[v][u] = 1;
    }
    for (u=1; u<=n; u++){
        for (v=1; v<=n; v++){
            if (u != v && path[u][v] == 0){
                dg temp1 = {u,v,dist(x[u],y[u],x[v],y[v])};
                B.PB(temp1);
            }
        }
    }
    cost = 0.0;
    kruskal(n);
    cout << setprecision(5)<<fixed << cost;
    cout << endl;
    return 0;
}
