#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> luckyNum;
char num[18];
char a[] = {'6', '8'};
int n;

void convert(int m)
{
    int ans = 0;

    for(int i = 1; i <= m; i++)
        ans = ans * 10 + (num[i] - '0');
    luckyNum.push_back(ans);

    for(int i = 1; i <= m; i++)
    {
        if(num[i] == '6')
            num[i] = '8';
        else
            num[i] = '6';
    }

    ans = 0;
    for(int i = 1; i <= m; i++)
        ans = ans * 10 + (num[i] - '0');
    luckyNum.push_back(ans);

    for(int i = 1; i <= m; i++)
    {
        if(num[i] == '6')
            num[i] = '8';
        else
            num[i] = '6';
    }
}

void Create(int cnt, int digit)
{
    for(int i = 0; i < 2; i++)
    {
        num[digit] = a[i];

        if(cnt == digit)
        {
            convert(cnt);

            return;
        }

        Create(cnt, digit + 1);
    }
}

void Build()
{
    for(int i = 1; i <= 17; i++)
        Create(i, 1);

    sort(luckyNum.begin(), luckyNum.end());
}

void Read()
{
    cin >> n;
}

void Solve()
{
    for(int i = 0; i < luckyNum.size(); i++)
    {
        if(luckyNum[i] % n == 0)
        {
            cout << luckyNum[i] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Build();

    int ntests;
    cin >> ntests;
    while(ntests--)
    {
        Read();

        Solve();
    }

    return 0;
}
