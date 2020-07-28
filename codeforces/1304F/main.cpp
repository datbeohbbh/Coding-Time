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

    const int N = 55;
    const int M = 2e4 + 4;
    int n,m,k;
    int animals[N][M];
    int sumAnimals[N][M];
    int dp[N][M];

    class SegmentTree{
    public:
        vector < int > tree;
        vector < int > lz;
    public:
        SegmentTree(int sizeTree){
            tree.resize((sizeTree << 2) | 4,0);
            lz.resize((sizeTree << 2) | 4,0);
        }
        void pushDown(int l,int r,int node){
            if(!lz[node]){
                return;
            }
            tree[node] += lz[node];
            if(l ^ r){
                lz[node << 1] += lz[node];
                lz[node << 1 | 1] += lz[node];
            }
            lz[node] = 0;
        }
        void updatePos(int l,int r,int pos,const int *values,int node = 1){
            if(l > r or r < pos or l > pos){
                return;
            }
            if(l == r){
                tree[node] = values[pos];
                return;
            }
            int mid = (l + r) >> 1;
            if(pos <= mid){
                updatePos(l,mid,pos,values,node << 1);
            } else {
                updatePos(mid + 1,r,pos,values,node << 1 | 1);
            }
            tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
        }
        void updateRange(int tl,int tr,int subs,int l,int r,int node = 1){
            pushDown(l,r,node);
            if(l > r or r < tl or l > tr){
                return;
            }
            if(tl <= l and r <= tr){
                tree[node] += subs;
                if(l ^ r){
                    lz[node << 1] += subs;
                    lz[node << 1 | 1] += subs;
                }
                return;
            }
            int mid = (l + r) >> 1;
            updateRange(tl,tr,subs,l,mid,node << 1);
            updateRange(tl,tr,subs,mid + 1,r,node << 1 | 1);
            tree[node] = max(tree[node << 1],tree[node << 1 | 1]);
        }
        int rmq(int tl,int tr,int l,int r,int node = 1){
            pushDown(l,r,node);
            if(l > r or r < tl or l > tr){
                return 0;
            }
            if(tl <= l and r <= tr){
                return tree[node];
            }
            int mid = (l + r) >> 1;
            return max(rmq(tl,tr,l,mid,node << 1),rmq(tl,tr,mid + 1,r,node << 1 | 1));
        }
    };
    SegmentTree* *seg;

    int getSum(int i,int j){
        return sumAnimals[i][j + k - 1] - sumAnimals[i][j - 1] + sumAnimals[i + 1][j + k - 1] - sumAnimals[i + 1][j - 1];
    }

    void upd(SegmentTree *st,int i,int j,int val){
        int u = max(1,j - k + 1);
        int v = min(j,u + k - 1);
        st -> updateRange(u,v,val,1,m);
    }

    void solve(){
        cin>>n>>m>>k;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin>>animals[i][j];
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                sumAnimals[i][j] = sumAnimals[i][j - 1] + animals[i][j];
            }
        }
        seg = new SegmentTree*[n + 2];
        seg[1] = new SegmentTree(m);
        for(int j = 1;j <= m - k + 1;++j){
            dp[1][j] = getSum(1,j);
            seg[1] -> updatePos(1,m,j,dp[1]);
        }
        for(int i = 2;i <= n;++i){
            seg[i] = new SegmentTree(m);
            for(int j = 1;j <= k;++j){
                upd(seg[i - 1],i,j,-animals[i][j]);
            }
            for(int j = 1;j <= m - k + 1;++j){
                int u = max(1,j - k + 1);
                int v = min(m,j + k - 1);
                maximize(dp[i][j],seg[i - 1] -> rmq(u,v,1,m) + getSum(i,j));
                if(u > 1){
                    maximize(dp[i][j],seg[i - 1] -> rmq(1,u - 1,1,m) + getSum(i,j));
                }
                if(v < m){
                    maximize(dp[i][j],seg[i - 1] -> rmq(v + 1,m,1,m) + getSum(i,j));
                }
                upd(seg[i - 1],i,j,animals[i][j]);
                upd(seg[i - 1],i,j + k,-animals[i][j + k]);
            }
            for(int j = 1;j <= m;++j){
                seg[i] -> updatePos(1,m,j,dp[i]);
            }
        }
        cout<<*max_element(dp[n] + 1,dp[n] + 1 + m);
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
