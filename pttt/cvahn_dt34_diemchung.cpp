#include <bits/stdc++.h>
using namespace std;

int n, k;
map<long long, int> milestones;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DC.inp","r",stdin);
    freopen("DC.out","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;

        ++milestones[a];
        --milestones[b + 1];
    }

    int tmp = 0;
    long long last = 1, res = 0;
    for(auto points : milestones)
    {
        if(tmp == k)
            res += points.first - last;
        
        last = points.first;
        tmp += points.second;
    }

    cout << res;

    return 0;
}
