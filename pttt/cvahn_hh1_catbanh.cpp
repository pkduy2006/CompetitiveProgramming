#include <bits/stdc++.h>
#include<cstdio>
#include <vector>
#include<algorithm>
#include<cmath>

#define x first
#define y second
using namespace std;

typedef pair<int,int> ii;
typedef double ld;
typedef long long ll;

int n;
ii p[1500];
int s[1500][1500], res;
int check(int i, int j, int k)
{
    int a=p[j].y-p[i].y, b=p[i].x-p[j].x, c=(p[j].x-p[i].x)*p[i].y-(p[j].y-p[i].y)*p[i].x;
    int x=a*p[k].x+b*p[k].y+c;
    if(x<0) x=-x;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cake.inp","r",stdin);
    freopen("cake.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
    for(int i=0;i<n;i++)
    {
        int k=(i+3)%n;
        for(int j=(i+2)%n;j!=(i+n-1)%n;j=(j+1)%n)
        {
            if(k==j)k=(k+1)%n;
            s[i][j]=check(i,j,k);
            while ((k+1)%n!=i && check(i,j,k)<=check(i,j,(k+1)%n))
            {
                k=(k+1)%n;
                s[i][j]=check(i,j,k);
            }
            res=max(res,s[i][j]+s[j][i]);
        }
    }
    cout.precision(1);
    cout<<fixed<<(ld)res/2.0<<endl;
    
    return 0;
}
