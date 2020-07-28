#include <bits/stdc++.h>

using namespace std;

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

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    int n,q;

    class Node{
    public:
        int z,o,t;
    public:
        Node(int z,int o,int t){
            this -> z = z;
            this -> o = o;
            this -> t = t;
        }
        void shift(){
            int tmp = t;
            t = o,o = z,z = tmp;
        }
        Node operator + (const Node &other){
            return Node(z + other.z,o + other.o,t + other.t);
        }
    };

    class SegmentTree{
    public:
        vector <Node> tree;
        vector <int> lz;
    public:
        SegmentTree(int sz){
            tree.resize((sz << 2) + 10,Node(0,0,0));
            lz.resize((sz << 2) + 10,0);
        }
        void buildTree(int l,int r,int node = 1){
            if(l > r){
                return ;
            }
            if(l == r){
                tree[node] = Node(1,0,0);
                return ;
            }
            int mid = (l + r) >> 1;
            buildTree(l,mid,node << 1);
            buildTree(mid + 1,r,node << 1 | 1);
            tree[node] = tree[node << 1] + tree[node << 1 | 1];
        }
        void pushdown(int l,int r,int node){
            if(!lz[node]){
                return ;
            }
            for(int i = 1;i <= lz[node] % 3;++i){
                tree[node].shift();
            }
            if(l ^ r) {
                lz[node << 1] += lz[node];
                lz[node << 1 | 1] += lz[node];
            }
            lz[node] = 0;
        }

        void update(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return ;
            }
            if(tl <= l and r <= tr){
                tree[node].shift();
                if(l ^ r){
                    lz[node << 1] += 1;
                    lz[node << 1 | 1] += 1;
                }
                return ;
            }
            int mid = (l + r) >> 1;
            update(tl,tr,l,mid,node << 1);
            update(tl,tr,mid + 1,r,node << 1 | 1);
            tree[node] = tree[node << 1] + tree[node << 1 | 1];
        }

        int calc(int tl,int tr,int l,int r,int node = 1){
            pushdown(l,r,node);
            if(l > r or r < tl or l > tr){
                return 0;
            }
            if(tl <= l and r <= tr){
                return tree[node].z;
            }
            int mid = (l + r) >> 1;
            int ll = calc(tl,tr,l,mid,node << 1);
            int rr = calc(tl,tr,mid + 1,r,node << 1 | 1);
            return ll + rr;
        }
    };

    void solve(){
        cin>>n>>q;
        SegmentTree *seg = new SegmentTree(n);
        seg -> buildTree(1,n);
        while(q--){
            int op,l,r;
            cin>>op>>l>>r;
            ++l,++r;
            if(!op){
                seg -> update(l,r,1,n);
            } else {
                cout<<seg -> calc(l,r,1,n)<<'\n';
            }
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
