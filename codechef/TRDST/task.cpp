#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "/home/datbeohbbh/cptemplates/debug.h"
using namespace DEBUG;
#endif

using namespace std;

template <class T,class U>
void maximize(T &lhs,U rhs){
    if(lhs < rhs)lhs = rhs;
}
template <class T,class U>
void minimize(T &lhs,U rhs){
    if(lhs > rhs)lhs = rhs;
}
template <class T>
T tabs(T x){
    return (x < (T)0 ? -x : x);
}

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define file_name "test"    /// FILE NAME HERE!!!

/* ================================= END OF TEMPLATE ================================= */

namespace Task{

    const int N = 1e5 + 5;
    constexpr int maxlg = 34 - __builtin_popcount(N);
    vector < vector < int > > adj;
    vector < vector < int > > dist[2];
    vector < int > k;
    int n;
   
    typedef class CentroidDecomposition{
        public:
            vector < vector < int > > centree;
            vector < vector < int > > origtree;
            vector < int > child;
            vector < bool > del;
            vector < int > dad;
            int root = -1;
            int sizeTree = 0;
        public:
            CentroidDecomposition(const vector < vector < int > > &adj):origtree(adj),sizeTree(len(adj)){
                centree.resize(sizeTree + 1,vector < int > ());
                child.resize(sizeTree + 1,0);
                del.resize(sizeTree + 1,false);
                dad.resize(sizeTree + 1,0);
            }
          
            void computeSize(int u,int par){
                child[u] = 1;
                for(int v : origtree[u]){
                    if(v != par and !del[v]){
                        computeSize(v,u);
                        child[u] += child[v];
                    }
                }
            }
           
            int findCentroid(int u,int par,int szt){
                for(int v : origtree[u]){
                    if(v != par and !del[v]){
                        if((child[v] << 1) > szt){
                            return findCentroid(v,u,szt);
                        }
                    }
                }
                return u;
            }
            
            void decompose(int u,int par){
                computeSize(u,-1);
                int cen = findCentroid(u,-1,child[u]);
                del[cen] = true;
                if(!~root){
                    root = cen;
                }
                dad[cen] = par;
                if(~par){
                    centree[par].emplace_back(cen);
                    centree[cen].emplace_back(par);
                }
                for(int v : origtree[cen]){
                    if(!del[v]){
                        decompose(v,cen);
                    }
                }
            }
            
            void decompose(){
                decompose(1,-1);
            }
    }_Centroid;
    _Centroid *cd;
   
    typedef class LowestCommonAncestor{
        public:
            vector < vector < int > > tree;
            vector < vector < int > > rmq;
            vector < int > h;
            vector < int > st;
            vector < int > euler_tour;
            function < int(int,int) > comp;
            int sizeTree = 0;
        public:
            LowestCommonAncestor(const vector < vector < int > > &adj):tree(adj),sizeTree(len(adj)){
                rmq.resize(maxlg + 2,vector < int > ((sizeTree << 1) + 2,0));
                h.resize(sizeTree + 2,0);
                st.resize(sizeTree + 2,0);
            }
            
            void dfs(int u,int par){
                st[u] = len(euler_tour);
                euler_tour.emplace_back(u);
                for(int v : tree[u]){
                    if(v != par){
                        h[v] = h[u] + 1;
                        dfs(v,u);
                        euler_tour.emplace_back(u);
                    }
                }
            }
           
            int getLca(int u,int v){
                int l = st[u];
                int r = st[v];
                if(l > r){
                    swap(l,r);
                }
                int x = (int)log2(r - l + 1);
                return comp(rmq[x][l],rmq[x][r - MASK(x) + 1]); 
            }
           
            int getDist(int u,int v){
                return h[u] + h[v] - (h[getLca(u,v)] << 1);
            }
            
            void buildLca(const function < int(int,int) > &func){
                for(int i = 0;i < len(euler_tour);++i){
                    rmq[0][i] = euler_tour[i];
                }
                for(int j = 1;j <= maxlg;++j){
                    for(int i = 0;i + MASK(j) - 1 < len(euler_tour);++i){
                        rmq[j][i] = func(rmq[j - 1][i],rmq[j - 1][i + MASK(j - 1)]);
                    }
                }
            }
            
            void buildLca(){
                dfs(1,-1);
                buildLca(comp = [&](int u,int v){return (h[u] <= h[v] ? u : v);});
            }
    }_Lca;
    _Lca *lca;
  
    void goDown(int u,int par,int cur_r,int dad_u){
        dist[0][cur_r].emplace_back(lca -> getDist(u,dad_u));
        dist[1][cur_r].emplace_back(lca -> getDist(u,cur_r));
        //debug(u,cur_r);
        for(int v : cd -> centree[u]){
            if(v != par){
                goDown(v,u,cur_r,dad_u);
            }
        }
    }
    
    void dfs_cen(int u,int par){
        goDown(u,par,u,par);
        sort(dist[0][u].begin(),dist[0][u].end());
        sort(dist[1][u].begin(),dist[1][u].end());
        //debug(u,dist[u]);
        for(int v : cd -> centree[u]){
            if(v != par){
                //debug(u,v);
                dfs_cen(v,u);
            }
        }
    }
   
    int countVertex(int u,int D){
        int ret = 0;
        auto it = upper_bound(dist[1][u].begin(),dist[1][u].end(),D);
        if(it != dist[1][u].end()){
            ret += len(dist[1][u]) - (int)(it - dist[1][u].begin());
        }
        int w = cd -> dad[u];
        int prev = u;
        while(~w){
            auto iter_w = upper_bound(dist[1][w].begin(),dist[1][w].end(),D - lca -> getDist(u,w));
            auto iter_prev = upper_bound(dist[0][prev].begin(),dist[0][prev].end(),D - lca -> getDist(u,w));
            if(iter_w != dist[1][w].end()){
                ret += len(dist[1][w]) - (int)(iter_w - dist[1][w].begin());
            }
            if(iter_prev != dist[0][prev].end()){
                ret -= len(dist[0][prev]) - (int)(iter_prev - dist[0][prev].begin());
            }
            tie(w,prev) = {cd -> dad[w],cd -> dad[prev]};
        }
        return ret;
    }
    
    void solve(){
        cin>>n;
        adj.resize(n + 2,vector < int > ());
        k.resize(n + 2,0);
        for(int i = 1;i <= n;++i){
            cin>>k[i];
        }
        for(int u,v,i = 1;i < n;++i){
            cin>>u>>v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        cd = new CentroidDecomposition(adj); cd -> decompose();
        lca = new LowestCommonAncestor(adj); lca -> buildLca();
        dist[0].resize(n + 1,vector < int > ());
        dist[1].resize(n + 1,vector < int > ());
        dfs_cen(cd -> root,cd -> root);
        for(int u = 1;u <= n;++u){
            int lo = 0,hi = n - 1;
            int ans = -1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(countVertex(u,mid) >= k[u]){
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cout<<ans<<' ';
        }
    }
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(file_name".inp","r",stdin);
    //freopen(file_name".out","w",stdout);	
    #endif // ONLINE_JUDGE
    Task::solve();
}

