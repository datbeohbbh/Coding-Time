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
    const ll base = 1e9 + 7;
    int n,q;
    string s;

    class Node {
    public:
        int mat[2][2];
        Node(){
            mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0;
        }
        void setNode(int cur){
            if(!cur){
                mat[0][0] = mat[1][0] = mat[1][1] = 1;
                mat[0][1] = 0;
            } else {
                mat[0][0] = mat[0][1] = mat[1][1] = 1;
                mat[1][0] = 0;
            }
        }
        void trans(){
            swap(mat[0][0],mat[0][1]);
            swap(mat[1][0],mat[1][1]);
            swap(mat[0][0],mat[1][0]);
            swap(mat[0][1],mat[1][1]);
        }
        Node operator * (const Node &other){
            Node ret;
            for(int i = 0;i < 2;++i){
                for(int j = 0;j < 2;++j){
                    for(int k = 0;k < 2;++k){
                        ret.mat[i][j] = addmod(ret.mat[i][j],mul(mat[i][k],other.mat[k][j],base),base);
                    }
                }
            }
            return ret;
        }
    };

    class SegmenTree{
        vector <Node> tree;
        vector <bool> lazy;
    public:
        SegmenTree(){
            tree.resize((N << 2),Node());
            lazy.resize((N << 2),false);
        }
        void build(int l,int r,int node = 1){
            if(l > r){
                return ;
            }
            if(l == r){
                tree[node].setNode((s[l] == 'A' ? 0 : 1));
                return ;
            }
            int mid = (l + r) >> 1;
            build(l,mid,node << 1);
            build(mid + 1,r,node << 1 | 1);
            tree[node] = tree[node << 1] * tree[node << 1 | 1];
        }
        void pushdown(int l,int r,int node){
            if(!lazy[node]){
                return ;
            }
            tree[node].trans();
            if(l ^ r){
                lazy[node << 1] = lazy[node << 1] ^ lazy[node];
                lazy[node << 1 | 1] = lazy[node << 1 | 1] ^ lazy[node];
            }
            lazy[node] = 0;
        }
        void update(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return;
            }
            if(tl <= l and r <= tr){
                tree[node].trans();
                if(l ^ r){
                    lazy[node << 1] = lazy[node << 1] ^ 1;
                    lazy[node << 1 | 1] = lazy[node << 1 | 1] ^ 1;
                }
                return ;
            }
            int mid = (l + r) >> 1;
            update(tl,tr,l,mid,node << 1);
            update(tl,tr,mid + 1,r,node << 1 | 1);
            tree[node] = tree[node << 1] * tree[node << 1 | 1];
        }
        Node query(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                Node ret = Node();
                ret.mat[0][0] = ret.mat[1][1] = 1;
                return ret;
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return query(tl,tr,l,mid,node << 1) * query(tl,tr,mid + 1,r,node << 1 | 1);
        }
    };
    SegmenTree seg;

    void solve(){
        cin>>n>>q>>s;
        s = " " + s;
        seg.build(1,n);
        while(q--){
            int type,l,r;
            ll a,b;
            cin>>type>>l>>r; --type;
            if(!type){
                seg.update(l,r,1,n);
            } else {
                cin>>a>>b;
                Node t = seg.query(l,r,1,n);
                ll ans_a = addmod(mul(a,t.mat[0][0],base),mul(b,t.mat[1][0],base),base);
                ll ans_b = addmod(mul(a,t.mat[0][1],base),mul(b,t.mat[1][1],base),base);
                cout<<ans_a<<' '<<ans_b<<'\n';
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