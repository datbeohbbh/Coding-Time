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

const int N = 5e3 + 5;
const ll base[] = {1000000007,1000000087};
const ll m[] = {26,29};
ll pw[2][N],hs[2][N];
int n,ans = N;
string s;

pll getHash(int l,int r){
    ll hs1 = (hs[0][r] - hs[0][l - 1] * pw[0][r - l + 1] + base[0]*base[0]) % base[0];
    ll hs2 = (hs[1][r] - hs[1][l - 1] * pw[1][r - l + 1] + base[1]*base[1]) % base[1];
    return mp(hs1,hs2);
}

bool ok(int l,int r){
    pll x = getHash(1,l);
    pll y = getHash(r,n);
    return (x != y);
}

void solve()
{
    cin>>s;
    n = sz(s);
    s = " " + s;
    pw[0][0] = pw[1][0] = 1;
    for(int j = 0;j < 2;++j){
        for(int i = 1;i <= n;++i){
            pw[j][i] = mul(pw[j][i - 1],m[j],base[j]);
        }
    }
    for(int j = 0;j < 2;++j){
        for(int i = 1;i <= n;++i){
            hs[j][i] = (hs[j][i - 1] * m[j] + s[i] - 'a' + 1) % base[j];
        }
    }
    for(int l = 1;l <= (n >> 1);++l){
        int r = n - l + 1;
        if(ok(l,r)){
            minimize(ans,(r - l > 1 ? 2 : 1));
        }
    }
    if(ans == N)
        cout<<"Impossible";
    else
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
