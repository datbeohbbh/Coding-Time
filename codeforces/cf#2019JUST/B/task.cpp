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

const int N = 1e5 + 5;
int occ[N];
int T,n,m,q;

struct FenwickTree{
    vector <int> ft;
    void clr(){
        ft.assign(N,0);
    }
    void update(int node,int val){
        for(;node > 0;node -= node & (-node)){
            maximize(ft[node],val);
        }
    }
    int rmq(int node){
        int ret = 0;
        for(;node <= N - 5;node += node & (-node)){
            maximize(ret,ft[node]);
        }
        return ret;
    }
}fen;

void solve()
{
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        fen.clr();
        for(int i = 1;i <= n;++i){
            int l,r;
            cin>>l>>r;
            ++occ[l];
            --occ[r + 1];
        }
        for(int i = 2;i <= m;++i){
            occ[i] += occ[i - 1];
        }
        occ[0] = -1;
        int f = 0;
        for(int i = m;i >= 0;--i){
            if(!occ[i]){
                if(!f){
                    f = i;
                }
            } else {
                if(f){
                    fen.update(f - i,f);
                    f = 0;
                }
            }
        }
        int ans = 0;
        while(q--){
            int k;
            cin>>k;
            ans = fen.rmq(k);
            if(!ans){
                cout<<-1<<' '<<-1<<'\n';
            } else {
                cout<<ans - k + 1<<' '<<ans<<'\n';
            }
        }
        memset(occ,0,sizeof(occ));
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
