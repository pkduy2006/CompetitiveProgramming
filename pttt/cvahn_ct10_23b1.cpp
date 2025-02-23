#include<bits/stdc++.h>
using namespace std;
struct diem
{
    double x, y;
};
diem a, b, c, d;
double a1, b1, c1, a2, b2, c2, dd, dx, dy;
void dt(diem a, diem b, double &a1, double &b1, double &c1)
{
    a1 = b.y - a.y;
    b1 = a.x - b.x;
    c1 = -a.x * b.y + b.x * a.y;
}
double tdt(diem a, double a1, double b1, double c1)
{
    return(a1 * a.x + b1 * a.y + c1);
}
main()
{
    freopen("haidt.inp","r",stdin);
    freopen("haidt.out","w",stdout);
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    dt(a, b, a1, b1, c1);
    dt(c, d, a2, b2, c2);
    dd = a1 * b2 - a2 * b1;
    dx = -c1 * b2 + c2 * b1;
    dy = -a1 * c2 + a2 * c1;
    if(dd == 0)
    {
        if(dx != 0 || dy != 0) cout << 4;
        else
        {
            if(((a.x - c.x) * (c.x - b.x) > 0 || (a.y - c.y) * (c.y - b.y)>0)||
               ((a.x - d.x) * (d.x - b.x) > 0 || (a.y - d.y) * (d.y - b.y) > 0) ||
               ((c.x - a.x) * (a.x - d.x) > 0 || (c.y - a.y) * (a.y - d.y) > 0) ||
               ((c.x - b.x) * (b.x-d.x)>0||(c.y-b.y)*(b.y-d.y)>0)) cout<<2;
                else
                if((a.x==c.x&&a.y==c.y)||(b.x==c.x&&b.y==c.y)||
                   (a.x==d.x&&a.y==d.y)||(b.x==d.x&&b.y==d.y)) cout<<1;
                else cout<<4;
        }
        }
        else
        {
            if(tdt(c,a1,b1,c1)*tdt(d,a1,b1,c1)<0&&tdt(a,a2,b2,c2)*tdt(b,a2,b2,c2)<0) cout<<3;
            else
            if(tdt(c,a1,b1,c1)==0||tdt(d,a1,b1,c1)==0||tdt(a,a2,b2,c2)==0||tdt(b,a2,b2,c2)==0) cout<<1;
            else cout<<4;
        }
        return 0;
        }
