using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define fir first
#define sec second

const ll MAXN=1111;
const double INF=9999999;
pll a[MAXN],b[MAXN];
ll n,m;
double AB=INF;

main(void)
{
    freopen("LEM.INP","r",stdin);
    freopen("LEM.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].fir>>a[i].sec;
    for(int i=1;i<=m;i++)cin>>b[i].fir>>b[i].sec;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
           double dis=sqrt((b[j].fir-a[i].fir)*(b[j].fir-a[i].fir)
                          +(b[j].sec-a[i].sec)*(b[j].sec-a[i].sec));
            AB=min(AB,dis);
        }
    cout<<setprecision(3)<<fixed;
    cout<<AB;
}
