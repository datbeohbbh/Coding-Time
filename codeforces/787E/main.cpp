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
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    int nxt[N],t[N];
    int a[N];
    int n;

    typedef class PersistentSegmentTree {
    public:
        PersistentSegmentTree *left,*right;
        int cnt;
    public:
        PersistentSegmentTree(int _cnt):cnt(_cnt),left(nullptr),right(nullptr){}
        PersistentSegmentTree(PersistentSegmentTree *_left,PersistentSegmentTree *_right):left(_left),right(_right),cnt(0){
            if(_left)cnt += _left -> cnt;
            if(_right)cnt += _right -> cnt;
        }
        PersistentSegmentTree* build(int,int);
        PersistentSegmentTree* updateNode(PersistentSegmentTree*,int,int,int);
        int rsq(PersistentSegmentTree*,PersistentSegmentTree*,int,int,int,int);
    }pst;

    pst* pst::build(int l,int r){
        if(l == r){
            return new PersistentSegmentTree(0);
        }
        int mid = (l + r) >> 1;
        return new PersistentSegmentTree(build(l,mid),build(mid + 1,r));
    }

    pst* pst::updateNode(pst* cur,int pos,int l,int r){
        if(l > r or r < pos or l > pos){
            return nullptr;
        }
        if(l == r){
            return new PersistentSegmentTree(cur -> cnt + 1);
        }
        int mid = (l + r) >> 1;
        if(pos <= mid){
            return new PersistentSegmentTree(updateNode(cur -> left,pos,l,mid),cur -> right);
        } else {
            return new PersistentSegmentTree(cur -> left,updateNode(cur -> right,pos,mid + 1,r));
        }
    }

    int pst::rsq(pst* le,pst* ri,int tl,int tr,int l,int r){
        if(l > r or r < tl or l > tr){
            return 0;
        }
        if(tl <= l and r <= tr){
            return ri -> cnt - le -> cnt;
        }
        int mid = (l + r) >> 1;
        int x = rsq(le -> left,ri -> left,tl,tr,l,mid);
         int y = rsq(le -> right,ri -> right,tl,tr,mid + 1,r);
        return x + y;
    }

    pst* *root;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = n;i >= 1;--i){
            if(!t[a[i]]){
                t[a[i]] = i;
                nxt[i] = n + 1;
            } else {
                nxt[i] = t[a[i]];
                t[a[i]] = i;
            }
        }
        int len = n + 1;
        root = new pst* [n + 1];
        pst *ans = new PersistentSegmentTree(0);
        root[0] = root[0] -> build(1,len);
        for(int i = 1;i <= n;++i){
            root[i] = root[i] -> updateNode(root[i - 1],nxt[i],1,len);
        }
        for(int k = 1;k <= n;++k){
            int groups = 0;
            for(int i = 1;i <= n;++i){
                int l = i + k - 1,r = n;
                int f = i + k - 1;
                for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                    int c = mid - i + 1 - ans -> rsq(root[i - 1],root[mid],1,mid,1,len);
                    if(c <= k){
                        f = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                i = f;
                ++groups;
            }
            cout<<groups<<' ';
        }
    }}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
#endif // ONLINE_JUDGE
    task::solve();
}
