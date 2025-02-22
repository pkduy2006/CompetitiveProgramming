#include <bits/stdc++.h>
using namespace std;
const int dx[]={-2,-1,1,2,2,1,-1,-2};
const int dy[]={1,2,2,1,-1,-2,-2,-1};
const int nm=1001;
long long n,a[nm][nm],xx1,yy1,xx2,yy2;
struct xyz
{
    long long x,y,z;
};
long long bfs(long long x,long long y,long long z)
{
    queue <xyz> q;
    q.push({x,y,0});
    a[x][y]=2;
    while(q.empty()!=true)
    {
        x=q.front().x;
        y=q.front().y;
        z=q.front().z;
        q.pop();
        for (int i=0;i<8;i++)
        {
            long long u=x+dx[i];
            long long v=y+dy[i];
            if(u>0&&u<=n&&v>0&&v<=n&&a[u][v]==0)
            {
                a[u][v]=2;
                if(u==xx2&&v==yy2) return z+1;
                q.push({u,v,z+1});
            }
        }
    }
}
int main()
{
    cin>>n;
    cin>>xx1>>yy1>>xx2>>yy2;
    cout<<bfs(xx1,yy1,0);
    return 0;
}
