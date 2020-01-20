#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second

const ll MAXN=555;
const ll tx1[]= {1,1,0};
const ll ty1[]= {0,1,1};
const ll tx2[]= {1,1,0};
const ll ty2[]= {0,-1,-1};
ll rb1[MAXN][MAXN],rb2[MAXN][MAXN],sign1[MAXN][MAXN],sign2[MAXN][MAXN],n,k;

void ReadData()
{
    freopen("ROBOCON.INP","r",stdin);
    freopen("ROBOCON.OUT","w",stdout);
    cin>>n>>k;
    ford(i,1,k)
    {
        ll u,v;
        cin>>u>>v;
        rb1[u][v]=-1;
        rb2[u][v]=-1;
    }
    ford(i,0,n+5)
    {
        rb1[0][i]=-1;
        rb2[0][i]=-1;
        rb1[i][0]=-1;
        rb2[i][0]=-1;
        rb1[i][n+1]=-1;
        rb2[i][n+1]=-1;
        rb1[n+1][i]=-1;
        rb2[n+1][i]=-1;
    }
    rb1[1][1]=1;
    rb2[1][n]=1;
}

void Robocon1()
{
    queue <pll> Q;
    Q.push(mp(1,1));
    sign1[1][1]=1;
    while(!Q.empty())
    {
        pll R=Q.front();
        Q.pop();
        ford(i,0,2)
        if(rb1[R.fir+tx1[i]][R.sec+ty1[i]]>-1 && sign1[R.fir+tx1[i]][R.sec+ty1[i]]==0)
        {
            rb1[R.fir+tx1[i]][R.sec+ty1[i]]=rb1[R.fir][R.sec]+1;
            Q.push(mp(R.fir+tx1[i],R.sec+ty1[i]));
            sign1[R.fir+tx1[i]][R.sec+ty1[i]]=1;
        }
    }
}

void Robocon2()
{
    queue <pll> Q;
    Q.push(mp(1,n));
    sign2[1][n]=1;
    while(!Q.empty())
    {
        pll R=Q.front();
        if(rb2[R.fir][R.sec]==rb1[R.fir][R.sec])
        {
            cout<<rb1[R.fir][R.sec]-1;
            return ;
        }
        Q.pop();
        ford(i,0,2)
        if(rb2[R.fir+tx2[i]][R.sec+ty2[i]]>-1 && sign2[R.fir+tx2[i]][R.sec+ty2[i]]==0)
        {
            rb2[R.fir+tx2[i]][R.sec+ty2[i]]=rb2[R.fir][R.sec]+1;
            Q.push(mp(R.fir+tx2[i],R.sec+ty2[i]));
            sign2[R.fir+tx2[i]][R.sec+ty2[i]]=1;
        }
    }
}

main(void)
{
    ReadData();
    Robocon1();
    Robocon2();
}
