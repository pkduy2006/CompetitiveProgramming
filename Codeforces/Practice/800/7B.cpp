//2024-2025 ICPC, NERC, Southern and Volga Russian Regional Contest (Unrated, Online Mirror, ICPC Rules, Preferably Teams) J. Waiting for...
//https://codeforces.com/problemset/problem/2038/J

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, b[N], cnt;
char a[N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 'P')
            cnt += b[i];
        else
        {
            if(cnt < b[i])
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
            cnt = max(0, cnt - b[i]);
        }
    }

    return 0;
}