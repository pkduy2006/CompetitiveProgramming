#include <bits/stdc++.h>
#define int long long
using namespace std;

const float eps = 1e-9;

struct lines
{
    float x, y, u, v, a, b, c;
} l[2];

bool check(int p, int q)
{
    for(int i = 0; i < 2; i++)
    {
        if(min(l[i].x, l[i].u) - eps > p || p > max(l[i].u, l[i].x) + eps)
            return false;

        if(min(l[i].y, l[i].v) - eps > q || q > max(l[i].y, l[i].v) + eps)
            return false;
    }

    return true;
}

bool checkOnePoint()
{
    if(l[0].x == l[1].x && l[0].y == l[1].y)
        return true;

    if(l[0].x == l[1].u && l[0].y == l[1].v)
        return true;

    if(l[0].u == l[1].x && l[0].v == l[1].y)
        return true;

    if(l[0].u == l[1].u && l[0].v == l[1].v)
        return true;

    return false;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("haidoanthang.inp","r",stdin);
    freopen("haidoanthang.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 2; i++)
    {
        cin >> l[i].x >> l[i].y >> l[i].u >> l[i].v;

        l[i].a = l[i].v - l[i].y;
        l[i].b = l[i].x - l[i].u;
        l[i].c = l[i].x * l[i].v - l[i].y * l[i].u;
    }

    float d = l[0].a * l[1].b - l[1].a * l[0].b;

    if(checkOnePoint())
    {
        cout << 1;
        return 0;
    }

    if(abs(d) < eps)
    {
        if(l[0].a * l[1].c == l[1].a * l[0].c && l[0].c * l[1].b == l[1].c * l[0].b)
            cout << 2;
        else
            cout << 4;
    }
    else
    {
        float m = (l[1].b * l[0].c - l[0].b * l[1].c) / d;
        float n = (l[0].a * l[1].c - l[1].a * l[0].c) / d;

        if(check(m, n))
            cout << 3;
        else
            cout << 4;
    }

    return 0;
}
