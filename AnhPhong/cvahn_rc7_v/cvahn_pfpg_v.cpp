#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16;
int n;
double a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PFPG.inp","r",stdin);
    freopen("PFPG.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;

        a[i] = a[i - 1] + log(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(a[i] > a[n] - a[i])
        {
            cout << i;

            return 0;
        }
    }
}
