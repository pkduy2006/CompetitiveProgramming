#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 16;
int n, a[N];
set<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Chude.inp","r",stdin);
    freopen("Chude.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    cout << s.size();
    
    return 0;
}
