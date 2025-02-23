#include<bits/stdc++.h>
using namespace std;

struct dataa
{
	int hv_1;
	int hv_A;
	int hv_a;
}
typedef dataa;

dataa pw[1000006];

int check (int fi, int kt)
{
	int num_1=pw[kt].hv_1 - pw[fi-1].hv_1;
	int num_a=pw[kt].hv_a - pw[fi-1].hv_a;
	int num_A=pw[kt].hv_A - pw[fi-1].hv_A;
	if (num_1>0 && num_a>0 && num_A>0 && kt-fi+1>=6) return 1;
	else return 0;
}

int tknp (int fi, int l, int r)
{
	int vt=-1;
	while (l<=r && r-fi+1>=6)
	{
		int mid = (l+r)/2;
		if (check (fi, mid)==1)
		{
			vt=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return vt;
}

int main ()
{
    freopen("matkhau.inp", "r", stdin);
    freopen("matkhau.out", "w", stdout);
	string s;
	cin>>s;
	pw[0].hv_1=0;
	pw[0].hv_a=0;
	pw[0].hv_A=0;
	int n=s.length();
	for (int i=1; i<=n; i++)
	{
		if (s[i-1]>='0' && s[i-1]<='9')
		{
			pw[i] = pw[i-1];
			pw[i].hv_1++;
		}
		else if (s[i-1]>='a' && s[i-1]<='z')
		{
			pw[i] = pw[i-1];
			pw[i].hv_a++;
		}
		else if (s[i-1]>='A' && s[i-1]<='Z')
		{
			pw[i] = pw[i-1];
			pw[i].hv_A++;
		}
	}
	long long dem=0;
	for (int i=1; i<=s.length()-6+1; i++)
	{
		int VT = tknp (i, i, n);
		if (VT!=-1)
		{
			dem+=n-VT+1;
		} else break;
	}
	cout<<dem;
	return 0;
}
