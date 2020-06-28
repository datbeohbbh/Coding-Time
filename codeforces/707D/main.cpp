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
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    typedef class PersistentSegmentTree{
    public:
        PersistentSegmentTree *left,*right;
        int sum;
        bool lazy;
        PersistentSegmentTree(){}
        PersistentSegmentTree(int sum):sum(sum),lazy(0),left(nullptr),right(nullptr){}
        PersistentSegmentTree(PersistentSegmentTree *_left,PersistentSegmentTree *_right,int _lazy,int _sum){
            left = _left;
            right = _right;
            lazy = _lazy;
            sum = _sum;
        }
    public:
        PersistentSegmentTree* buildTree(int,int);
        PersistentSegmentTree* pushdown(PersistentSegmentTree*,int,int);
        PersistentSegmentTree* modify(PersistentSegmentTree*,int,int,int,int);
        PersistentSegmentTree* invert(PersistentSegmentTree*,int,int,int,int);
    }tree;

    tree* tree::buildTree(int l, int r) {
        if(l == r){
            return new tree(0);
        }
        int mid = (l + r) >> 1;
        tree* le = buildTree(l,mid);
        tree* ri = buildTree(mid + 1,r);
        return new tree(le,ri,0,le -> sum + ri -> sum);
    }

    tree* tree::pushdown(tree *cur,int l,int r){
        if(!cur -> lazy){
            return cur;
        }
        tree *le = cur -> left;
        tree *ri = cur -> right;
        if(l ^ r){
            le = new tree(le -> left,le -> right,le -> lazy ^ 1,le -> sum);
            ri = new tree(ri -> left,ri -> right,ri -> lazy ^ 1,ri -> sum);
        }
        return new tree(le,ri,0,r - l + 1 - cur -> sum);
    }

    tree* tree::modify(tree *cur,int pos,int ret,int l,int r){
        cur = pushdown(cur,l,r);
        if(l == r){
            return new tree (ret);
        }
        int mid = (l + r) >> 1;
        tree *le,*ri;
        if(pos <= mid){
            le = pushdown(modify(cur -> left,pos,ret,l,mid),l,mid);
            ri = pushdown(cur -> right,mid + 1,r);
        } else {
            le = pushdown(cur -> left,l,mid);
            ri = pushdown(modify(cur -> right,pos,ret,mid + 1,r),mid + 1,r);
        }
        return new tree(le,ri,0,le -> sum + ri -> sum);
    }

    tree* tree::invert(tree *cur,int tl,int tr,int l,int r){
        cur = pushdown(cur,l,r);
        if(l > r or r < tl or l > tr){
            return cur;
        }
        if(tl <= l and r <= tr){
            tree *le = cur -> left;
            tree *ri = cur -> right;
            if(l ^ r){
                le = new tree(le -> left,le -> right,le -> lazy ^ 1,le -> sum);
                ri = new tree(ri -> left,ri -> right,ri -> lazy ^ 1,ri -> sum);
            }
            return new tree(le,ri,0,r - l + 1 - cur -> sum);
        }
        int mid = (l + r) >> 1;
        tree *le = pushdown(invert(cur -> left,tl,tr,l,mid),l,mid);
        tree *ri = pushdown(invert(cur -> right,tl,tr,mid + 1,r),mid + 1,r);
        return new tree(le,ri,0,le -> sum + ri -> sum);
    }

    int n,m,q;
    tree* *seg;

    void solve(){
        cin>>n>>m>>q;
        seg = new tree*[q + 1];
        seg[0] = seg[0] -> buildTree(1,n * m);
        auto getPos = [&](const int &i,const int &j){
            return m * (i - 1) + j;
        };
        for(int k = 1;k <= q;++k){
            int type,i,j;
            cin>>type;
            if(type < 4){
                cin>>i;
                --type;
                if(type < 2){
                    cin>>j;
                    seg[k] = seg[k] -> modify(seg[k - 1],getPos(i,j),type ^ 1,1,n * m);
                } else {
                    seg[k] = seg[k] -> invert(seg[k - 1],getPos(i,1),getPos(i,m),1,n * m);
                }
            } else {
                int roll_back;
                cin>>roll_back;
                seg[k] = seg[roll_back];
            }
            cout<<seg[k] -> sum<<'\n';
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}