#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, a[N];
pair<int, int> dungeon[N]; // first là lượng máu cần thiết, second là tổng số quái vật

bool check(int stat)
{
    for(int i = 1; i <= n; i++)
    {
        if(stat + dungeon[i - 1].second <= dungeon[i].first)
            return false;

        stat += dungeon[i - 1].second;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DRPG.inp","r",stdin);
    freopen("DRPG.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {   
            int x;
            cin >> x;

            a[j] = max(x + 1 - j, 0);
        }
        
        dungeon[i].second = k;
        dungeon[i].first = *max_element(a + 1, a + 1 + k);
    }
    sort(dungeon + 1, dungeon + 1 + n);

    int l = 0, r = (int)2e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    cout << l;

    return 0;
}
