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
#define BIT(x,i) (((x)>>(i))&1LL)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e6 + 2;
    const int inf = 1e9;
    int a[N];
    ll ans[N];
    int n,w;

    struct SegmentTree{
        vector <int> tree;
        vector <int> lazy;
        SegmentTree(){
            tree.resize((N<<2),0);
            lazy.resize((N<<2),0);
        }

        void pushdown(int l,int r,int node){
            if(!lazy[node])return ;
            tree[node] += (r - l + 1) * lazy[node];
            if(l != r){
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }

        void update(int tl,int tr,int val,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr)return ;
            if(tl <= l and r <= tr){
                tree[node] += (r - l + 1) * val;
                if(l != r){
                    lazy[node<<1] += val;
                    lazy[node<<1|1] += val;
                }
                return ;
            }
            int mid = (l + r) >> 1;
            update(tl,tr,val,l,mid,node<<1);
            update(tl,tr,val,mid + 1,r,node<<1|1);
            tree[node] = tree[node<<1] + tree[node<<1|1];
        }

        int rsq(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr)return 0;
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return rsq(tl,tr,l,mid,node<<1) + rsq(tl,tr,mid + 1,r,node<<1|1);
        }
    }seg;

    int find_left(int l,int r,int len){
        int pos = l - 1;
        int pv = l;
        for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(seg.rsq(pv,mid,1,len) < mid - pv + 1){
                r = mid - 1;
            } else {
                pos = mid;
                l = mid + 1;
            }
        }
        return ++pos;
    }

    int find_right(int l,int r,int len){
        int pos = r + 1;
        int pv = r;
        for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(seg.rsq(mid,pv,1,len) < pv - mid + 1){
                l = mid + 1;
            } else {
                pos = mid;
                r = mid - 1;
            }
        }
        return --pos;
    }

    void calc(int len){
        vector <pii> changes;
        vector <pii> vec;
        for(int i = 1;i <= len;++i){
            vec.emp(mp(a[i],i));
        }
        sort(vec.rbegin(),vec.rend());
        for(int i = 0;i < sz(vec);++i){
            int l = vec[i].sec;
            int r = vec[i].sec + w - len;
            l = find_left(l,r,len);
            r = find_right(l,r,len);
            if(l <= r){
                ans[l] += (r - l + 1 > 1 ? max(1LL*vec[i].fir,0) : 1LL*vec[i].fir);
                ans[r + 1] -= (r - l + 1 > 1 ? max(1LL*vec[i].fir,0) : 1LL*vec[i].fir);
                seg.update(l,r,1,1,len);
                changes.emp(mp(l,r));
            }
        }
        for(int i = 0;i < sz(changes);++i){
            int l = changes[i].fir;
            int r = changes[i].sec;
            seg.update(l,r,-1,1,len);
        }
    }

    void solve(){
        cin>>n>>w;
        for(int i = 1;i <= n;++i){
            int l;
            cin>>l;
            for(int j = 1;j <= l;++j){
                cin>>a[j];
            }
            calc(l);
        }
        for(int i = 1;i <= w;++i){
            ans[i] += ans[i - 1];
        }
        for(int i = 1;i <= w;++i){
            cout<<ans[i]<<' ';
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
