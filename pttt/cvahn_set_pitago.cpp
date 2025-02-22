#include<bits/stdc++.h>
using namespace std;
const long long nm=1e8+1;
int i,j,n,dem,x;
long long t;
bool c[nm];
vector<long>a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x*x);
        c[x*x]=1;
    }
    sort(a.begin(),a.end());
    for(i=0;i<=a.size()-3;i++)
        for(j=i+1;j<=a.size()-2;j++)
        {
            t=a[i]+a[j];
            if(t<=nm&&c[t]==1) 
            dem++;
        }
    cout<<dem;
    return 0;
}
