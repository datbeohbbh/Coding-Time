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
int n,k,A,B;
map <int,int> pos;
int a[N];

pii calc(int l,int r){
    int tl = -1,tr = -1;
    for(int lk = 1,rk = k,mid = (lk + rk)>>1;lk <= rk;mid = (lk + rk)>>1){
        if(a[mid] <= r){
            tr = mid;
            lk = mid + 1;
        }
        else {
            rk = mid - 1;
        }
    }
    for(int lk = 1,rk = k,mid = (lk + rk)>>1;lk <= rk;mid = (lk + rk)>>1){
        if(a[mid] >= l){
            tl = mid;
            rk = mid - 1;
        }
        else {
            lk = mid + 1;
        }
    }
    return mp(tl,tr);
}

ll f(int l,int r){
    if(r - l){
        int mid = (r + l)>>1;
        pii seg = calc(l,r);
        if(seg.fir == -1 or seg.sec == -1 or seg.fir > seg.sec){
            return 1LL*A;
        }
        else {
            return min(1LL*(seg.sec - seg.fir + 1)*1LL*B*1LL*(r  - l + 1),f(l,mid) + f(mid + 1,r));
        }
    }
    else {
        return (pos[l] == 0 ? 1LL*A : 1LL*B*1LL*pos[l]);
    }
}

void solve()
{
    cin>>n>>k>>A>>B;
    for(int i = 1;i <= k;++i){
        cin>>a[i];
        ++pos[a[i]];
    }
    sort(a + 1,a + 1 + k);
    cout<<f(1,(1<<n));
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
