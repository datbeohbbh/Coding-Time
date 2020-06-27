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

    const int N = 2e5 + 5;
    vector <int> adj[N];
    int n,m,p = 0;
    int child[N],bigChild[N];
    int head[N],chain[N];
    int pos[N],dad[N];
    int chainIndex = 0;

    class FenwickTree{
    public:
        int treeSize;
        vector <int> tree;
        vector <int> changes;
    public:
        FenwickTree(int szt){
            this -> treeSize = szt;
            tree.resize(szt + 3,0);
        }
        void clr(){
            for(int i = 0;i < len(changes);++i){
                tree[changes[i]] = 0;
            }
            changes.clear();
        }
        void updateNode(int node,int value){
            for(;node <= treeSize;node += node & (-node)){
                tree[node] += value;
                changes.emplace_back(node);
            }
        }
        int rsq(int node){
            if(!node){
                return 0;
            }
            int ret = 0;
            for(;node > 0;node -= node &(-node)){
                ret += tree[node];
            }
            return ret;
        }
        int rsq(int l,int r){
            return rsq(r) - rsq(l - 1);
        }
    }*fenw;

    void dfs(int u,int par){
        child[u] = 1;
        bigChild[u] = -1;
        for(int v : adj[u]){
            if(v == par){
                continue;
            }
            dad[v] = u;
            dfs(v,u);
            child[u] += child[v];
            if(bigChild[u] == -1 or child[v] > child[bigChild[u]]){
                bigChild[u] = v;
            }
        }
    }

    void hld(int u,int par){
        if(!head[chainIndex]){
            head[chainIndex] = u;
        }
        pos[u] = ++p;
        chain[u] = chainIndex;
        if(~bigChild[u]){
            hld(bigChild[u],u);
        }
        for(int v : adj[u]){
            if(v == par or v == bigChild[u]){
                continue;
            }
            ++chainIndex;
            hld(v,u);
        }
    }

    int calc(int u){
        int ret = 0;
        while(true){
            if(!chain[u]){
                ret += fenw -> rsq(pos[1],pos[u]);
                break;
            }
            ret += fenw -> rsq(pos[head[chain[u]]],pos[u]);
            u = dad[head[chain[u]]];
        }
        return ret;
    }

    void solve(){
        cin>>n>>m;
        for(int i = 1;i < n;++i){
            int u,v;
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1,1);
        hld(1,1);
        fenw = new FenwickTree(n);
        while(m--){
            int k;
            fenw -> clr();
            cin>>k;
            vector <int> v(k + 2);
            for(int i = 1;i <= k;++i){
                cin>>v[i];
                int u = (v[i] == 1 ? 1 : dad[v[i]]);
                fenw -> updateNode(pos[u],1);
            }
            bool ok = false;
            for(int i = 1;i <= k;++i){
                if(calc(v[i]) == k){
                     ok = true;
                     break;
                }
            }
            cout<<(ok ? "YES\n" : "NO\n");
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
