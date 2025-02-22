#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, m, e;
bool check;

void printAns(int x, int y, int z, int t)
{
    cout << "((((" << a;

    if(x == 1)
        cout << '+';
    else if(x == 2)
        cout << '-';
    else if(x == 3) 
        cout << '*';
    else    
        cout << '/';
    cout << b << ')';
    
    if(y == 1)
        cout << '+';
    else if(y == 2)
        cout << '-';
    else if(y == 3) 
        cout << '*';
    else    
        cout << '/';
    cout << c << ')';

    if(z == 1)
        cout << '+';
    else if(z == 2)
        cout << '-';
    else if(z == 3) 
        cout << '*';
    else    
        cout << '/';
    cout << d << ')';
    if(t == 1)
        cout << '+';
    else if(t == 2)
        cout << '-';
    else if(t == 3) 
        cout << '*';
    else    
        cout << '/';
    cout << e << ')';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Bieuthuc.inp","r",stdin);
    freopen("Bieuthuc.out","w",stdout);

    cin >> a >> b >> c >> d >> e >> m;

    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int k = 1; k <= 4; k++)
            {
                for(int t = 1; t <= 4; t++)
                {
                    int answer;
                    bool review = true;
                    if(i == 1)
                        answer = a + b;
                    else if(i == 2)
                        answer = a - b;
                    else if(i == 3)
                        answer = a * b;
                    else
                    {
                        if(a % b != 0)
                            review = false;
                        else
                            answer = a / b;
                    }
                    if(j == 1)
                        answer += c;
                    else if(j == 2)
                        answer -= c;
                    else if(j == 3) 
                        answer *= c;
                    else
                    {   
                        if(answer % c != 0)
                            review = false;
                        else
                            answer /= c;    
                    }
                    if(k == 1)
                        answer += d;
                    else if(k == 2)
                        answer -= d;
                    else if(k == 3)
                        answer *= d;
                    else 
                    {
                        if(answer % d != 0)
                            review = false;
                        else
                            answer /= d;
                    }
                    if(t == 1)
                        answer += e;
                    else if(t == 2)
                        answer -= e;
                    else if(t == 3)
                        answer *= e;
                    else
                    {
                        if(answer % e == 0)
                            review = false;
                        else
                            answer /= e;
                    }
                    if(answer == m && review)
                    {
                        printAns(i, j, k, t);
                        cout << '\n';
                        check = true;
                    }
                }
            }
        }
    }

    if(!check)
        cout << 0;

    return 0;
}
