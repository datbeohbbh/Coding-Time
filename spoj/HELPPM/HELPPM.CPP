using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define ford(i,a,b) for(int i=a;i<=b;i++)
#define fore(i,a,b) for(int i=a;i>=b;i--)

const ll MAXN=555;
ll a[MAXN][MAXN],b[MAXN][MAXN],x[MAXN],ri,rj,ru,rv,kmin=LONG_LONG_MAX,p,m,n;
bool ok=false;

void ReadData()
{
    //freopen("HELPPM.INP","r",stdin);
    //freopen("HELPPM.OUT","w",stdout);
    cin>>m>>n>>p;
    ford(i,1,m)ford(j,1,n)cin>>a[i][j];
    ford(i,1,n)ford(j,1,m)b[j][i]=b[j-1][i]+a[j][i];
}

void HelpPm()
{
    ford(i,1,m)ford(j,1,i)
    {
        ll L=0,R=0,sum=0;
        ford(k,1,n)x[k]=b[i][k]-b[j-1][k];
        while(R<=n && L<=R)
        {
            if(sum>=p)
            {
                if(kmin>(i-j+1)*(R-L+1))
                {
                    kmin=(i-j+1)*(R-L+1);
                    ri=j;
                    rj=L;
                    ru=i;
                    rv=R;
                    ok=true;
                }
                sum-=x[L];
                L++;
            }
            else
            {
                R++;
                sum+=x[R];
            }
        }
    }
    if(!ok)cout<<-1;
    else cout<<kmin<<endl<<ri<<" "<<rj<<" "<<ru<<" "<<rv;
}

main(void)
{
    ReadData();
    HelpPm();
}
