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
 
    const int inf = 1e9;
    const int N = 2e5 + 2;
    int n,m;
    int a[N];
 
    struct SegmentTree{
        vector <pii> tree;
        void initSegmentTree(int size_tree){
            tree.resize((size_tree<<2) + 2,mp(inf,inf));
        }
 
        void updateNode(int pos,pii val,int l = 1,int r = n,int node = 1){
            if(l > r or r < pos or l > pos)return ;
            if(l == r){
                return (void)(tree[node] = val);
            }
            int mid = (l + r) >> 1;
            if(pos <= mid){
                updateNode(pos,val,l,mid,node<<1);
            } else {
                updateNode(pos,val,mid + 1,r,node<<1|1);
            }
            tree[node] = min(tree[node<<1],tree[node<<1|1]);
        }
 
        pii getRMQ(int tl,int tr,int l = 1,int r = n,int node = 1){
            if(l > r or r < tl or l > tr)return mp(inf,inf);
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return min(getRMQ(tl,tr,l,mid,node<<1),getRMQ(tl,tr,mid + 1,r,node<<1|1));
        }
    };
    SegmentTree segTree[9];
 
    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        vector <int> pw;
        pw.emp(1);
        for(int i = 1;i < 10;++i){
            pw.emp(pw[i - 1] * 10);
        }
        for(int i = 0;i < 9;++i){
            segTree[i].initSegmentTree(n);
            for(int j = 1;j <= n;++j){
                int dig = ((a[j] % pw[i + 1]) / pw[i]);
                if(!(a[j] / pw[i + 1]) and !dig){
                    continue;
                } else if(dig){
                    segTree[i].updateNode(j,mp(a[j],j));
                }
            }
        }
        while(m--){
            int type,l,r;
            cin>>type>>l>>r; --type;
            if(type){
                int ans = inf + inf;
                for(int i = 0;i < 9;++i){
                    pii x = segTree[i].getRMQ(l,r);
                    if(x != mp(inf,inf)){
                            pii y = segTree[i].getRMQ(x.sec + 1,r);
                            pii z = segTree[i].getRMQ(l,x.sec - 1);
                            if(y != mp(inf,inf)){
                                minimize(ans,x.fir + y.fir);
                            }
                            if(z != mp(inf,inf)){
                                minimize(ans,x.fir + z.fir);
                            }
 
                    }
                }
                cout<<(ans == inf + inf ? -1 : ans)<<'\n';
            } else {
                for(int i = 0;i < 9;++i){
                    int dig = ((a[l] % pw[i + 1]) / pw[i]);
                    if(!(a[l] / pw[i + 1]) and !dig)break;
                    segTree[i].updateNode(l,mp(inf,inf));
                }
                a[l] = r;
                for(int i = 0;i < 9;++i){
                    int dig = ((a[l] % pw[i + 1]) / pw[i]);
                    if(!(a[l] / pw[i + 1]) and !dig)break;
                    segTree[i].updateNode(l,mp(dig ? a[l] : inf,dig ? l : inf));
                }
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