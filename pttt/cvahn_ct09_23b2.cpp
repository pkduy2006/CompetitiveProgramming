#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, cnt_step;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("dkt.inp","r",stdin);
    freopen("dkt.out","w",stdout);

    cin >> n;

    cnt_step = n * (n + 1) / 2;
    cnt_step %= 26;
    char res = cnt_step + 65;

    cout << res;

    return 0;
}
