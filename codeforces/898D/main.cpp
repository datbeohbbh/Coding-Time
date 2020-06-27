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

    const int M = 1e6 + 1;
    const int N = 2e5 + 5;
    int n,m,k;
    int a[N];
    int cnt[M + 2];
    int f[M + 2];
    bool has[M + 2];
    vector <pii> ve;
    vector <int> g;

    struct SegmentTree{
        vector <int> tree;
        vector <int> lazy;
        SegmentTree(){
            tree.resize((M << 2) + 2,-(M << 1));
            lazy.resize((M << 2) + 2,0);
        }
        void pushdown(int l,int r,int node){
            if(!lazy[node])return ;
            tree[node] += lazy[node];
            if(l ^ r){
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        void updateNode(int pos,int l = 0,int r = M,int node = 1){
            if(r < pos or l > pos or l > r){
                return ;
            }
            if(l == r){
                tree[node] = ve[pos].second;
                return ;
            }
            int mid = (l + r) >> 1;
            if(pos <= mid){
                updateNode(pos,l,mid,node << 1);
            } else {
                updateNode(pos,mid + 1,r,node << 1 | 1);
            }
            tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
        }
        void updateRange(int tl,int tr,int val,int l = 0,int r = M,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return ;
            }
            if(tl <= l and r <= tr){
                tree[node] += val;
                if(l ^ r){
                    lazy[node << 1] += val;
                    lazy[node << 1 | 1] += val;
                }
                return;
            }
            int mid = (l + r) >> 1;
            updateRange(tl,tr,val,l,mid,node << 1);
            updateRange(tl,tr,val,mid + 1,r,node << 1 | 1);
            tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
        }
        int rmq(int tl,int tr,int l = 0,int r = M,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return -(M << 1);
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return max(rmq(tl,tr,l,mid,node << 1),rmq(tl,tr,mid + 1,r,node << 1 | 1));
        }
    };
    SegmentTree *seg;

    int find_left(int x){
        int l = 0,r = sz(ve) - 1;
        int pos = -1;
        for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(x <= ve[mid].first){
                r = mid - 1;
                pos = mid;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    }

    int find_right(int x){
        int l = 0,r = sz(ve) - 1;
        int pos = -1;
        for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
            if(ve[mid].first <= x){
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        return pos;
    }

    void solve(){
        cin>>n>>m>>k;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            cnt[a[i]] = 1;
        }
        for(int i = 1;i <= M;++i){
            cnt[i] += cnt[i - 1];
        }
        for(int i = m;i <= M;++i){
            if(cnt[i] - cnt[i - m] >= k){
                ++f[i - m + 1],--f[i + 1];
                ve.emplace_back(make_pair(i,cnt[i] - cnt[i - m]));
            }
        }
        for(int i = 1;i <= M;++i){
            f[i] += f[i - 1];
        }
        for(int i = 1;i <= n;++i){
            if(f[a[i]] > 0){
                g.emplace_back(a[i]);
            }
        }
        sort(all(g),[](const int &i,const int &j){
            return f[i] > f[j];
        });
        seg = new SegmentTree;
        for(int i = 0;i < sz(ve);++i){
            seg -> updateNode(i);
        }
        int ans = 0;
        for(int i = 0;i < sz(g);++i){
            int x = g[i];
            int l = find_left(x);
            int r = find_right(x + m - 1);
            if(~r) {
                if (seg -> rmq(l, r) >= k) {
                    ++ans;
                    seg -> updateRange(l, r, -1);
                }
            }
        }
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