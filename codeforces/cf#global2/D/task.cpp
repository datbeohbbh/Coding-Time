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

const int N = 1e5 + 5;
ll sum[N],b[N],s[N];
int n,q;

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>s[i];
    }
    sort(s + 1,s + 1 + n);
    for(int i = 2;i <= n;++i){
        b[i - 1] = s[i] - s[i - 1];
    }
    sort(b + 1,b + n);
    for(int i = n - 1;i >= 0;--i){
        sum[i] = sum[i + 1] + b[i];
    }
    cin>>q;
    while(q--){
        ll lk,rk;
        cin>>lk>>rk;
        ll ans = s[n] + rk - s[1] - lk + 1;
        int l = 1,r = n - 1;
        int pos = -1;
        for(int mid = (l + r)>>1;l <= r;mid = (l + r)>>1){
            if(b[mid] <= rk - lk){
                l = mid + 1;
            }
            else {
                r = mid - 1;
                pos = mid;
            }
        }
        if(~pos){
            ans -= (sum[pos] + 1LL*(n - pos)*1LL*(lk - rk - 1));
        }
        cout<<ans<<' ';
    }
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
