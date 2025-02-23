#include<bits/stdc++.h>
#define int long long
const int nm = 1e4 + 1;
using namespace std;
struct diem
{
    double x, y;
};
diem a[nm];
vector<diem> v;
int n, d;
bool c[nm], kt;
double a1, b1, c1, p;
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
bool cmp(diem a, diem b)
{
    return (a.y < b.y);
}
bool sameside(diem d1, diem d2)
{
    int j = 0;
    double ans, a1, b1, c1;
    a1= d1.y - d2.y;
    b1= d2.x - d1.x;
    c1= d1.x * d2.y - d2.x * d1.y;
    do
    {
        j++;
        ans= a1 * a[j].x + b1 * a[j].y + c1;
    }
    while(ans == 0 && j < n);
    if(ans < 0)
    {
        for(int k = j + 1; k <= n; k++)
        {
            if(a1 * a[k].x + b1* a[k].y + c1 > 0)
            return 0;
        }
    }
    else
    {
        for(int k = j + 1; k <= n; k++)
        {
             if(a1* a[k].x + b1* a[k].y + c1 < 0)
                return 0;
        }
    }
    return 1;
}
void spdg()
{
    double s = 0.0, p = 0.0;
    for(int i = 0; i < v.size() - 1; i++)
    {
        s = s + (v[i].x - v[i + 1].x) * (v[i].y + v[i + 1].y) / 2;
        p = p + dis(v[i].x, v[i].y, v[i + 1].x, v[i + 1].y);
    }
    s = abs(s);
    cout << setprecision(3) << fixed << p << '\n' << s;
}
main()
{
    freopen("Baoloi.inp","r",stdin);
    freopen("Baoloi.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a + 1,a + 1 + n, cmp);
    v.push_back(a[1]);
    c[1] = 1;
    do
    {
        kt = false;
        for(int i = 2; i <= n; i++)
            if(c[i] == 0 && sameside(v[v.size() - 1], a[i]))
        {
            v.push_back(a[i]);
            c[i] = 1;
            kt = true;
        }
    }
    while(kt);
    v.push_back(a[1]);
    cout<< v.size() - 1 << " " << '\n';
    spdg();
    return 0;
}
