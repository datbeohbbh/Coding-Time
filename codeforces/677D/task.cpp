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
void maximize(T &x,U y)
{
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y)
{
    if(x > y)x=y;
}
template <class T>
T Abs(T x)
{
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x)
{
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD)
{
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD)
{
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD)
{
    return (long long)x*y%MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N = 301;
const int inf = 2e9;
const int tx[] = {-1,0,1,0};
const int ty[] = {0,-1,0,1};
vector <pii> color[N*N];
vector <pair <int,pii> > bfs,aux;
int vis[N][N],a[N][N];
pii des;
int f[N][N];
int n,m,p;

int cost(pii x,pii y){
    return Abs(y.fir - x.fir) + Abs(y.sec - x.sec);
}

bool insize(int x,int y){
    return 1 <= x and x <= n and 1 <= y and y <= m;
}

void solve()
{
    cin>>n>>m>>p;
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            cin>>a[i][j];
            f[i][j] = inf;
            if(a[i][j] == 1)
                f[i][j] = i + j - 2;
            color[a[i][j]].pb(mp(i,j));
            if(a[i][j] == p)
                des = mp(i,j);
        }
    }
    for(int col = 2;col <= p;++col){
        int pre_size = sz(color[col - 1]);
        int cur_size = sz(color[col]);
        if(pre_size * cur_size <= n*m){
            for(int i = 0;i < pre_size;++i){
                int pre_x = color[col - 1][i].fir;
                int pre_y = color[col - 1][i].sec;
                for(int j = 0;j < cur_size;++j){
                    int cur_x = color[col][j].fir;
                    int cur_y = color[col][j].sec;
                    minimize(f[cur_x][cur_y],f[pre_x][pre_y] + cost(color[col - 1][i],color[col][j]));
                }
            }
        }
        else {
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j)
                    vis[i][j] = -1;
            }
            aux.clear();
            bfs.clear();
            for(int i = 0;i < pre_size;++i){
                int pre_x = color[col - 1][i].fir;
                int pre_y = color[col - 1][i].sec;
                aux.pb(mp(f[pre_x][pre_y],mp(pre_x,pre_y)));
            }
            sort(all(aux));
            bfs.pb(aux[0]);
            vis[aux[0].sec.fir][aux[0].sec.sec] = aux[0].fir;
            int jbfs = 0,jaux = 1;
            while(jbfs < sz(bfs)){
                pair <int,pii> top = bfs[jbfs];
                ++jbfs;
                int x = top.sec.fir;
                int y = top.sec.sec;
                while(jaux < sz(aux) and aux[jaux].fir <= top.fir)
                    bfs.pb(aux[jaux++]);
                for(int i = 0;i < 4;++i){
                    int nx = x + tx[i];
                    int ny = y + ty[i];
                    if(insize(nx,ny) and vis[nx][ny] == -1){
                        vis[nx][ny] = top.fir + 1;
                        bfs.pb(mp(top.fir + 1,mp(nx,ny)));
                    }
                }
            }
            for(int i = 0;i < cur_size;++i){
                int cur_x = color[col][i].fir;
                int cur_y = color[col][i].sec;
                f[cur_x][cur_y] = vis[cur_x][cur_y];
            }
        }
    }
    cout<<f[des.fir][des.sec];
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
