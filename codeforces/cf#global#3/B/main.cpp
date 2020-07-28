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

    const  int N = 2e5 + 5;
    int a[N],b[N];
    vector <pair <pii,int> > vec;
    int n,m,ta,tb,k;
    set <int> st[2];

    void solve(){
        cin>>n>>m>>ta>>tb>>k;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            a[i] += ta;
            st[0].insert(i);
        }
        for(int i = 1;i <= m;++i){
            cin>>b[i];
            st[1].insert(i);
        }
        for(int i = 1;i <= n;++i){
            int l = 1,r = m;
            int pos = -1;
            for(int mid = (l + r)>>1;l <= r;mid = (l + r)>>1){
                if(b[mid] >= a[i]){
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            if(~pos){
                vec.pb(mp(mp(i,pos),0));
            }
        }
        for(int i = 1;i <= m;++i){
            int l = 1,r = n;
            int pos = -1;
            for(int mid = (l + r)>>1;l <= r;mid = (l + r)>>1){
                if(a[mid] <= b[i]){
                    l = mid + 1;
                    pos = mid;
                } else {
                    r = mid - 1;
                }
            }
            if(~pos){
                vec.pb(mp(mp(i,pos),1));
            }
        }
        sort(all(vec),[](const pair <pii,int> &x,const pair <pii,int> &y){
            int u = (x.sec == 1 ? x.fir.sec : m - x.fir.sec + 1);
            int v = (y.sec == 1 ? y.fir.sec : m - y.fir.sec + 1);
            return (u < v) or (u == v and x.fir.fir < y.fir.fir);
        });
        for(int i = 0;i < min(sz(vec),k);++i){
            pair <pii,int> x = vec[i];
            if(st[x.sec].find(x.fir.fir) != st[x.sec].end()) {
                st[x . sec] . erase(x . fir . fir);
            }
        }
        vector <int> na,nb;
        for(auto x : st[0]){
            na.pb(a[x]);
        }
        for(auto x : st[1]){
            nb.pb(b[x]);
        }
        bool f = false;
        int ans = -1;
        for(int i = 0;i < sz(na);++i){
            auto it = lower_bound(all(nb),na[i]);
            if(it != nb.end()){
                if(!f){
                    f = true;
                    ans = *it + tb;
                }
            }
        }
        cout<<(f ? ans : -1);
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