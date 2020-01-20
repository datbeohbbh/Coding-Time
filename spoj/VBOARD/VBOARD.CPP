using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

const ll MAXN=505;
ll var,blacks[MAXN][MAXN],whites[MAXN][MAXN],Fw[MAXN][MAXN],Fb[MAXN][MAXN];
ll n,q,d=0;
bool oky,okx;

void ReadData()
{
    //ios_base::sync_with_stdio(false); cin.tie(false); cout.tie(false);
    freopen("VBOARD.INP","r",stdin);
    freopen("VBOARD.OUT","w",stdout);
    cin>>n;
    okx=true;
    ford(i,1,n)
    {
        oky=okx;
        ford(j,1,n)
        {
            if(oky)cin>>whites[i][j];
            else cin>>blacks[i][j];
            Fw[i][j]=Fw[i-1][j]+Fw[i][j-1]-Fw[i-1][j-1]+whites[i][j];
            Fb[i][j]=Fb[i-1][j]+Fb[i][j-1]-Fb[i-1][j-1]+blacks[i][j];
            oky=!oky;
        }
        okx=!okx;
    }
}

void Answer()
{
    ll bl,wh,i,j,u,v;
    cin>>q;
    while(cin>>i>>j>>u>>v)
    {
        bl=Fb[u][v]-(Fb[i-1][v]+Fb[u][j-1])+Fb[i-1][j-1];
        wh=Fw[u][v]-(Fw[i-1][v]+Fw[u][j-1])+Fw[i-1][j-1];
        cout<<abs(bl-wh)<<endl;
    }
}

main(void)
{
    ReadData();
    Answer();
}
