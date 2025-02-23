#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 16;
const int INF = 1e9 + 7;
int f, v, a[N][N], dp[N][N], res = 1, trace[N][N];
vector<int> answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    freopen("flower.inp","r",stdin);
    freopen("flower.out","w",stdout);

    cin >> f >> v;
    for(int i = 1; i <= f; i++)
    {
        for(int j = 1; j <= v; j++)
            cin >> a[i][j];
    }

    memset(dp, -0x3f3f3f, sizeof(dp));
    for(int i = 1; i <= v; i++)
        dp[1][i] = a[1][i];

    for(int i = 2; i <= f; i++)
    {
        for(int j = 2; j <= v; j++)
        {
            for(int k = 1; k < j; k++)
            {   
                if(dp[i - 1][k] + a[i][j] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][k] + a[i][j];
                    trace[i][j] = k;
                }
            } 
        }
    }

    for(int i = 1; i <= v; i++)
    {
        if(dp[f][i] > dp[f][res])
            res = i;
    }
    cout << dp[f][res] << '\n';
    answer.push_back(res);
    for(int i = f; i > 1; i--)
    {   
        answer.push_back(trace[i][res]);
        res = trace[i][res];
    }
    for(int i = answer.size() - 1; i >= 0; i--)
        cout << answer[i] << ' ';
    return 0;
}
