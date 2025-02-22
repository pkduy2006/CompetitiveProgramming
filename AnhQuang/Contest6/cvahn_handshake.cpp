#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],res,sum;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("HANDSHAKE.inp","r",stdin);
    freopen("HANDSHAKE.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        res=res+sum*a[i];
        sum=sum+a[i];
    }
    cout<<res;
    }
