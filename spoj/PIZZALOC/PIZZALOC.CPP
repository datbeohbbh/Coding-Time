using namespace std;
#include<bits/stdc++.h>
#define ll int

struct coor
{
    ll x,y,s;
};
coor a[25],b[111];
vector <ll> V[111];
ll k,m,n,sign[111],x[25],rem[111],maxx=0,R;

void ReadData()
{
    cin>>k>>R>>m;
    for(int i=1; i<=m; i++)cin>>a[i].x>>a[i].y;
    cin>>n;
    for(int i=1; i<=n; i++)cin>>b[i].x>>b[i].y>>b[i].s;
}

void Calc()
{
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            double d=sqrt((a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y));
            if(d<=R)V[i].push_back(j);
        }
}

void Pizzaloc()
{
    ll coun=0,sum=0,t=0;
    for(int i=1; i<=m; i++)
        if(x[i]==1)
        {
            coun++;
            rem[++t]=i;
        }
    if(coun==k)
    {
        for(int i=1; i<=t; i++)
            for(int j=0; j<V[rem[i]].size(); j++)
                if(sign[V[rem[i]][j]]==0)
                {
                    sum+=b[V[rem[i]][j]].s;
                    sign[V[rem[i]][j]]=1;
                }
        memset(sign,0,sizeof(sign));
        maxx=max(maxx,sum);
    }
}

void Bit(ll p)
{
    for(int i=0; i<=1; i++)
    {
        x[p]=i;
        if(p==m)Pizzaloc();
        else Bit(p+1);
    }
}

main(void)
{
    ReadData();
    Calc();
    Bit(1);
    cout<<maxx;
}
