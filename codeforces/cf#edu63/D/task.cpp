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
    return (long long)x*y%MOD;
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

const int N = 3e5 + 5;
ll a[N],f[N],g[N],ff[N],gg[N],s[N],t[N],l[N];
int n;
ll x;
ll ans = 0;

void solve()
{
    cin>>n>>x;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
        f[i] = ff[i] = a[i];
        g[i] = gg[i] = l[i] = i;
        ans += a[i];
    }
    maximize(ans,0);
    for(int i = 1;i <= n;++i){
        f[i] += f[i - 1];
    }
    for(int i = n;i >= 1;--i){
        ff[i] += ff[i + 1];
    }
    for(int i = n;i >= 1;--i){
        if(ff[i] < ff[gg[i + 1]]){
            gg[i] = i;
        }
        else {
            gg[i] = gg[i + 1];
        }
    }
    for(int i = 1;i <= n;++i){
        if(f[i] < f[g[i - 1]]){
            g[i] = i;
        }
        else {
            g[i] = g[i - 1];
        }
    }
    for(int i = 1;i <= n;++i){
        a[i] *= x;
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1;i <= n;++i){
        t[i] = s[i] - f[i] + f[g[i]];
    }
    for(int i = 1;i <= n;++i){
        if(t[i] < t[l[i- 1]]){
            l[i] = i;
        }
        else {
            l[i] = l[i - 1];
        }
    }
    for(int i = 1;i <= n;++i){
        maximize(ans,s[i] - t[l[i - 1]] + ff[i + 1] - ff[gg[i + 1]]);
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
