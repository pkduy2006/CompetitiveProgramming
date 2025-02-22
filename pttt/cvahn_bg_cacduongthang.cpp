#include<bits/stdc++.h>
using namespace std;
struct heso{
	double a;
	double b;
	double c;
};
heso dt[10000];
int i,k,d,dx,dy,n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>dt[i].a>>dt[i].b>>dt[i].c;
	for(int i=1;i<=n-1;i++)
		for(int k=i+1;k<=n;k++)
		{
			d=dt[i].a*dt[k].b-dt[k].a*dt[i].b;
			if(d!=0) cout<<i<<' '<<k<<endl;
		}
	for(int i=1;i<=n-1;i++)
		for(k=i+1;k<=n;k++)
		{
			d=dt[i].a*dt[k].b-dt[k].a*dt[i].b;
			dx=-dt[i].c*dt[k].b+dt[k].c*dt[i].b;
			dy=-dt[i].a*dt[k].c+dt[k].a*dt[i].c;
			if(d==0&&(dx!=0||dy!=0)) cout<<i<<' '<<k<<endl;
		}
	return 0;
}
