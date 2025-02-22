#include<bits/stdc++.h>
using namespace std;
struct duongtron{
    double x,y,r;
};
duongtron dt[1001];
int i,j,n;
double d;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>dt[i].x>>dt[i].y>>dt[i].r;
    for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
        {
            d=sqrt(pow(dt[i].x-dt[j].x,2)+pow(dt[i].y-dt[j].y,2));
            if(d<dt[i].r+dt[j].r&&d>abs(dt[i].r-dt[j].r))
                cout<<i<<' '<<j<<endl;
        }
    for(i=1;i<=n-1;i++)
        for(j=i+1;j<=n;j++)
        {
            d=sqrt(pow(dt[i].x-dt[j].x,2)+pow(dt[i].y-dt[j].y,2));
            if(d<=dt[i].r-dt[j].r)
            cout<<i<<' '<<j<<endl;
            else 
                if(d<=dt[j].r-dt[i].r)
                cout<<j<<' '<<i<<endl;
        }
    return 0;
}
