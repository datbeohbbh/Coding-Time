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
int n;
ll sum[N];

void upd(int l,int r){
    sum[l] += 1LL*(r - l + 1);
    sum[r + 1] -= 1LL*(r - l + 1);
}

void solve()
{
    cin>>n;
    queue <pii> q;
    q.push(mp(1,n));
    upd(1,n);
    ll cnt = 1;
    for(;q.size();q.pop()){
        pii top = q.front();
        int l = top.fir;
        int r = top.sec;
        if(!(r - l)){
            continue;
        } else {
            int mid = (r - l + 1) >> 1;
            if(mid - l > 0 and r - mid > 0){
                cnt<<=1;
            }
            q.push(mp(l,mid));
            q.push(mp(mid + 1,r));
            upd(l,mid);
            upd(mid + 1,r);
            if((r - l + 1) & 1){
                q.push(mp(l,mid + 1));
                q.push(mp(mid + 2,r));
                upd(l,mid + 1);
                upd(mid + 2,r);
            }
        }
    }
    for(int i = 1;i <= n;++i){
        sum[i] += sum[i - 1];
    }
    cout<<setprecision(10)<<fixed;
    for(int i = 1;i <= n;++i){
        cout<<(double)(sum[i]) / (double)cnt<<' ';
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
