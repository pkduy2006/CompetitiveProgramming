#include<bits/stdc++.h>
using namespace std;
struct diem
{
    int x,y;
};
diem a,b,c,d;
double tdt(diem a, diem b, diem c){
    return ((a.y-b.y)*c.x + (b.x-a.x)*c.y + a.x*b.y - a.y*b.x);
}
int main()
{
    freopen("dtdt.inp","r",stdin);
    freopen("dtdt.out","w",stdout);
    cin>>a.x>>a.y>>b.x>>b.y;
    cin>>c.x>>c.y>>d.x>>d.y;
    if(tdt(c,d,a)==0 && tdt(c,d,b)==0)cout<<3;
    else if(tdt(c,d,a)==0 || tdt(c,d,b)==0 || tdt(c,d,a)*tdt(c,d,b)<0)cout<<1;
    else if(a.y-b.y==c.y-d.y)cout<<2;
    else cout<<4;
    return 0;
}
