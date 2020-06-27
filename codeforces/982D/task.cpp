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

const int N=1e5 + 5;
int a[N],idx[N],lab[N];
int n,maxlocations = 0,ans;
set <pii> heap;

int findp(int u){
    return (lab[u] < 0 ? u : findp(lab[u]));
}

bool join(int u,int v){
    u = findp(u),v = findp(v);
    if(u == v)return false;
    if(lab[u] > lab[v])swap(u,v);
    heap.erase(mp(lab[u],u));
    heap.erase(mp(lab[v],v));
    lab[u] += lab[v];
    lab[v] = u;
    heap.insert(mp(lab[u],u));
    return true;
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
        idx[i] = i;
        lab[i] = -1;
    }
    sort(idx + 1,idx + 1 + n,[](const int &i,const int &j){
        return a[i] < a[j];
    });
    ans = a[idx[1]];
    heap.insert(mp(-1,idx[1]));
    for(int i = 2;i <= n;++i){
        int j = idx[i - 1];
        while(j > 1 and a[j - 1] < a[idx[i]]){
            if(!join(j,j - 1))break;
            --j;
        }
        j = idx[i - 1];
        while(j < n and a[j + 1] < a[idx[i]]){
            if(!join(j,j + 1))break;
            ++j;
        }
        if(!heap.empty() and heap.begin() -> fir == heap.rbegin() -> fir){
            if(sz(heap) > maxlocations){
                maxlocations = sz(heap);
                ans = a[idx[i]];
            }
        }
        heap.insert(mp(lab[idx[i]],idx[i]));
    }
    cout<<ans;
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
