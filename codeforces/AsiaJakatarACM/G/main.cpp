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
    const int inf = -2e9;
    int n,m,q;
    ordered_set <int> R[N];
    int a[N];
    int p[N];

    class SegmenTree{
    public:
        vector <int> tree;
        vector <int> lazy;
        SegmenTree(){
            tree.resize(N << 2,0);
            lazy.resize(N << 2,0);
        }
        void pushdown(int l,int r,int node){
            if(!lazy[node]){
                return ;
            }
            tree[node] += lazy[node];
            if(l ^ r){
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        void update(int pos,int l,int r,int val,int node = 1){
            if(l > r or r < pos or l > pos){
                return ;
            }
            if(l == r){
                return (void)(tree[node] = val);
            }
            int mid = (l + r) >> 1;
            if(pos <= mid){
                update(pos,l,mid,val,node << 1);
            } else {
                update(pos,mid + 1,r,val,node << 1 | 1);
            }
            tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
        }
        void updateRange(int tl,int tr,int l,int r,int val,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return ;
            }
            if(tl <= l and r <= tr){
                tree[node] += val;
                if(l ^ r){
                    lazy[node << 1] += val;
                    lazy[node << 1 | 1]+= val;
                }
                return ;
            }
            int mid = (l + r) >> 1;
            updateRange(tl,tr,l,mid,val,node << 1);
            updateRange(tl,tr,mid + 1,r,val,node << 1 | 1);
            tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
        }
        int rmq(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return inf;
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return max(rmq(tl,tr,l,mid,node << 1),rmq(tl,tr,mid + 1,r,node << 1 | 1));
        }
    };
    SegmenTree seg;

    void solve(){
        cin>>n>>m>>q;
        ordered_set <int> ost;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            ost.insert(a[i]);
        }
        p[0] = n - ost.order_of_key(a[1]);
        vector <vector <int> > vec(m + 1,vector <int>());
        for(int i = 1;i <= m;++i){
            int len;
            cin>>len;
            for(int j = 1;j <= len;++j){
                int val;
                cin>>val;
                R[i].insert(val);
                vec[i].emp(val);
            }
            p[i] = len - R[i].order_of_key(a[1]);
        }
        for(int i = 1;i <= m;++i){
            p[i] += p[i - 1];
        }
        for(int i = 0;i <= m;++i){
            seg.update(i,0,m,sz(R[i + 1]) + p[i]);
        }
        while(q--){
            int x,y,z;
            cin>>x>>y>>z;
            int old_value = sz(R[x]) - R[x].order_of_key(a[1]);
            R[x].erase(vec[x][y - 1]);
            vec[x][y - 1] = z;
            R[x].insert(z);
            int new_value = sz(R[x]) - R[x].order_of_key(a[1]);
            seg.updateRange(x,m,0,m,-(old_value - new_value));
            cout<<(seg.rmq(0,m,0,m) > n ? "0\n" : "1\n");
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