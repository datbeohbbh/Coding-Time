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

const int N=102;
int a[N],pre[N],suf[N];
string s;
ll f[N][N];
int n;

void solve()
{
    cin>>n>>s;
    s = " " + s;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
    }
    pre[0] = 1e9;
    suf[n + 1] = -1e9;
    for(int i = 1;i <= n;++i){
        pre[i] = suf[i] = i;
    }
    for(int i = 2;i <= n;++i)
        if(s[i] == s[i - 1])
            pre[i] = pre[i - 1];
    for(int i = n - 1;i >= 1;--i)
        if(s[i] == s[i + 1])
            suf[i] = suf[i + 1];
    for(int i = 1;i <= n;++i)
        f[i][i] = a[1];
    for(int gap = 2;gap <= n;++gap){
        for(int l = 1,r = l + gap - 1;r <= n;++l,++r){
            for(int j = pre[l - 1];j <= l - 1;++j)
                maximize(f[j][r],f[l][r] + a[l - j]);
            for(int j = r + 1;j <= suf[r + 1];++j)
                maximize(f[l][j],f[l][r] + a[j - r]);
            if(s[l - 1] == s[r + 1]){
                for(int lj = pre[l - 1];lj <= l - 1;++lj)
                    for(int rj = r + 1;rj <= suf[r + 1];++rj)
                        maximize(f[lj][rj],f[l][r] + a[rj - lj - r + l]);
            }
        }
    }
    cout<<f[1][n];
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
