#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 16, M = 1e2 + 16;
int n, q, a[N], h[N], par[N], p[N][25], lp[M], cnt[N][30], b[M], single[N][30];
vector<int> adj[N], prime;

void sieveLinear()
{
    for(int i = 2; i <= (int)1e2; i++)
    {
        if(lp[i] == 0)
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j < prime.size() && prime[j] <= lp[i] && i * prime[j] <= (int)1e2; j++)
            lp[prime[j] * i] = prime[j];
    }
    for(int i = 0; i < prime.size(); i++)
        b[prime[i]] = i + 1;
}

void extract(int node, int k)
{
    if(k < 2)
        return;

    int last = lp[k], c = 1;
    k /= lp[k];

    while (k != 1)
    {
        if(last != lp[k])
        {
            cnt[node][b[last]] = c;
            last = lp[k];
            c = 1;
        }
        else
            c++;

        k /= lp[k];
    }
    cnt[node][b[last]] = c;
}

void dfs(int u, int pu)
{
    extract(u, a[u]);
    for(int i = 1; i <= 25; i++)
        single[u][i] = cnt[u][i];
    if(pu != -1)
    {
        h[u] = h[pu] + 1;
        for(int i = 1; i <= 25; i++)
            cnt[u][i] += cnt[pu][i];
    }
    par[u] = pu;

    for(int v : adj[u])
    {
        if(v == pu)
            continue;

        dfs(v, u);
    }
}

void Build()
{
    fill(par, par + N, -1);
    memset(p, -1, sizeof p);
    dfs(1, -1);
    for(int i = 1; i <= n; i++)
        p[i][0] = par[i];

    for(int i = 1; i <= 20; i++)
    {
        for(int u = 1; u <= n; u++)
        {
            if(p[u][i - 1] == -1)
                continue;

            p[u][i] = p[p[u][i - 1]][i - 1];
        }
    }
}

int getLCA(int u, int v)
{
    if(h[u] < h[v])
        swap(u, v);
    int steps = h[u] - h[v];
    for(int i = 20; i >= 0; i--)
    {
        if((steps >> i) & 1)
            u = p[u][i];
    }

    assert(h[u] == h[v]);
    if(u == v)
        return u;
    for(int i = 20; i >= 0; i--)
    {
        if(p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    }

    assert(p[u][0] == p[v][0]);
    return p[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("TRSQ.INP","r",stdin);
    freopen("TRSQ.OUT","w",stdout);

    sieveLinear();

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Build();

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        int root = getLCA(u, v);
        //cout << root << '\n';
        if(p[root][0] == -1)
        {
            bool check = true;
            for(int i = 1; i <= 25; i++)
            {
                //cout << cnt[u][i] << ' ' << cnt[v][i] << '\n';
                if((cnt[u][i] + cnt[v][i] - cnt[root][i]) % 2 != 0)
                    check = false;
            }

            if(check)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
        else
        {
            bool check = true;
            for(int i = 1; i <= 25; i++)
            {
                if((cnt[u][i] + cnt[v][i] - 2 * cnt[p[root][0]][i] - single[root][i]) % 2 != 0)
                    check = false;
            }

            if(check)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}
