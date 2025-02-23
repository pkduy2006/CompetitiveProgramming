#include <bits/stdc++.h>
using namespace std;

double dtich=0.0;
struct point
{
    double x, y;
};

struct diem
{
    double x, y;
};

struct diem1
{
    double x, y;
};

vector <diem> ans;
vector <diem1> da;

bool middle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double xm, double ym)
{
    double maxx1=max(x1,x2), minx1=min(x1, x2);
    double maxy1=max(y1,y2), miny1=min(y1, y2);
    double maxx3=max(x3,x4), minx3=min(x3, x4);
    double maxy3=max(y3,y4), miny3=min(y3, y4);
    if (xm>=minx1&&xm<=maxx1&&ym>=miny1&&ym<=maxy1&&
        xm>=minx3&&xm<=maxx3&&ym>=miny3&&ym<=maxy3)
    return true;
    return false;
}

bool gd(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double a1 = y2 - y1;
    double b1 = x1- x2;
    double c1 = a1*(x1) + b1*(y1);

    double a2 = y4 - y3;
    double b2 = x3 - x4;
    double c2 = a2*(x3)+ b2*(y3);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        return 0;
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        if (middle(x1,y1,x2,y2,x3,y3,x4,y4,x,y))
        ans.push_back({x,y});
        if (ans.empty()==false)
        return 1;
    }
    return 0;
}

double dtdg()
{
    double area = 0.0;
    int j = da.size() - 1;
    for (int i = 0; i < da.size(); i++)
    {
        area += (da[j].x + da[i].x) * (da[j].y - da[i].y);
        j = i;
    }
    return abs(area / 2.0);

}

vector <point> a;
int main()
{
    freopen ("area.inp","r",stdin);
    freopen ("area.out","w",stdout);
    int i;
    double y=0, x=0;
    string s;
    getline (cin,s);
    a.push_back({0,0});
    for (i=0;i<=s.length()-1;i++)
    {
        if (s[i]=='R') x++;
        else if (s[i]=='U') y++;
        if (s[i+1]!=s[i])
        {
            a.push_back({x,y});
        }
    }
    da.push_back({0,0});
    da.push_back({a[1].x,a[1].y});
    for (i=1;i<=a.size()-2;i++)
    {
        if (gd(a[i].x, a[i].y,a[i+1].x,a[i+1].y,a[0].x,a[0].y,a[a.size()-1].x, a[a.size()-1].y)==0)
            {
                da.push_back({a[i+1].x,a[i+1].y});
            }
        else
        {
            if (ans.empty()==false)
            da.push_back({ans[0].x, ans[0].y});
            dtich+=dtdg();
            da.erase(da.begin(),da.end());
            da.push_back({ans[0].x, ans[0].y});
            da.push_back({a[i+1].x,a[i+1].y});
            ans.erase(ans.begin(),ans.end());
        }
    }
    cout<<setprecision(3)<<fixed<<dtich;
    return 0;
}
