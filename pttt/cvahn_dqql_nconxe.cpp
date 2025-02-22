#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[100][100], dem, n;
bool b[100];

void inkq(int n)
{
     dem++;
    cout << dem << '\n';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

void nconxe (int i)
{
     for(int j = 1; j <= n; j++)
    {
        if(b[j] == 0)
        {
            a[i][j] = i;
            b[j] = 1;
            if (i == n) inkq(i);
            else
                nconxe(i + 1);
            b[j] = 0;
            a[i][j] = 0;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    nconxe(1);
    return 0;
}
