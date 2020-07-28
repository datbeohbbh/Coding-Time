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

const int inf = -1e9;
const int N = 5e2 + 1;
int left[N][N][N],right[N][N][N];
int a[N][N],sum[N][N];
int n,m;

void solve()
{
    cin>>n>>m;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j){
            cin>>a[i][j];
            fill(left[i][j],left[i][j] + 1 + n,inf);
            fill(right[i][j],right[i][j] + 1 + n,inf);
        }
    for(int j = 1;j <= m;++j)
        for(int i = 1;i <= n;++i)
            sum[i][j] = sum[i - 1][j] + a[i][j];
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j){
            int l = i,r = i;
            int cur = j;
            int val = 0;
            while(cur <= m and l >= 1 and r <= n){
                val += sum[r][cur] - sum[l - 1][cur];
                maximize(left[i][cur][r - l + 1],val);
                --l;
                ++r;
                ++cur;
            }
        }
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j){
            int l = i,r = i;
            int cur = j;
            int val = 0;
            while(cur >= 1 and l >= 1 and r <= n){
                val += sum[r][cur] - sum[l - 1][cur];
                maximize(right[i][cur][r - l + 1],val);
                --l;
                ++r;
                --cur;
            }
        }
    int ans = inf;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            for(int k = 1;k <= n;k += 2){
                int r = (k - 1) / 2;
                if(i + r > n)continue;
                if(i - r < 1)continue;
                maximize(ans,left[i][j][k] + right[i][j][k] - sum[i + r][j] + sum[i - r - 1][j]);
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
