#include<bits/stdc++.h>
#define int long long
const int nm=1007;
const double eps=1e-5;
bool kt;
int i,j,n;
using namespace std;
struct diem
{
    double x,y;
};
diem a[nm];
double tdt(diem a,diem b,diem c)
{
    double a1,b1,c1;
    a1=a.y-b.y;
    b1=b.x-a.x;
    c1=a.x*b.y-a.y*b.x;
    return (a1*c.x+b1*c.y+c1);
}
void dtdg()
{
    double dt=0;
    for(int i=1;i<=n;i++)
    dt=dt+(a[i].x-a[i+1].x)*(a[i].y+a[i+1].y)/2;
    dt=abs(dt);
    cout<<setprecision(3)<<fixed<<dt;
}
bool ktloi(int i, int j)
{
    int k,vt;
    for(k=1;k<=n;k++)
        if(tdt(a[i],a[j],a[k])*tdt(a[i],a[j],a[k+1])<0) return 0;
    return 1;
}
bool ktcat(int l, int h)
{
    if(tdt(a[l],a[l+1],a[h])*tdt(a[l],a[l+1],a[h+1])<0 && tdt(a[h],a[h+1],a[l])*tdt(a[h],a[h+1],a[l+1])<0) return 1;
        return 0;
}
bool kttc ()
{
    int i,j;
    for(i=1;i<=n-1;i++)
        for(j=i+2;j<=n;j++)
        if(ktcat(i,j)) return 1;
    return 0;
}
int32_t main()
{
    freopen("Dagiac.inp","r",stdin);
    freopen("Dagiac.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
     cin>>a[i].x>>a[i].y;
    a[n+1]=a[1];
    kt=1;
    for(i=1;i<=n;i++)
        if(ktloi(i, i+1)==0) {kt=0; break;}
        if(kt)
        {
            cout<<1<<endl;
            dtdg();
        }
        else
        {
            if(kttc()) cout<<3;
            else
            {
                cout<<2<<endl;
                dtdg();
            }
        }
    return 0;
}
