#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x = y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x = y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    int n,m,q;
    int par[N],opp[N];
    map <string,int> g;

    int findp(int u){
        return (u == par[u] ? u : par[u] = findp(par[u]));
    }

    void join(int u,int v){
        par[findp(u)] = findp(v);
    }

    bool chk(int type,int u,int v){
        if(type == 1){
            if(findp(opp[findp(u)]) and findp(opp[findp(u)]) == findp(v)){
                return false;
            } else if(findp(opp[findp(v)]) and findp(opp[findp(v)]) == findp(u)){
                return false;
            } else {
                return true;
            }
        } else {
            return (findp(u) == findp(v) ? false : true);
        }
    }

    void makeLink(int type,int u,int v){
        if(type == 1){
            if(findp(opp[findp(u)]) and findp(opp[findp(v)]) ){
                join(findp(opp[findp(u)]),findp(opp[findp(v)]));
                int tmp = findp(opp[findp(u)]);
                join(u,v);
                opp[findp(u)] = tmp;
            } else {
                if(findp(opp[findp(u)])){
                    int tmp = findp(opp[findp(u)]);
                    join(u,v);
                    opp[findp(u)] = tmp;
                } else if(findp(opp[findp(v)])){
                    int tmp = findp(opp[findp(v)]);
                    join(u,v);
                    opp[findp(u)] = tmp;
                } else {
                    join(u,v);
                }
            }
        } else {
            if(opp[findp(u)]){
                join(findp(opp[findp(u)]),findp(v));
            }
            if(opp[findp(v)]){
                join(findp(opp[findp(v)]),findp(u));
            }
            opp[findp(u)] = findp(v);
            opp[findp(v)] = findp(u);
        }
    }

    void solve(){
        cin>>n>>m>>q;
        for(int i = 1;i <= n;++i){
            string s;
            cin>>s;
            g[s] = i;
        }
        for(int i = 1;i <= n;++i){
            par[i] = i;
        }
        for(int i = 1;i <= m;++i){
            string x,y;
            int type;
            cin>>type>>x>>y;
            int u = g[x];
            int v = g[y];
            if(!chk(type,u,v)){
                cout<<"NO\n";
            } else {
                cout<<"YES\n";
                makeLink(type,u,v);;
            }
        }
        while(q--){
            string x,y;
            cin>>x>>y;
            int u = g[x];
            int v = g[y];
            if(!chk(2,u,v)){
                cout<<1<<'\n';
            } else if(!chk(1,u,v)){
                cout<<2<<'\n';
            } else {
                cout<<3<<'\n';
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}