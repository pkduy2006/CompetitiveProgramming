#include<bits/stdc++.h>
using namespace std;
struct phanso
{
	int t,m;
};
int i,j,n,k,d;
phanso ps[1000001];
bool sosanh(phanso a, phanso b)
{
	return(a.t*b.m<b.t*a.m);
}
int main()
{
	cin>>n>>k;
	d=1;
	ps[1].t=0; ps[1].m=1;
	for(i=1;i<n;i++)
		for(j=i+1;j<=n;j++)
			if(__gcd(i,j)==1)
				{
					d++;
					ps[d].t=i;
					ps[d].m=j;
				}
	++d;
	ps[d].t=1; ps[d].m=1;
	sort(ps+1,ps+1+d,sosanh);
	cout<<ps[k].t<<"/"<<ps[k].m;
}
