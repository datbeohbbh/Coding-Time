using namespace std;
#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<pii,int>
#define fir first
#define sec second
#define mp make_pair
#define ford(i,a,b) for(int i=a;i<=b;i++)

const int MAXN=111;
const int tx[]= {-1,1,0,0};
const int ty[]= {0,0,-1,1};
int a[MAXN][MAXN];
int r,c,x,y,z,t;

inline bool insize(int u,int v)
{
    return (1 <= u && u <= r && 1 <= v && v <= c && a[u][v]==0);
}

inline void Bessie()
{
    queue <piii> Q;
    set <pii> S;
    Q.push(mp(mp(x,y),0));
    S.insert(mp(x,y));
    while(!Q.empty())
    {
        piii it=Q.front();
        Q.pop();
        if(it.fir.fir==z && it.fir.sec==t)
        {
            printf("%d",it.sec);
            return ;
        }
        int u=it.fir.fir,v=it.fir.sec;
        ford(i,0,3)if(insize(u+tx[i],v+ty[i]) && S.find(pii(u+tx[i],v+ty[i]))==S.end())
        {
            Q.push(mp(mp(u+tx[i],v+ty[i]),it.sec+1));
            S.insert(mp(u+tx[i],v+ty[i]));
        }
    }
}

main(void)
{
    scanf("%d%d",&r,&c);
    ford(i,1,r)ford(j,1,c)
    {
        char ch;
        cin>>ch;
        if(ch=='C')x=i,y=j;
        else if(ch=='B')z=i,t=j;
        else a[i][j]=(ch=='*' ? 1 : 0);
    }
    Bessie();
}
