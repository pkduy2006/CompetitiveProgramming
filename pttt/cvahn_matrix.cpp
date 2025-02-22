#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 25;
int n, k, posX = 1, posY = 1, res = 1, d = 1, ans = 0;
char s[3 * N];
struct smallest
{
    int w, x, y;
}a[2 * N];

void run(int u, int v, int d)
{
    if(a[d].x != u)
    {
        ans = a[d].w + abs(a[d].x - u);
        res += a[d].w + abs(a[d].x - u);
    }
    else
    {
        res += a[d].w + abs(a[d].y - v);
        ans = a[d].w + abs(a[d].y - v);
    }
}

void Read()
{
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> s[i];
}

void Solve()
{
    a[1].w = 1;
    a[1].x = 1;
    a[1].y = 1;
    int cnt = 2;
    a[2 * n - 1].w = n * n;
    a[2 * n - 1].x = n;
    a[2 * n - 1].y = n;
    for(int i = 2; i <= n; i++)
    {
        a[i].w = a[i - 1].w + i - 1;
        if(i % 2 == 1)
        {
            a[i].x = i;
            a[i].y = 1;
        }
        else
        {
            a[i].y = i;
            a[i].x = 1;
        }
    }
    for(int i = 2 * n - 2; i >= n + 1; i--)
    {
        a[i].w = a[i + 1].w - cnt;
        cnt++;

        if(i % 2 == 0)
        {
            a[i].x = i - n + 1;
            a[i].y = n;
        }
        else
        {
            a[i].x = n;
            a[i].y = i - n + 1;
        }
    }

    for(int i = 1; i <= k; i++)
    {
        if(s[i] == 'U')
        {
            posX--;
            d--;
        }
        else if(s[i] == 'D')
        {
            posX++;
            d++;
        }
        else if(s[i] == 'L')
        {
            posY--;
            d--;
        }
        else if(s[i] == 'R')
        {
            posY++;
            d++;
        }

        run(posX, posY, d);
    }

    cout << res;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("matrix.inp","r",stdin);
    freopen("matrix.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Read();

    Solve();

    return 0;
}
