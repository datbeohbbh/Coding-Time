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

const int base = 1e9 + 7;
const int N = 1e3 + 3;
int f[N][N];
vector <int> p[N];
int n,q,k;

int calc(){
    for(int i = 2;i <= n;++i){
        for(int j = 1;j <= k;++j){
            f[i][j] = 0;
        }
    }
    for(int i = 1;i <= k;++i){
        f[1][i] = 1;
    }
    for(int i = 2;i <= n;++i){
        for(int j = 1;j <= k;++j){
            for(int cur = 0;cur < sz(p[j]) and p[j][cur] <= k;++cur){
                f[i][j] = addmod(f[i][j],f[i - 1][p[j][cur]],base);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= k;++i){
        ans = addmod(ans,f[n][i],base);
    }
    return ans;
}

void solve(){
    for(int i = 1;i <= 1000;++i){
        for(int j = 1;j < i;++j){
            if(i % j)continue;
            p[i].pb(j);
        }
        for(int j = (i << 1);j <= 1000;j += i){
            p[i].pb(j);
        }
    }
    cin>>q;
    while(q--){
        int ans = 0;
        cin>>n>>k;
        cout<<calc()<<'\n';
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
