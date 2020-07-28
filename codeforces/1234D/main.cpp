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
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
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
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    string s;
    int n,q;

    struct FenwickTree{
        vector <int> ft;
        FenwickTree(){
            ft.resize(N + 1,0);
        }
        void update(int node,int val){
            for(;node < N;node += node & (-node)){
                ft[node] += val;
            }
        }
        int rsq(int node){
            int res = 0;
            for(;node > 0;node -= node & (-node)){
                res += ft[node];
            }
            return res;
        }
        int rsq(int l,int r){
            return rsq(r) - rsq(l - 1);
        }
    }fen[26];

    void solve(){
        cin>>s;
        n = sz(s);
        s = " " + s;
        for(int i = 1;i <= n;++i){
            fen[s[i] - 'a'].update(i,1);
        }
        cin>>q;
        while(q--){
            int type,l,r,pos;
            char c;
            cin>>type; --type;
            if(!type){
                cin>>pos>>c;
                fen[s[pos] - 'a'].update(pos,-1);
                fen[c - 'a'].update(pos,1);
                s[pos] = c;
            } else {
                int ans = 0;
                cin>>l>>r;
                for(int i = 0;i < 26;++i){
                    ans += fen[i].rsq(l,r) > 0;
                }
                cout<<ans<<'\n';
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