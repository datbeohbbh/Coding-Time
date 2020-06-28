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

const int N=1e5+5;
int a[N],cnt[N];
int n;

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i)
        cin>>a[i];
    if(n == 1){
        if(a[1] == 1)
          cout<<"Impossible",exit(0);
        else
          cout<<"Possible",exit(0);
    }
    sort(a + 1,a + 1 + n);
    if(a[n] != a[n - 1])
        cout<<"Impossible",exit(0);
    if(n - 2 > 0 and a[n] - 1 == 0)
        cout<<"Impossible",exit(0);
    for(int i = 1;i <= a[n] - 1;++i)
        if(a[n] > (a[i]<<1))
            cout<<"Impossible",exit(0);
    for(int i = 1;i <= a[n] - 1;++i)
        ++cnt[a[i]];
    int ce = a[n];
    for(int i = a[n];i <= n - 2;++i){
        if(!cnt[a[i] - 1])
            cout<<"Impossible",exit(0);
        ++ce;
        ++cnt[a[i]];
    }
    cout<<(ce == n - 1 ? "Possible" : "Impossible");
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//    freopen(fn".inp","r",stdin);
//    freopen(fn".out","w",stdout);
//    #endif // ONLINE_JUDGE
    task::solve();
}
