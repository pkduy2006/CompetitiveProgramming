#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 16;
bool mark[N];
int l, r;
vector<int> ans;

void Eratostheses()
{
    fill(mark, mark + N, true);
    mark[0] = mark[1] = false;

    for(int i = 2; i <= sqrt(N); i++)
    {
        if(mark[i])
        {
            for(int j = i * i; j <= N; j += i)
                mark[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("csnt.inp","r",stdin);
    freopen("csnt.out","w",stdout);

    Eratostheses();
    cin >> l >> r;
    for(int i = l; i <= r; i++)
    {
        if(mark[i])
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i << ' ';

    return 0;
}
