#include <bits/stdc++.h>
using namespace std;
const int dvc = 1e9;
int p,w,dis[1001][1001],ans,len,x,y,minn;
bool cotre[1001];
char u,v;
void floyd()
{
    for (int k = 1; k <= 26; k++)
        for (int i = 1; i <= 26; i++)
            for (int j = 1; j <= 26; j++)
                if (dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}
int main()
{
    freopen("VUONTRE.INP","r",stdin); 
    freopen("VUONTRE.OUT","w",stdout);
    for (int i = 1; i <= 26; i++)
        for (int j = 1; j <= 26; j++)
            dis[i][j] = dvc;
    cin >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> u >> v >> w;
        x = toupper(u)-64;
        y = toupper(v)-64;
        dis[x][y] = w; 
        dis[y][x] = w;
        if (u >= 'A' && u < 'Z')
            cotre[x]=1;
        if (v >= 'A' && v < 'Z')
            cotre[y]=1;
    }
    floyd();
    len = dvc;
    for (int i = 1; i < 26; i++)
        if (cotre[i] == 1 && dis[i][26] < len)
        {
            len = dis[i][26];
            ans = i;
        }
    cout << (char)(ans+64) << ' ' << len;
    cout << endl;
    return 0;
}
