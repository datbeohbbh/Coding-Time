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
#define pb push_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

const int N=1e5+5;
map <int,vector <int> > ma[2];
int par[N],vis[N],len[N];
int degin[N],degout[N];
int f[N],tr[N];
string str[N];
vector <pii> adj[N];
vector <int> topo;
bool isCycle = false;

int findp(int u){return par[u] == u ? u : findp(par[u]);}
void join(int u,int v){
    u = findp(u),v = findp(v);
    if(u == v)return ;
    par[u] = v;
}

void dfs(int u){
    vis[u] = 1;
    for(auto cur : adj[u]){
        int v = cur.fir;
        if(!vis[v])
          dfs(v);
        else{
            if(vis[v] == 1){
              isCycle = true;
              break;
            }
        }
    }
    vis[u] = 2;
    topo.pb(u);
}

void buildGr(int i,string s){
    string tmp = "";
    int j = 0;
    tmp+=(char)s[j];
    while(j < len[i] and sz(ma[1][tmp]))
      tmp.pb(s[++j]);
    --j;
    if(j >= 0){
        tmp.pop_back();
        for(auto v : ma[1][tmp])
         if(v ^ i){
           ++degin[v];
           ++degout[i];
           adj[i].pb(mp(v,len[i] - j));
           join(i,v);
          }
    }
    j = len[i] - 1;
    tmp.clear();
    tmp+=(char)s[j];
    while(~j and sz(ma[0][tmp]))
      tmp = s[--j] + tmp;
    ++j;
    if(j < len[i]){
        tmp.erase(0,1);
        for(auto v : ma[0][tmp])
         if(v ^ i){
           adj[i].pb(mp(v,j));
           join(i,v);
           ++degin[v];
           ++degout[i];
         }
    }
}

bool valid(){
    for(int i = 1;i <= n;++i)
      if(!vis[i]){
        dfs(i);
      }
    int cnt = 0;
    for(int i = 1;i <= n;++i)
     cnt+=par[i] == i;
    return (cnt == 1 and !isCycle);
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i)par[i] = i;
    for(int i = 1;i <= n;++i){
        string s;
        cin>>s;
        string tmp = "";
        len[i] = sz(s);
        str[i] = s;
        for(int j = 0;j < len[i];++j){
            tmp += (char)s[j];
            ma[0][tmp].pb(i);
        }
        tmp.clear();
        for(int j = len[i] - 1;~j;--j){
            tmp = (char)s[j] + tmp;
            ma[1][tmp].pb(i);
        }
    }
    for(int i = 1;i <= n;++i){
        buildGr(i,str[i]);
    }
    if(!valid())
      cout<<"NO",exit(0);
    int src = -1;
    for(int i = 1;i <= n;++i)
      if(!degin[i])
        src = i,f[i] = len[i];
    fill(vis + 1,vis + 1 + n,0);
    for(int i = 1;i <= n;++i)
     if(i ^ src)
       f[i] = numeric_limits <int> :: max() >> 2;
    topo.clear();
    dfs(src);
    for(int i = sz(topo) - 1;~i;--i){
        int u = topo[i];
        for(int j = 0;j < sz(adj[u]);++j){
            int v = adj[u][j].fir;
            int c = adj[u][j].sec;
            if(f[v] > f[u] + c){
                tr[v] = u;
                f[v] = f[u] + c;
            }
        }
    }
    vector <int> vec;
    for(int i = 1;i <= n;++i)
      if(!degout[i]){
        if(f[i] == n){
          vec.pb(i);
        }
      }
    if(vec.empty())
      cout<<"NO",exit(0);

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
