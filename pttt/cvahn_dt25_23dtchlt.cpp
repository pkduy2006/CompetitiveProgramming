#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 16;
int n, m;
vector<int> adj[N];
bool mark[N];

void dfs(int x)
{
    mark[x] = true;
    for(int y : adj[x])
    {
        if(mark[y])
            continue;

        dfs(y); 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DTCHLT.inp","r",stdin);
    freopen("DTCHLT.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    dfs(1);
    bool check = true;
    for(int i = 1; i <= n; i++)
    {
        if(!mark[i])
        {
            check = false;
            break;
        }
    }
    if(!check)
    {
        cout << 0;
        return 0;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!adj[i].size())
        {
            check = false;
            break;
        }   
    }

    if(!check)
        cout << 2;
    else
        cout << 1;
    
    return 0;
}
