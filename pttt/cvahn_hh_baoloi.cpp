#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 11;
int n;

struct point
{
    double x, y;
};

vector<point> ans;
point z;

bool cmp(point a, point b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

bool ccw(point a, point b, point c)
{
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

void Solve(vector<point> & a)
{
    if(a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);

    point pFirst = a.front(), pSecond = a.back();
    z = a.front();
    vector<point> up, down;
    up.push_back(pFirst);
    down.push_back(pFirst);

    for(int i = 1; i < a.size(); i++)
    {
        if(i == a.size() - 1 || cw(pFirst, a[i], pSecond))
        {
            while(up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();

            up.push_back(a[i]);
        }

        if(i == a.size() - 1 || ccw(pFirst, a[i], pSecond))
        {
            while(down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                down.pop_back();

            down.push_back(a[i]);
        }
    }

    for(int i = 0; i < up.size(); i++)
        ans.push_back(up[i]);
    for(int i = down.size() - 2; i >= 0; i--)
        ans.push_back(down[i]);
}

double calDis(int p, int q)
{
    return sqrt((ans[p].x - ans[q].x) * (ans[p].x - ans[q].x) + (ans[p].y - ans[q].y) * (ans[p].y - ans[q].y));
}

double findP()
{
    double res = 0;

    for(int i = 0; i < ans.size() - 1; i++)
        res += calDis(i, i + 1);

    return res;
}

double findS()
{
    double res = 0;

    for(int i = 0; i < ans.size() - 1; i++)
        res += (ans[i].x - ans[i + 1].x) * (ans[i].y + ans[i + 1].y) / 2;

    return abs(res);
}


main()
{
    //freopen("input.txt","r",stdin);
    freopen("Baoloi.inp","r",stdin);
    freopen("Baoloi.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<point> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    Solve(a);

    ans.push_back(z);

    cout << ans.size() - 2 << '\n';
    cout << fixed << setprecision(3) << findP() << '\n';
    cout << fixed << setprecision(3) << findS() << '\n';

    return 0;
}
