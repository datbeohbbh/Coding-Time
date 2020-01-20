using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fir first
#define sec second
#define mp make_pair

const ll MAXN=3*(1e5+5);
pll tree[MAXN];
ll n,a,b,res=999999999,L=1,R=1,aa=0,bb=0;

main(void)
{
    freopen("MINROAD.INP","r",stdin);
    freopen("MINROAD.OUT","w",stdout);
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=1; i<=n; i++)
        cin>>tree[i].fir>>tree[i].sec;
    sort(tree+1,tree+1+n);
    aa+=(tree[L].sec == 1 ? 1 : 0);
    bb+=(tree[L].sec == 2 ? 1 : 0);
    while(L <= R && R <= n)
    {
        if(aa < a && bb < b)
        {
            R++;
            aa+=(tree[R].sec == 1 ? 1 : 0);
            bb+=(tree[R].sec == 2 ? 1 : 0);
        }
        else if(aa >= a && bb >= b)
        {
            res=min(res,tree[R].fir-tree[L].fir);
            aa-=(tree[L].sec == 1 ? 1 : 0);
            bb-=(tree[L].sec == 2 ? 1 : 0);
            L++;
        }
        else if(aa > a && bb < b)
        {
            if(tree[L].sec == 1)L++,aa--;
            R++;
            aa+=(tree[R].sec == 1 ? 1 : 0);
            bb+=(tree[R].sec == 2 ? 1 : 0);
        }
        else if(aa < a && bb > b)
        {
            if(tree[L].sec == 2)L++,bb--;
            R++;
            aa+=(tree[R].sec == 1 ? 1 : 0);
            bb+=(tree[R].sec == 2 ? 1 : 0);
        }
        else
        {
            R++;
            aa+=(tree[R].sec == 1 ? 1 : 0);
            bb+=(tree[R].sec == 2 ? 1 : 0);
        }
    }
    printf("%lld",(res!=999999999 ? res : -1));
}
