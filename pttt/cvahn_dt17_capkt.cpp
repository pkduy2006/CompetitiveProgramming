#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 25;
int a[N], n;
char s[2 * N];

void Read()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve()
{
    int idx = 1;
    for(int i = 1; i <= n; i++)
    {
        s[idx] = 'A';
        s[idx + a[i] + 1] = 'B';

        while(s[idx] == 'A' || s[idx] == 'B')
            idx++;
    }

    for(int i = 1; i <= 2 * n; i++)
        cout << s[i];
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
