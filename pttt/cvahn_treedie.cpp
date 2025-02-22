#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, res = 0;
pair<int, int> a[N];
bool mark[N];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if(x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
}

void Solve()
{
    sort(a + 1, a + 1 + n, cmp);
    fill(mark, mark + N, false);

    for(int i = 1; i <= n; i++)
    {
        if(mark[a[i].second] == false)
        {
            res++;
            
            if(a[i].second + 1 <= n)
                mark[a[i].second + 1] = true;
            if(a[i].second - 1 >= 1)
                mark[a[i].second - 1] = true;
                
            mark[a[i].second] = true;
        }
    }
    
    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Treedie.inp","r",stdin);
    freopen("Treedie.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
