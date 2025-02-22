#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, a[N], st[4 * N];
long long res;
string s, x;
vector<int> adj[27];

long long get(int id, int l, int r, int x, int y)
{
    if(r < x || y < l)
        return 0;
    
    if(x <= l && r <= y)
        return st[id];
    
    int mid = (l + r) / 2;

    return get(id * 2, l, mid, x, y) + get(id * 2 + 1, mid + 1, r, x, y);
}

void update(int id, int l, int r, int value)
{
    if(r < value || value < l)
        return;
    
    if(l == r && value == l)
    {
        st[id] = 1;
        return;
    }

    int mid = (l + r) / 2;

    update(id * 2, l, mid, value);
    update(id * 2 + 1, mid + 1, r, value);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("STRSWAP.INP","r",stdin);
    freopen("STRSWAP.OUT","w",stdout);

    cin >> n >> s >> x;
    
    for(int i = 0; i < x.size(); i++)
        adj[x[i] - 'a' + 1].push_back(i);
    for(int i = 1; i <= 26; i++)
        sort(adj[i].begin(), adj[i].end());
    for(int i = 0; i < s.size(); i++)
    {
        a[i + 1] = adj[s[i] - 'a' + 1].front();
        adj[s[i] - 'a' + 1].erase(adj[s[i] - 'a' + 1].begin());
    }

    for(int i = 1; i <= n; i++)
    {   
        res += get(1, 1, n, a[i] + 1, n);
        update(1, 1, n, a[i]);
    }

    cout << res;
    return 0;
}
