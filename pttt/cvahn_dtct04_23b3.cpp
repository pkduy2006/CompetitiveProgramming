#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
string a[N];
int n;

bool cmp(string me, string her)
{
    return me + her > her + me;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("numjoin.inp","r",stdin);
    freopen("numjoin.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n, cmp);

    for(int i = 1; i <= n; i++)
        cout << a[i];

    return 0;
}
