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

const int N = 1e5 + 5;
const int lg = 18;
vector <int> maxpre,maxsuf;
vector <int> block[N];
char a[N],b[N];
int sA[N],sB[N],c[N],last[N];
int f[N];
int n;

int bs(int l,int r,int idx,int val){
    int pos = -1;
    for(int mid = (l + r)>>1;l <= r;mid = (l + r)>>1){
        if(c[block[idx][mid]] <= val){
            l = mid + 1;
            pos = mid;
        }
        else {
            r = mid - 1;
        }
    }
    return pos;
}

void solve()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i]>>b[i];
    }
    for(int i = 1;i <= n;++i){
        sA[i] = sA[i - 1] + (a[i] == 'A');
        sB[i] = sB[i - 1] + (a[i] == 'B');
    }
    int flag = 0;
    for(int i = 1;i <= n + 1;++i){
        c[i] = sA[i] - sB[i];
        last[i] = flag;
        if(b[i] == 'L')
            flag = i;
    }
    int cur = -1;
    b[n + 1] = 'L';
    for(int i = 1;i <= n + 1;++i){
        if(b[i] != 'L')
            continue;
        int l = last[i];
        ++cur;
        for(int j = l;j < i;++j){
            block[cur].pb(j);
        }
    }
    f[block[0][0]] = 0;
    for(int j = 1;j < sz(block[0]);++j){
        f[block[0][j]] = -1;
    }
    for(int i = 0;i <= cur;++i){
        sort(all(block[i]),[](const int &x,const int &y){
           return c[x] < c[y];
        });
    }
    for(int i = 1;i <= cur;++i){
        int len = sz(block[i - 1]);
        maxpre.clear();
        maxpre.resize(len,0);
        maxsuf.clear();
        maxsuf.resize(len,0);
        for(int j = 0;j < len;++j){
            maxpre[j] = maxsuf[j] = f[block[i - 1][j]];
        }
        for(int j = 1;j < len;++j){
            maximize(maxpre[j],maxpre[j - 1]);
        }
        for(int i = len - 2;~i;--i){
            maximize(maxsuf[i],maxsuf[i + 1]);
        }
        for(int j = 0;j < sz(block[i]);++j){
            int pos = bs(0,sz(block[i - 1]) - 1,i - 1,c[block[i][j]]);
            if(~pos){
                maximize(f[block[i][j]],maxpre[pos] + 1);
                if(pos + 1 < len)maximize(f[block[i][j]],maxsuf[pos + 1]);
            }
            else
                maximize(f[block[i][j]],maxpre[len - 1]);
        }
    }
    cout<<f[n];
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
