#include <bits/stdc++.h>
#define int long long
using namespace std;

const float eps = 1e-4;
float m, n;
bool mark[4];

struct lines
{
    float x, y;
} l[4];

bool checkPoint()
{
    for(int i = 0; i < 4; i++)
    {
        if(m == l[i].x && n == l[i].y)
            return true;
    }

    return false;
}

bool checkLine(float e, float f, float g, float h)
{
    float a = h - f;
    float b = e - g;
    float c = e * h - f * g;

    if(m * a + n * b == c && min(e, g) - eps <= m && m <= max(e, g) + eps && min(f, h) - eps <= n && n <= max(f, h) + eps)
        return true;

    return false;
}

float checkIn(float e, float f, float g, float h)
{
    float a = h - f;
    float b = e - g;
    float c = e * h - f * g;

    return a * m + b * n - c;
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Tugiacm.inp","r",stdin);
    freopen("Tugiacm.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 4; i++)
        cin >> l[i].x >> l[i].y;
    cin >> m >> n;

    if(checkPoint())
    {
        cout << 4;
        return 0;
    }

    for(int i = 0; i < 3; i++)
    {
        if(checkLine(l[i].x, l[i].y, l[i + 1].x, l[i + 1].y))
        {
            cout << 3;
            return 0;
        }
    }
    if(checkLine(l[3].x, l[3].y, l[0].x, l[0].y))
    {
        cout << 3;
        return 0;
    }

    for(int i = 0; i < 3; i++)
    {
        if(checkIn(l[i].x, l[i].y, l[i + 1].x, l[i + 1].y) >= -eps)
            mark[i] = true;
    }
    if(checkIn(l[3].x, l[3].y, l[0].x, l[0].y) >= -eps)
        mark[3] = true;

    if((mark[0] && mark[1] && mark[2] && mark[3]) || (!mark[0] && !mark[1] && !mark[2] && !mark[3]))
    {
        cout << 1;
        return 0;
    }

    cout << 2;
    return 0;
}
