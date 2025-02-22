#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 198;
int a[N][N], sum[N][N];
vector< pair <int, int> > ans;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            sum[i][j] = max(sum[i - 1][j], sum[i - 1][j - 1]) + a[i][j];
            res = max(res, sum[i][j]);
        }
    }

    int past = res, idxX = n, idxY;
    for(int i = 1; i <= n; i++)
    {
        if(sum[n][i] == past)
        {
            idxY = i;
            past-=a[n][i];
            break;
        }
    }
    ans.push_back({idxX, idxY});
    while(past > 0)
    {
        if(sum[idxX - 1][idxY] == past)
            idxX--;
        else
        {
            idxX--;
            idxY--;
        }
        ans.push_back({idxX, idxY});
        past-=a[idxX][idxY];
    }

    cout << res << '\n';
    for(int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}
