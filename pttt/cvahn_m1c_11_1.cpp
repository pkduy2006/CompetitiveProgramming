#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 16;
int n, a[N];
vector<int> pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("timmax.inp","r",stdin);
    freopen("timmax.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int tmp = *max_element(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == tmp)
            pos.push_back(i);
    }
    
    cout << tmp << '\n';
    for(int i : pos)
        cout << i << ' ';

    return 0;
}
