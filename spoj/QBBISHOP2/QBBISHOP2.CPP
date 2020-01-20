using namespace std;
#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=a;i<=b;i++)
#define fir first
#define sec second

typedef pair<int,int> pii;
const int MAXN=222;
int a[MAXN][MAXN],n,m,p,q,s,t;
bool ok=false;
queue <pii> Q;

void ReadData()
{
    freopen("QBBISHOP.INP","r",stdin);
    freopen("QBBISHOP.OUT","w",stdout);
    int r,c;
    cin>>n>>m>>p>>q>>s>>t;
    ford(i,0,498)ford(j,0,498)a[i][j]=1;
    ford(i,1,n)ford(j,1,n)a[i][j]=0;
    ford(i,1,m)
    {
        cin>>r>>c;
        a[r][c]=-1;
    }
}

void DiagonalLine(int u,int v)
{
    int u1,v1,u2,v2,u3,v3,u4,v4;
    u1=u-1;  v1=v+1;
    u2=u+1;  v2=v+1;
    u3=u-1;  v3=v-1;
    u4=u+1;  v4=v-1;
    while(a[u1][v1]==0)
    {
        Q.push(make_pair(u1,v1));
        a[u1][v1]=a[u][v]+1;
        u1=u1-1;
        v1=v1+1;
    }
    while(a[u2][v2]==0)
    {
        Q.push(make_pair(u2,v2));
        a[u2][v2]=a[u][v]+1;
        u2=u2+1;
        v2=v2+1;
    }
    while(a[u3][v3]==0)
    {
        Q.push(make_pair(u3,v3));
        a[u3][v3]=a[u][v]+1;
        u3=u3-1;
        v3=v3-1;
    }
    while(a[u4][v4]==0)
    {
        Q.push(make_pair(u4,v4));
        a[u4][v4]=a[u][v]+1;
        u4=u4+1;
        v4=v4-1;
    }
}

void QBBISHOP()
{
    pii coor;
    Q.push(make_pair(p,q));
    a[p][q]=1;
    while(!Q.empty())
    {
        coor=Q.front();
        if(coor.fir==s && coor.sec==t)
        {
            cout<<a[coor.fir][coor.sec]-1;
            ok=true;
            return ;
        }
        Q.pop();
        DiagonalLine(coor.fir,coor.sec);
    }
}

main(void)
{
    ReadData();
    QBBISHOP();
    if(!ok)cout<<-1;
}
