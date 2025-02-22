#include <bits/stdc++.h>
#define int long long
using namespace std;

float u, v;

struct segment
{
    float x, y, dis;
} s[3];

void CalDistance()
{
    s[0].dis = (s[0].x - s[1].x) * (s[0].x - s[1].x) + (s[0].y - s[1].y) * (s[0].y - s[1].y);
    s[1].dis = (s[1].x - s[2].x) * (s[1].x - s[2].x) + (s[1].y - s[2].y) * (s[1].y - s[2].y);
    s[2].dis = (s[2].x - s[0].x) * (s[2].x - s[0].x) + (s[2].y - s[0].y) * (s[2].y - s[0].y);
}

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Tamgiacv.inp","r",stdin);
    freopen("Tamgiacv.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 3; i++)
        cin >> s[i].x >> s[i].y;

    CalDistance();

    if(s[0].dis + s[1].dis != s[2].dis)
    {
        cout << 0;
        return 0;
    }

    pair<float, float> res = {s[0].x + s[2].x - s[1].x, s[0].y + s[2].y - s[1].y};

    cout << res.first << ' ' << res.second << '\n';

    return 0;
}
