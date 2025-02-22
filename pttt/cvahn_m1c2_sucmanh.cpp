#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100068], b[100069];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
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
