const int inf = 1e9;
class HopcroftKarp{
public:
    vector <int> pairU;
    vector <int> pairV;
    vector <int> dist;
    vector < vector <int> > adj;
    int n;
    int cntMatching;
public:
    HopcroftKarp(int n){
        pairU.resize((n << 2) + 2,0);
        pairV.resize((n << 2) + 2,0);
        dist.resize((n << 2) + 2,0);
        adj.resize((n << 2) + 2,vector <int> ());
        this -> cntMatching = 0;
        this -> n = n;
    }
    ~HopcroftKarp(){
        pairU.clear();
        pairV.clear();
        dist.clear();
        adj.clear();
        this -> n = 0;
        this -> cntMatching = 0;
    }

    void addEdges(int u,int v){
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    bool bfs(){
        queue <int> q;
        for(int u = 1;u <= n;++u){
            if(!pairU[u]){
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = inf;
            }
        }
        dist[0] = inf;
        for(;len(q);q.pop()){
            int u = q.front();
            if(dist[u] >= dist[0])continue;
            for(int i = 0;i < len(adj[u]);++i){
                int v = adj[u][i];
                if(dist[pairV[v]] == inf){
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
        return (dist[0] != inf);
    }

    bool dfs(int u){
        if(u){
            for(int i = 0;i < len(adj[u]);++i){
                int v = adj[u][i];
                if(dist[pairV[v]] == dist[u] + 1){
                    if(dfs(pairV[v])){
                        pairV[v] = u;
                        pairU[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    void computeMatching(){
        while(bfs()){
            for(int u = 1;u <= n;++u){
                if(!pairU[u] and dfs(u)){
                    ++cntMatching;
                }
            }
        }
    }
};
