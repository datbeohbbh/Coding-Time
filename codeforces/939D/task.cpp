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

int par[30],mark[30];
int n;
string s,t;
vector <pair <char,char> > ans;
vector <int> lab[30];

int findp(int u){
    return (u == par[u] ? u : findp(par[u]));
}

void join(int u,int v){
    u = findp(u),v = findp(v);
    if(u == v)return ;
    if(sz(lab[u]) < sz(lab[v]))swap(u,v);
    lab[u].insert(lab[u].end(),all(lab[v]));
    lab[v].clear();
    par[v] = u;
}

void solve()
{
    cin>>n>>s>>t;
    for(int i = 0;i < 26;++i){
        lab[i].pb(i);
        par[i] = i;
    }
    for(int i = 0;i < n;++i){
        mark[s[i] - 'a'] = mark[t[i] - 'a'] = true;
    }
    for(int i = 0;i < n;++i){
        join(s[i] - 'a',t[i] - 'a');
    }
    for(int i = 0;i < 26;++i){
        if(mark[i] and par[i] == i){
            for(int j = 1;j < sz(lab[i]);++j){
                ans.pb(mp((char)(lab[i][j] + 'a'),(char)(lab[i][j - 1] + 'a')));
            }
        }
    }
    cout<<sz(ans)<<'\n';
    for(auto res : ans){
        cout<<res.fir<<' '<<res.sec<<'\n';
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
