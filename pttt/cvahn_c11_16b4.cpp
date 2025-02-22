#include <bits/stdc++.h>
using namespace std;

const int N = 25e4 + 16;
int n, res;
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
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!mark[i])
        {
            dfs(i);
            res++;
        }
    }
    
    cout << res;

    return 0;
}
