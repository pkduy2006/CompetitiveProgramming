#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SUCMANH.inp","r",stdin);
    freopen("SUCMANH.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] <= b[i])
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}
