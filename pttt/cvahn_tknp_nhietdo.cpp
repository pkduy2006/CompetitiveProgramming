#include <bits/stdc++.h>

using namespace std;
const int nm=1e6+1;
int a[nm],i,n,mx,ans;

bool thu(int dl) {
    int vt=1;
    for(int i=vt+1; i<=n; i++)
        if(a[vt]<a[i] && a[i]-a[vt]<=dl) vt=i;
    if(vt==n || a[vt]>=a[n]) return 1;
    else return 0;
}

int main() {
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    mx=a[n]-a[1];
    int left=1; int right=mx;
    int mid;
    while(left<=right) {
        mid=(left+right)/2;
        if(thu(mid)) {
            ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    cout<<ans;
    return 0;
}
