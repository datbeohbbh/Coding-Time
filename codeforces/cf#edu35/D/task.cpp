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

const int N = 1555;
int a[N];
int f[2][N][N],cnt[2][N][N];
int n,m;

void calc(int t){
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cnt[t][i][j] = cnt[t][i - 1][j] + (j == a[i]);
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            cnt[t][i][j] += cnt[t][i][j - 1];
        }
    }
    for(int r = 1;r <= n;++r){
        for(int l = 1;l < r;++l){
            f[t][l][r] = f[t][l][r - 1] + cnt[t][r - 1][a[r] - 1] - cnt[t][l - 1][a[r] - 1];
        }
    }
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
    }
    calc(0);
    reverse(a + 1,a + 1 + n);
    calc(1);
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        int res = f[1][1][l - 1] + f[0][l][r] + f[1][r + 1][n];
        cout<<(res & 1 ? "odd" : "even")<<'\n';
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
