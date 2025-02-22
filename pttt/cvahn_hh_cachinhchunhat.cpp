#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 11;
pair<int, int> lines[N];
int n, mark[N], res = 0;

int calDis(int h, int l)
{
    return (lines[h].first - lines[l].first) * (lines[h].first - lines[l].first) + (lines[h].second - lines[l].second) * (lines[h].second - lines[l].second);
}

void Trace(int r, int s, int q)
{
    int remainX = lines[r].first + lines[q].first - lines[s].first;
    int remainY = lines[r].second + lines[q].second - lines[s].second;

    for(int i = 1; i <= n; i++)
    {
        if(lines[i].first == remainX && lines[i].second == remainY)
        {
            mark[i]++;
            break;
        }
    }
}

bool solve(int x, int y, int z)
{
    int e = calDis(x, y);
    int f = calDis(y, z);
    int g = calDis(x, z);

    if(e + f != g)
        return false;

    Trace(x, y, z);
    return true;
}

void findPoint(int a, int b, int c)
{
    if(solve(a, b, c))
        return;

    if(solve(b, a, c))
        return;

    if(solve(b, c, a))
        return;
}

main()
{
   // freopen("input.txt","r",stdin);
    freopen("cchunhat.inp","r",stdin);
    freopen("cchunhat.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> lines[i].first >> lines[i].second;

    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = i + 1; j <= n - 1; j++)
        {
            for(int k = j + 1; k <= n; k++)
                findPoint(i, j, k);
        }
    }

    for(int i = 1; i <= n; i++)
        res += mark[i];

    cout << res / 4;
    return 0;
}
