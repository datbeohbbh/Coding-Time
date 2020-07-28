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

#define ll int
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

vector <pll> pw,hs[2];
vector <int> p;
string s,revs;
int n;
ll ans = 0;

pll gethash(int l,int r,int f){
    ll hs1 = (hs[f][r].fir - hs[f][l - 1].fir * pw[r - l + 1].fir);
    ll hs2 = (hs[f][r].sec - hs[f][l - 1].sec * pw[r - l + 1].sec);
    return mp(hs1,hs2);
}

void solve()
{
    cin>>s;
    revs = s;
    reverse(all(revs));
    n = sz(s);
    s = " " + s;
    revs = " " + revs;
    p.resize(n + 2,0);
    pw.resize(n + 2,mp(0,0));
    hs[0].resize(n + 2,mp(0,0));
    hs[1].resize(n + 2,mp(0,0));
    pw[0] = mp(1,1);
    for(int i = 1;i <= n;++i){
        pw[i].fir = pw[i - 1].fir*67;
        pw[i].sec = pw[i - 1].sec*71;
    }
    for(int i = 1;i <= n;++i){
        hs[0][i].fir = (hs[0][i - 1].fir * 67 + s[i] - '0' + 1) ;
        hs[0][i].sec = (hs[0][i - 1].sec * 71 + s[i] - '0' + 1);
        hs[1][i].fir = (hs[1][i - 1].fir * 67 + revs[i] - '0' + 1);
        hs[1][i].sec = (hs[1][i - 1].sec * 71 + revs[i] - '0' + 1);
    }
    for(int i = 1;i <= n;++i){
      p[i] = (gethash(1,i,0) == gethash(n - i + 1,n,1) ? p[i >> 1] + 1 : 0);
      ans += 1LL*p[i];
    }
    cout<<ans<<'\n';
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
//    ofstream inp("test.inp");
//    for(int i = 1;i <= 5e6;++i)
//      inp<<"3";
    task::solve();
}
