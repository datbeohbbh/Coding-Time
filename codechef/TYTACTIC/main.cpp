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

    const int N = 1e5 + 5;
    int n,m;
    vector <int> adj[N];
    int in[N],out[N],a[N];

    class FenwickTree{
    public:
        vector <int> tree;
        int num_node;
    public:
        FenwickTree(int num_node){
            this -> num_node = num_node;
            tree.resize(num_node + 5,0);
        }
        int rsq(int node){
            if(node <= 0){
                return 0;
            }
            int ret = 0;
            for(;node > 0;node -= node & (-node)){
                ret += tree[node];
            }
            return ret;
        }
        int rsq(int l,int r){
            return rsq(r) - rsq(l - 1);
        }
        void update(int node,int val){
            for(;node <= num_node;node += node & (-node)){
                tree[node] += val;
            }
        }
    };

    int time = 0;
    void dfs(int u,int par){
        in[u] = ++time;
        for(int v : adj[u]){
            if(v ^ par){
                dfs(v,u);
            }
        }
        out[u] = time;
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1,1);
        FenwickTree *fwt = new FenwickTree(n);
        for(int i = 1;i <= n;++i){
            fwt -> update(in[i],a[i]);
        }
        while(m--){
            char type;
            int s,x;
            cin>>type>>s;
            if(type == 'Q'){
                cout<<fwt -> rsq(in[s],out[s])<<'\n';
            } else {
                cin>>x;
                fwt -> update(in[s],-a[s]);
                fwt -> update(in[s],a[s] = x);
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
