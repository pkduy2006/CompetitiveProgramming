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

const int N = 2e2 + 11;
int m, n, a[N][N], res = 1;
int jump_i[] = {-1, 0, 1, 0};
int jump_j[] = {0, 1, 0, -1};
vector<pair<int, int>> changeValue;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("cheese.inp","r",stdin);
    freopen("cheese.out","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    while(true)
    {
        changeValue.clear();

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(a[i][j] != 1)
                    continue;

                int cnt = 0;
                for(int k = 0; k < 4; k++)
                {
                    int next_i = i + jump_i[k], next_j = j + jump_j[k];

                    cnt += (a[next_i][next_j] != 1);
                }

                if(cnt >= 2)
                    changeValue.push_back({i, j});
            }
        }

        if(changeValue.empty())
            break;

        for(auto [x, y] : changeValue)
            a[x][y] = res + 1;
        res++;
    }

    cout << res - 1;

    return 0;
}
