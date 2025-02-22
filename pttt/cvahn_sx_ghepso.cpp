#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 4;

string a[N];

bool cmp(string a, string b)
{
    return a + b > b + a;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n, cmp);

    for(int i = 1; i <= n; i++)
        cout << a[i];
    return 0;
}
