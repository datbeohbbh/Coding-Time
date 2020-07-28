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

int NextInt() {
    int ret = 0, d;
    d = getchar();
    while (d < 48 || d > 57)
       	d = getchar();
    do {
        ret = ret * 10 + d - 48;
        d = getchar();
    } while (d > 47 && d < 58);
    return ret;
}

const int inf = 1e9;
const int N = 4e3 + 4;
int f[N][N],dp[808][N];
int n,k;

int sum(int l,int r){
    return (f[r][r] - f[l - 1][r] - f[r][l - 1] + f[l - 1][l - 1]);
}

void calc(int gr,int jleft,int jright,int kleft,int kright){
    if(jleft > jright)return ;
    int jmid = (jleft + jright) >> 1;
    int best = kleft;
    dp[gr][jmid] = inf;
    for(int j = kright;j >= kleft;--j){
        if(j < jmid){
            if(dp[gr][jmid] > dp[gr - 1][j] + sum(j + 1,jmid)){
                dp[gr][jmid] = dp[gr - 1][j] + sum(j + 1,jmid);
                best = j;
            }
        }
    }
    calc(gr,jleft,jmid - 1,kleft,best);
    calc(gr,jmid + 1,jright,best,kright);
}

void solve()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            f[i][j] = NextInt();
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    for(int i = 1;i <= n;++i){
        dp[1][i] = sum(1,i);
    }
    for(int i = 2;i <= k;++i){
        calc(i,1,n,1,n);
    }
    dp[k][n]>>=1;
    printf("%d",dp[k][n]);
}}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
//    ofstream inp(fn".inp");
//    srand(time(NULL));
//    inp<<4000<<' '<<10<<'\n';
//    vector <vector <int> > a,mark;
//    a.resize(4002,vector <int>(4002,0));
//    mark = a;
//    for(int i = 1;i <= 4000;++i){
//        for(int j = 1;j <= 4000;++j){
//            if(mark[i][j])continue;
//            a[i][j] = a[j][i] = rand() % 10;
//            mark[i][j] = mark[j][i] = 1;
//        }
//    }
//    for(int i = 1;i <= 4000;++i){
//        for(int j = 1;j <= 4000;++j){
//            inp<<a[i][j]<<' ';
//        }
//        inp<<'\n';
//    }
}
