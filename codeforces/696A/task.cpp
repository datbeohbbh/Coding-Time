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

int q;
map <pll,ll> fee;
map <ll,bool> lca;
ll ans = 0;

ll f(ll node){
    node-=(node & 1LL);
    node>>=1LL;
    return node;
}

void up(ll node){
    while(node > 0){
        lca[node] = true;
        node-=(node & 1LL);
        node>>=1LL;
    }
}

ll findlca(ll node){
    while(!lca[node]){
        node-=(node & 1LL);
        node>>=1LL;
    }
    return node;
}

void upd(ll node,ll _lca,ll w){
    if(node == _lca)
      return ;
    while(true){
        fee[mp(node,f(node))]+=w;
        node = f(node);
        if(node == _lca)
          break;
    }
}

ll calc(ll node,ll _lca){
    if(node == _lca)
      return 0;
    ll ret = 0;
    while(true){
        ret+=fee[mp(node,f(node))];
        node = f(node);
        if(node == _lca)
          break;
    }
    return ret;
}

void solve()
{
    cin>>q;
    for(int i = 1;i <= q;++i){
        int op;
        ll l,r,w;
        cin>>op>>l>>r;
        if(op == 1)cin>>w;
        lca.clear();
        up(l);
        ll _lca = findlca(r);
        if(op == 1){
            upd(l,_lca,w);
            upd(r,_lca,w);
        }
        else {
            ans = 0;
            ans += calc(l,_lca) + calc(r,_lca);
            cout<<ans<<'\n';
        }
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
