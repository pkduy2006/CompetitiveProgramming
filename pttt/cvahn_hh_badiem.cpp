#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point
{
    float x, y;
} p[3];

main()
{
    //freopen("input.txt","r",stdin);
    freopen("Badiem.inp","r",stdin);
    freopen("Badiem.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;

    float a = sqrt((p[0].x - p[1].x) * (p[0].x - p[1].x) + (p[0].y - p[1].y) * (p[0].y - p[1].y));
    float b = sqrt((p[1].x - p[2].x) * (p[1].x - p[2].x) + (p[1].y - p[2].y) * (p[1].y - p[2].y));
    float c = sqrt((p[2].x - p[0].x) * (p[2].x - p[0].x) + (p[2].y - p[0].y) * (p[2].y - p[0].y));
    if(b + c == a)
        cout << 1;
    else if(a + b == c)
        cout << 2;
    else
    {
        float P = (a + b + c) / 2;
        float S = sqrt(P * (P - a) * (P - b) * (P - c));

        cout << fixed << setprecision(3) << S << '\n';
        cout << fixed << setprecision(3) << P * 2 << '\n';
    }

    return 0;
}
