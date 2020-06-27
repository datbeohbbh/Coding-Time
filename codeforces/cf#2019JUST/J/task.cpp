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

const int N = 2e3 + 3;
int a[N][N],cnt[2][N],b[N][N];
int T,n,m;

void solve(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector <int> ve;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin>>a[i][j];
                b[i][j] = a[i][j];
            }
        }
        int ans = 0;
        for(int i = 2;i <= n;++i){
            ve.clear();
            for(int j = 1;j <= m;++j){
                ve.emplace_back(a[i][j]);
                ve.emplace_back(a[i - 1][j]);
            }
            sort(all(ve));
            ve.erase(unique(all(ve)),ve.end());
            for(int j = 1;j <= m;++j){
                b[i][j] = lower_bound(all(ve),a[i][j]) - ve.begin() + 1;
                b[i - 1][j] = lower_bound(all(ve),a[i - 1][j]) - ve.begin() + 1;
            }
            for(int j = 1;j <= sz(ve);++j){
                cnt[0][j] = cnt[1][j] = 0;
            }
            for(int j = 1;j <= m;++j){
                ++cnt[0][b[i][j]];
                ++cnt[1][b[i - 1][j]];
            }
            for(int j = 1;j <= sz(ve);++j){
                ans += min(cnt[0][j],cnt[1][j]);
            }
            for(int j = 1;j <= m;++j){
                b[i][j] = a[i][j];
                b[i - 1][j] = a[i][j];
            }
        }
        cout<<ans<<'\n';
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
