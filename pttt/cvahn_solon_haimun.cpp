#include <bits/stdc++.h>
using namespace std;
const int nm=1000000;
int i,n,gt[nm],ngt;
void nhansl(int m)
{
	int i,nho=0;
	for(i=1;i<=ngt;i++)
	{
		nho=nho+gt[i]*m;
		gt[i]=nho%10;
		nho/=10;
	}
	while(nho>0)
	{
		ngt++;
		gt[ngt]=nho%10;
		nho/=10;
	}
}
int main()
{
    cin>>n;
	ngt=1;
	gt[1]=1;
	for(i=1;i<=n;i++)
	nhansl(2);
	for(i=ngt;i>=1;i--)
	cout<<gt[i];
    return 0;
}
