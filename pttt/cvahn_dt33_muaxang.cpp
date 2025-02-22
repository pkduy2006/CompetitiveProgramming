#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 11;
int n, pos, res = 0, neededPetrol[N];

struct GasStation
{
    int idx, need, price;
} p[N];

bool cmp(GasStation x, GasStation y)
{
    return (x.price < y.price || (x.price == y.price && x.idx > y.idx));
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai5.inp","r",stdin);
    freopen("Bai5.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {   
        cin >> p[i].need;
        neededPetrol[i] = neededPetrol[i - 1] + p[i].need;
        p[i].idx = i;
    }
    for(int i = 1; i <= n; i++)
        cin >> p[i].price;

    sort(p + 1, p + 1 + n, cmp);
    pos = n;
    for(int i = 1; i <= n; i++)
    {
        if(p[i].idx > pos)
            continue;
         
        res += p[i].price * (neededPetrol[pos] - neededPetrol[p[i].idx - 1]);
        pos = p[i].idx - 1;
    }

    cout << res;

    return 0;
}
