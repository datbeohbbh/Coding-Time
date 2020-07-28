#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const ll base = 1e9 + 7;
const int N = 1e5 + 5;
const int inf = 2e9;
set <pii> heap;
pii a[N];
int pos[N];
bool vis[N];
int n,x,y;
ll ans = 0;

void solve()
{
    cin>>n>>x>>y;
    for(int i = 1;i <= n;++i){
        cin>>a[i].sec>>a[i].fir;
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;++i){
        heap.insert(mp(a[i].fir,i));
        pos[i] = i;
    }
    for(int i = 1;i <= n;++i){
        int l = a[i].sec;
        set <pii> :: iterator it = heap.lower_bound(mp(l,0));
        if(it == heap.begin())continue;
        else
            --it;
        ll f = 1LL*y*1LL*l;
        ll cmp = (f - x) / y;
        if(1LL*x + 1LL*y*1LL*cmp <= f)
            ++cmp;
        set <pii> :: iterator nit = heap.lower_bound(mp(cmp,0));
        if(nit == heap.end())continue;
        if(nit -> fir > it -> fir)continue;
        int j = nit -> sec;
        heap.erase(nit);
        pos[i] = j;
    }
    for(int i = n;i >= 1;--i){
        if(vis[i])continue;
        int maxr = 0;
        int minl = inf;
        int j = i;
        while(true){
            vis[j] = true;
            maximize(maxr,a[j].fir);
            minimize(minl,a[j].sec);
            if(j == pos[j]){
                break;
            }
            j = pos[j];
        }
        ll u = 1LL*x;
        ll v = mul(1LL*y,1LL*(maxr - minl),base);
        ll s = addmod(u,v,base);
        ans = addmod(ans,s,base);
    }
    cout<<ans;
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
