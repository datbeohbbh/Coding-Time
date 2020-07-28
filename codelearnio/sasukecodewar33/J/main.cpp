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

    const int N = 16;
    const int inf = 2e9;
    const int tx[] = {0,0,-1,1};
    const int ty[] = {1,-1,0,0};
    pair <int,int> pos[N];
    bool del[N >> 1][N >> 1];
    bool can[(1 << N) + 2][4][4];
    int f[(1 << N) + 2];

    //tuple <int,int,int,int> tr[(1 << N) + 2][140];

    bool insize(int i,int j){
        return 0 <= i and i <= 3 and 0 <= j and j <= 3;
    }

    void bfs(int mask){
        queue < pair <int,int> > q;
        vector < vector <bool> > vis(4,vector <bool> (4,false));
        for(int i = 0;i < 4;++i){
            if(del[0][i]){
                q.emplace(make_pair(0,i));
                vis[0][i] = true;
            }
            if(del[i][0]){
                q.emplace(make_pair(i,0));
                vis[i][0] = true;
            }
            if(del[i][3]){
                q.emplace(make_pair(i,3));
                vis[i][3] = true;

            }
            if(del[3][i]){
                q.emplace(make_pair(3,i));
                vis[3][i] = true;
            }
        }
        for(;len(q) > 0;q.pop()){
            pair <int,int> top = q.front();
            int u = top.first;
            int v = top.second;
            for(int i = 0;i < 4;++i){
                int ux = u + tx[i];
                int vy = v + ty[i];
                if(insize(ux,vy) and del[ux][vy] and !vis[ux][vy]){
                    q.emplace(make_pair(ux,vy));
                    vis[ux][vy] = true;
                }
            }
        }
        for(int i = 0;i < 4;++i){
            for(int j = 0;j < 4;++j){
                if(!del[i][j]){
                    for(int k = 0;k < 4;++k){
                        int ii = i + tx[k];
                        int jj = j + ty[k];
                        if(!insize(ii,jj)){
                            can[mask][i][j] = true;
                        } else {
                            can[mask][i][j] |= vis[ii][jj];
                        }
                    }
                }
            }
        }
    }

    int compute(int mask){
        if(mask == (1 << N) - 1){
            return 0;
        }
        if(~f[mask]){
            return f[mask];
        }
        int res = 0;
        for(int v = N - 1;v >= 0;--v){
            if(!((mask >> v) & 1) && can[mask][pos[v].first][pos[v].second]){
                int mi = inf;
                for(int u = N - 1;u >= 0;--u){
                    if(u != v){
                        //int mi = inf;
                        if(!((mask >> u) & 1) and can[mask | (1 << v)][pos[u].first][pos[u].second]){
                            minimize(mi,v + 1 + compute(mask | (1 << v) | (1 << u)));
                        }
                    }
                }
                maximize(res,mi);
            }
        }
        return (f[mask] = res);
    }

    int maxDiff(vector <string> board){
        for(int i = 0;i < 4;++i){
            stringstream ss(board[i]);
            for(int j = 0;j < 4;++j){
                int val;
                ss >> val;
                pos[--val] = make_pair(i,j);
            }
        }
        for(int mask = 0;mask < (1 << N);++mask) {
            for (int i = 0; i < N; ++i) {
                if ((mask >> i) & 1) {
                    del[pos[i] . first][pos[i] . second] = true;
                }
            }
            bfs(mask);
            for (int i = 0; i < N; ++i) {
                if ((mask >> i) & 1) {
                    del[pos[i] . first][pos[i] . second] = false;
                }
            }
        }
        memset(f,-1,sizeof(f));
        int ans = compute(0);
       // clog<<ans;
        return Abs(136 - (ans << 1));
    }

    void solve(){
        vector <string> board(4);
        for(int i = 0;i < 4;++i){
            getline(cin,board[i]);
        }
        cout<<maxDiff(board);
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