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

    const ll base[] = {1000000007,1000000087};
    const int N = 1e5 + 2;
    const int aux = 1e4;
    int n,len;
    pll hs[N],rev_hs[N];
    int a[N];
    bool match[N];
    vector <int> f[aux << 1 | 1];
    map <pll,set <pii> > hashCode;
    ll ans = 0;

    void del(int pos){
        match[pos] = true;
        (hashCode[hs[pos]]).erase(make_pair(a[pos],pos));
    }

    pll computeHash(const string &tmp){
        pll h(0,0);
        for(int i = 0;i < len;++i){
            h.first = (h.first * 29LL + tmp[i] - 'a' + 1) % base[0];
            h.second = (h.second * 31LL + tmp[i] - 'a' + 1) % base[1];
        }
        return h;
    }

    void solve(){
        cin>>n>>len;
        for(int i = 1;i <= n;++i){
            string s;
            cin>>s>>a[i];
            a[i] += aux;
            f[a[i]].emplace_back(i);
            hs[i] = computeHash(s);
            reverse(all(s));
            rev_hs[i] = computeHash(s);
            (hashCode[hs[i]]).insert(make_pair(a[i],i));
        }
        vector <pii> ve;
        for(int val = (aux << 1);~val;--val){
            for(int pos : f[val]){
                if(match[pos])continue;
                set <pii> &heap = hashCode[rev_hs[pos]];
                if(!heap.empty() and heap.rbegin() -> second == pos){
                    heap.erase(*heap.rbegin());
                }
                if(!heap.empty()){
                    pii top = *heap.rbegin();
                    heap.erase(top);
                    int u = val + top.first - (aux << 1);
                    if(u > 0){
                        ans += 1LL*u;
                        del(pos);
                        del(top.second);
                        ve.emplace_back(make_pair(pos,top.second));
                    }
                }
            }
        }
        ll tmp = ans;
        for(pii p : ve){
            int i = p.first;
            int j = p.second;
            if(i == j)continue;
            if(hs[i] == rev_hs[i]){
                maximize(tmp,ans - (a[i] + a[j] - (aux << 1)) + (a[i] - aux));
            }
        }
        int add = 0;
        for(int i = 1;i <= n;++i){
            if(!match[i] and hs[i] == rev_hs[i]){
                maximize(add,a[i] - aux);
            }
        }
        ans = max(ans + add,tmp);
        cout<<ans;
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