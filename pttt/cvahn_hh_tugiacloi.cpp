#include <bits/stdc++.h>
#define int long long
using namespace std;

struct lines
{
    float x, y, dis;
} l[4];

bool check()
{
    if(l[1].x - l[0].x != l[2].x - l[3].x)
        return false;

    if(l[1].y - l[0].y != l[2].y - l[3].y)
        return false;

    if(l[3].x - l[0].x != l[2].x - l[1].x)
        return false;

    if(l[3].y - l[0].y != l[2].y - l[1].y)
        return false;

    return true;
}

float calDis(float x, float y, float z, float t)
{
    return sqrt((x - z) * (x - z) + (y - t) * (y - t));
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Tugiacloi.inp","r",stdin);
    freopen("Tugiacloi.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 4; i++)
        cin >> l[i].x >> l[i].y;

    if(!check())
    {
        cout << 5;
        return 0;
    }

    float a = calDis(l[0].x, l[0].y, l[1].x, l[1].y);
    float b = calDis(l[1].x, l[1].y, l[2].x, l[2].y);
    float c = calDis(l[2].x, l[2].y, l[3].x, l[3].y);
    float d = calDis(l[3].x, l[3].y, l[0].x, l[0].y);
    float e = calDis(l[1].x, l[1].y, l[3].x, l[3].y);
    float f = calDis(l[2].x, l[2].y, l[0].x, l[0].y);

    if(a == b && b == c && c == d && e == f)
    {
        cout << 4;
        return 0;
    }

    if(e == f)
    {
        cout << 3;
        return 0;
    }

    if(a == b && b == c && c == d)
    {
        cout << 2;
        return 0;
    }

    cout << 1;
    return 0;
}
