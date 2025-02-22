#include <bits/stdc++.h>
using namespace std;

int solve5(string k)
{
    int res = 0, posSt = -1, posNd = k.size();
    reverse(k.begin(), k.end());
    for(int i = 0; i < k.size(); i++)
    {
        if(k[i] == '5')
        {
            posSt = i;
            break;
        }
    }
    res += posSt;

    if(posSt == -1)
        return k.size();

    for(int i = posSt + 1; i < k.size(); i++)
    {
        if(k[i] == '2' || k[i] == '7')
        {
            posNd = i;
            break;
        }
    }
    res += (posNd - 1) - (posSt + 1) + 1;
    return (posSt != -1 && posNd != k.size() ? res : k.size());
}

int solve0(string k)
{
    int res = 0, posSt = -1, posNd = k.size();
    reverse(k.begin(), k.end());
    for(int i = 0; i < k.size(); i++)
    {
        if(k[i] == '0')
        {
            posSt = i;
            break;
        }
    }
    res += posSt;

    if(posSt == -1)
        return k.size();

    for(int i = posSt + 1; i < k.size(); i++)
    {
        if(k[i] == '0' || k[i] == '5')
        {
            posNd = i;
            break;
        }
    }

    res += (posNd - 1) - (posSt + 1) + 1;
    return (posSt != -1 || posNd != k.size() ? res : k.size());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("D25.inp","r",stdin);
    freopen("D25.out","w",stdout);

    string n;
    cin >> n;

    cout << min(solve0(n), solve5(n));

    return 0;
}
