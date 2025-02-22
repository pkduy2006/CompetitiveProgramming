#include <bits/stdc++.h>
using namespace std;
int i,n,gt[1000001],ngt,m; 
void nhansl (int m) 
{
    int i, nho=0;
	for (i=1; i<=ngt; i++)
	{
		nho=nho+gt[i]*m;
		gt[i]=nho%10;
		nho=nho/10; 
	 } 
	while (nho>0)
	{
		ngt++; 
		gt[ngt]=nho%10;
		nho=nho/10; 
	 } 
}

int main () 
{
   	cin>>m>>n; 
   	ngt=1; 
   	gt[1]=1;
   	for (i=1; i<=n; i++)
		nhansl(m);
 	for (i=ngt; i>=1; i--)
	 	cout<<gt[i];	
}
