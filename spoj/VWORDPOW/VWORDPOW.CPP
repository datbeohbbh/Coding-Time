using namespace std;
#include<bits/stdc++.h>

const int MAXN=1100;
string s[MAXN],good[MAXN/10];
int n,m;

main(void)
{
    freopen("VWORD.INP","r",stdin);
    freopen("VWORD.OUT","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=1; i<=n; i++)
        getline(cin,s[i]);
    for(int i=1; i<=m; i++)
        getline(cin,good[i]);
    for(int i=1; i<=n; i++)
    {
        int score=0;
        for(int j=1; j<=m; j++)
        {
            if((s[i]).size() < (good[j]).size())continue;
            int L=0,R=(good[j]).size()-1;
            for(int k=0; k<(s[i]).size(); k++)
                if((s[i])[k]==(good[j])[L] || toupper((s[i])[k])==(good[j])[L])
                {
                    L++;
                    if(L > R)
                    {
                        score++;
                        break;
                    }
                }
        }
        printf("%d\n",score);
    }
}
