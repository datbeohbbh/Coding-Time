using namespace std;
#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=a;i<=b;i++)

const int SIZE=222;
int a[SIZE][SIZE];
int m,n;
map <int,int> ma;

main(void)
{
    freopen("MCITYHAL.INP","r",stdin);
    freopen("MCITYHAL.OUT","w",stdout);
    scanf("%d%d",&m,&n);
    ford(i,1,m)ford(j,1,n)
    {
        char ch;
        cin>>ch;
        a[i][j]=ch-'0';
    }
    ford(i,1,n)a[m+1][i]=1;
    ford(j,1,n)
    {
        int cnt=0;
        ford(i,1,m+1)
        {
            if(a[i][j]==0)cnt++;
            else
            {
                ma[cnt]++;
                cnt=0;
            }
        }
    }
    for(map <int,int> :: iterator it=ma.begin(); it!=ma.end(); it++)
        if(it->first!=0)
            printf("%d %d\n",it->first,it->second);
}
