#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

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
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x + k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x - k) % MOD + MOD) % MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const int N = 1e5 + 5;
    int a[N];
    int n;
    int nxt[2][N];

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        int dec = 1,inc = 1;
        for(int i = 2;i <= n;++i){
            inc += (a[i - 1] <= a[i]);
            dec += (a[i - 1] >= a[i]);
        }
        if(inc == n or dec == n){
            cout<<0,exit(0);
        }
        a[n + 1] = (N << 10);
        stack <int> stk;
        stk.emplace(n + 1);
        for(int i = n;i >= 1;--i){
            while(!stk.empty() and a[i] >= a[stk.top()]){
                stk.pop();
            }
            nxt[0][i] = stk.top();
            stk.emplace(i);
        }
        while(!stk.empty()){
            stk.pop();
        }
        a[n + 1] = -(N << 10);
        stk.emplace(n + 1);
        for(int i = n;i >= 1;--i){
            while(!stk.empty() and a[i] <= a[stk.top()]){
                stk.pop();
            }
            nxt[1][i] = stk.top();
            stk.emplace(i);
        }
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < 2;++j){
                if(nxt[j][i] <= n and nxt[j ^ 1][nxt[j][i]] <= n){
                    cout<<3<<'\n';
                    cout<<i<<' '<<nxt[j][i]<<' '<<nxt[j ^ 1][nxt[j][i]];
                    exit(0);
                }
            }
        }
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