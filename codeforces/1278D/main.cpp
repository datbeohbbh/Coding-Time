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

    int n;
    vector <int> *g;
    int *l,*r,*par;

    int findp(int u){
        return par[u] == u ? u : par[u] = findp(par[u]);
    }

    void join(int u,int v){
        par[findp(u)] = findp(v);
    }

    void solve(){
        cin>>n;
        g = new vector <int>[n + 1];
        par = new int[n + 1];
        l = new int[n + 1];
        r = new int[n + 1];
        for(int i = 1;i <= n;++i){
            cin>>l[i]>>r[i];
            par[i] = i;
        }
        vector <pii> vec;
        for(int i = 1;i <= n;++i){
            vec.emplace_back(make_pair(l[i],i));
            vec.emplace_back(make_pair(r[i],i));
        }
        sort(all(vec));
        set <pii> cur;
        int E = 0;
        for(pii p : vec){
            if(E >= n){
                break;
            }
            else if(cur.count(p)){
                cur.erase(p);
            } else {
                for(pii it : cur){
                    if(r[it.second] > r[p.second]){
                        break;
                    }
                    join(it.second,p.second);
                    ++E;
                    if(E >= n){
                        break;
                    }
                }
                cur.insert(make_pair(r[p.second],p.second));
            }
        }
        int com = 0;
        for(int i = 1;i <= n;++i){
            if(i == findp(i)){
                ++com;
            }
        }
        cout<<(E == n - 1 and com == 1 ? "YES" : "NO");
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