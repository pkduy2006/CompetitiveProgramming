#include <bits/stdc++.h>
#define int long long
using namespace std;
const int modd=1e9;
const int nm=1e5+1;
int n,a[nm],dd;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai1.inp","r",stdin);freopen("Bai1.out","w",stdout);
cin>>n;
a[5]=3;
a[4]=1;
if (n==4){
cout<<1;
return 0;
}
if (n==5){
cout<<3;
return 0;
}
int dd=2;
int d=1;
for (int i=6;i<=n;i++){
        if (i%2==0)d=d+1;
        dd=dd+d;
        a[i]=a[i-1]+dd;
}
cout<<a[n]%modd;

    return 0;
}
