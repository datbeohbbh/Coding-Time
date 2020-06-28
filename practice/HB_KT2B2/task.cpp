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

const  int N = 5e5 + 5;
int a[11][N],s[N<<1],left[N<<1],right[N<<1];
int m,n;

void calcLeft(){
    stack <int> stk;
    int j = n;
    for(int i = 1;i <= n;++i){
        stk.push(i);
    }
    for(int i = n + 1;i <= (n<<1);++i){
        while(true){
            int j = stk.top();
            if(s[j] >= s[i]){
                left[i] = j + 1;
                break;
            }
            stk.pop();
        }
        stk.push(i);
    }
}

void calcRight(){
    stack <int> stk;
    int j = n + 1;
    for(int i = (n<<1);i > n;--i){
        stk.push(i);
    }
    for(int i = n;i >= 1;--i){
        while(true){
            int j = stk.top();
            if(s[j] >= s[i]){
                right[i] = j - 1;
                break;
            }
            stk.pop();
        }
        stk.push(i);
    }
}

void solve()
{
    cin>>m>>n;
    for(int i = 1;i <= m;++i)
        for(int j = 1;j <= n;++j){
            cin>>a[i][j];
        }
    for(int j = 1;j <= n;++j)
        for(int i = 1;i <= m;++i){
            s[j] += a[i][j];
        }
    for(int i = 1;i <= n;++i){
        s[i + n] = s[i];
    }
    calcLeft();
    calcRight();
    for(int i = 1;i <= n;++i){
        cout<<min(right[i] - left[i + n] + n,n - 1)<<' ';
    }
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
