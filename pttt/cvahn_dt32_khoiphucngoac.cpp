#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 11;
int n, a[N], idx = 1;
char res[10 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai2.inp","r",stdin);
    freopen("Bai2.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    fill(res, res + 10 * N, '0');

    for(int i = 0; i < 2 * n; i++)
    {
        if(res[i] == '0')
        {
            res[i] = '(';
            res[i + a[idx] + 1] = ')';
            idx++;
        }
    }

    for(int i = 0; i < 2 * n; i++)
        cout << res[i];

    return 0;
}
