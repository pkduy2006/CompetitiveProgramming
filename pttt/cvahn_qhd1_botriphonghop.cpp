#include<bits/stdc++.h>
using namespace std;
const int nm=1e6+1;
struct hop
{
	int a,b;
};
hop h[nm];
int n,i,vtd,dem;
bool sosanh(hop x,hop y)
{
	return((x.b<y.b)||(x.b==y.b&&x.a<y.a));
}
int main()
{
	freopen("phonghop.inp","r",stdin);
	freopen("phonghop.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>h[i].a>>h[i].b;
	sort(h+1,h+1+n,sosanh);
	vtd=1;
	dem=1;
	for(i=2;i<=n;i++)
		if(h[i].a>=h[vtd].b)
	{
		dem++;
		vtd=i;
	}
	cout<<dem;
}
