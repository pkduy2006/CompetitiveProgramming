#include <bits/stdc++.h>

using namespace std;

const int nm = 1e6+1;
bool snt[nm];
int n,x,y,z,a[nm],d=0;

void sangnt()
{
	fill(snt+1,snt+nm+1,1);
	snt[1]=0;
	for (int i = 2; i <= sqrt(nm); ++i)
	{
		if (snt[i])
		{
			for (int j = 2; i*j <= nm; ++j)
			{
				snt[i*j]=0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("BAI1.INP","r",stdin);
	freopen("BAI1.OUT","w",stdout);
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sangnt();
	z=x%y;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i]>=x and a[i]%y==z and snt[a[i]])
		{
			d++;
		}
	}
	cout << d;
	return 0;
}
