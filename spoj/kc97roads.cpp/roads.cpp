using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back

struct coor
{
    ll u,v;
    double w;
};
const ll MAXN=1011;
coor ed[1000111];
ll lab[MAXN];
ll n,m,d=0,s=0;
pll cor[MAXN];
double sum=0;

bool cmp(coor A,coor B)
{
    return A.w < B.w;
}

void Init()
{
    for(int i=1; i<n; i++)
        for(int j=1; j<=n; j++)
        {
            double L=sqrt((cor[i].fir-cor[j].fir)*(cor[i].fir-cor[j].fir)
                          +(cor[i].sec-cor[j].sec)*(cor[i].sec-cor[j].sec));
            d++;
            ed[d].u=i;
            ed[d].v=j;
            ed[d].w=L;
        }
}

ll getroot(ll x)
{
    while(lab[x]>0)x=lab[x];
    return x;
}

void Union(ll r1,ll r2)
{
    ll x=lab[r1]+lab[r2];
    if(abs(lab[r1])<abs(lab[r2]))
    {
        lab[r1]=r2;
        lab[r2]=x;
    }
    else
    {
        lab[r2]=r1;
        lab[r1]=x;
    }
}

void Kruskal()
{
    sort(ed+1,ed+1+d,cmp);
    for(int i=1;i<=n;i++)lab[i]=-1;
    for(int i=1;i<=d;i++)
    {
        if(s==n-1)break;
        ll r1=getroot(ed[i].u);
        ll r2=getroot(ed[i].v);
        if(r1!=r2)
        {
            sum+=ed[i].w;
            s++;
            Union(r1,r2);
        }
    }
    cout<<setprecision(2)<<fixed<<sum;
}

main(void)
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)cin>>cor[i].fir>>cor[i].sec;
    for(int i=1; i<=m; i++)
    {
        ll uk,vk;
        cin>>uk>>vk;
        d++;
        ed[d].u=uk;
        ed[d].v=vk;
        ed[d].w=0;
    }
    Init();
    Kruskal();
}
