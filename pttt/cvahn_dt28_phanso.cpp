#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 11;
int a[N], b[N], n, m, k;
vector<pair<int, int>> factor, newFactor;

int findGCD(int x, int y)
{
    if(y == 0)
        return x;
    
    return findGCD(y, x % y);
}

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second < x.second * y.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("ps.inp","r",stdin);
    freopen("ps.out","w",stdout);

    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(b[j] == 0)
                continue;

            int t = a[i] / findGCD(a[i], b[j]), m = b[j] / findGCD(a[i], b[j]);
            factor.push_back({t, m});
        }
    }

    sort(factor.begin(), factor.end(), cmp);
    newFactor.push_back(factor.front());
    for(int i = 1; i < factor.size(); i++)
    {
        if(factor[i] != factor[i - 1])
            newFactor.push_back(factor[i]);
    }

    cout << newFactor[k - 1].first << ' ' << newFactor[k - 1].second;

    return 0;
}
