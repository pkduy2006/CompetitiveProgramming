#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 16;
int n, m, a[N], res;
pair<int, int> c[N];
stack<pair<int, int>> s;
vector<pair<int, int>> new_a;

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
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> c[i].first >> c[i].second;

    sort(c + 1, c + 1 + m);

    s.push(c[1]);
    for(int i = 2; i <= m; i++)
    {
        while (!s.empty())
        {
            pair<int, int> a = s.top();
            if(a.second > c[i].second)
                s.pop();
            else
                break;
        }
        
        s.push(c[i]);
    }
    
    while (!s.empty())
    {
        new_a.push_back(s.top());
        s.pop();
    }
    
    sort(a + 1, a + 1 + n);
    int idx = 0;
    reverse(new_a.begin(), new_a.end());
    for(int i = 1; i <= n; i++)
    {
        while (a[i] > new_a[idx].first)
            idx++;
        res += new_a[idx].second;
    }

    cout << res;

    return 0;
}
