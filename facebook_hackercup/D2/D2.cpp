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
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define fn "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */

// ================================= DEBUG =================================

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rand __rand
mt19937 generator(chrono::system_clock::now().time_since_epoch().count());
template <class T = int>
T rand(T range = numeric_limits <T> :: max()){
    return (T) (generator() % range);
}

// ================================= DEBUG =================================
namespace Task{

    const llong inf = 1e18;
    vector < vector < int > > adj;
    vector < int > par;
    vector < llong > c;
    vector < llong > dp;
    int n,m,a,b;
    
    void clr(){
        adj.clear();
        c.clear();
        dp.clear();
        par.clear();
    }
  
    class SegmentTree{
        public:
            vector < llong > tree;
        public:
            SegmentTree(int size_tree){
                tree.resize((size_tree << 2) | 2,inf);
            }
            
            ~SegmentTree(){
                tree.clear();
            }
            
            void updatePos(int l,int r,int pos,llong val,int node = 1){
                if(l > r or r < pos or l > pos){
                    return;
                }
                if(l == r){
                    minimize(tree[node],val);
                    return;
                }
                int mid = (l + r) >> 1;
                if(pos <= mid){
                    updatePos(l,mid,pos,val,node << 1);
                } else {
                    updatePos(mid + 1,r,pos,val,node << 1 | 1);
                }
                minimize(tree[node],min(tree[node << 1],tree[node << 1 | 1]));
            }
            
            llong rmq(int tl,int tr,int l,int r,int node = 1){
                if(tl > tr or l > r or r < tl or l > tr){
                    return inf;
                }
                if(tl <= l and r <= tr){
                    return tree[node];
                }
                int mid = (l + r) >> 1;
                return min(rmq(tl,tr,l,mid,node << 1),rmq(tl,tr,mid + 1,r,node << 1 | 1));
            }
    };
    
    void dfs(int u,int p){
        for(int v : adj[u]){
            if(v == p){
                continue;
            }
            par[v] = u;
            dfs(v,u);
        }
    }
   
    void calc(int u,int p,int prev,int nxt,int i,SegmentTree *st,int d = 0){
        if(d >= m){
            return;
        }
        if(c[u] > 0){
            int j = max(1,i - d);
            minimize(dp[j],st -> rmq(max(1,i - (m - d)),i - 1,1,n) + (u == b ? 0 : c[u]));
            st -> updatePos(1,n,j,dp[j]);
        }
        for(int v : adj[u]){
            if(v != prev and v != nxt and v != p){
                calc(v,u,prev,nxt,i,st,d + 1);
            }
        }
    }
    
    void compute(){
        cin>>n>>m>>a>>b;
        adj.resize(n + 2,vector < int > ());
        c.resize(n + 2,0);
        par.resize(n + 2,0);
        dp.resize(n + 2,inf);
        for(int i = 1;i <= n;++i){
            int p;
            cin>>p>>c[i];
            if(p){
                adj[i].emplace_back(p);
                adj[p].emplace_back(i);
            }
        }
        dfs(b,b);
        dp[1] = 0;
        SegmentTree *st = new SegmentTree(n + 2);
        st -> updatePos(1,n,1,0);
        int prev = a,nxt = 0,i = 2;
        for(int cur = par[a];cur != 0;cur = nxt,++i){
            nxt = par[cur];
            calc(cur,cur,prev,nxt,i,st);
            prev = cur;
        }
        //debug(i - m - 1,dp[2],dp[3]);
        llong ans = st -> rmq(max(1,i - m - 1),i,1,n);
        cout<<(ans == inf ? -1 : ans)<<'\n';
        clr();
    }
    
    void solve(){
        int T;
        cin>>T;
        for(int tests = 1;tests <= T;++tests){
            cout<<"Case #"<<tests<<": ";
            compute();
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".txt","w",stdout);	
    #endif // ONLINE_JUDGE
    Task::solve();
}

