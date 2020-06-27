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
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
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
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    const  int inf = 1e9;
    const  int N = 2e5 + 5;
    int p[N],pos[N];
    int left[N],right[N];
    int n;
    ll ans = 0;

    void pre_calc(){
        p[0] = p[n + 1] = inf;
        int j = 0;
        stack <int> lstack,rstack;
        lstack.push(j);
        for(int i = 1;i <= n;++i){
            while(true){
                j = lstack.top();
                if(p[j] > p[i]){
                    break;
                }
                lstack.pop();
            }
            lstack.push(i);
            left[i] = j + 1;
        }
        j = n + 1;
        rstack.push(j);
        for(int i = n;i >= 1;--i){
            while(true){
                j = rstack.top();
                if(p[j] > p[i]){
                    break;
                }
                rstack.pop();
            }
            right[i] = j - 1;
            rstack.push(i);
        }
    }

    void calc(int perm,int lx,int rx,int ly,int ry){
        for(int i = lx;i <= rx;++i){
            if(pos[perm - p[i]] >= ly and pos[perm - p[i]] <= ry){
                ++ans;
            }
        }
    }

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>p[i];
        }
        for(int i = 1;i <= n;++i){
            pos[p[i]] = i;
        }
        pre_calc();
        for(int i = 1;i <= n;++i){
            if(!(i - left[i]) or !(right[i] - i))continue;
            if((i << 1) < left[i] + right[i])
                calc(p[i],left[i],i - 1,i + 1,right[i]);
            else
                calc(p[i],i + 1,right[i],left[i],i - 1);
        }
        cout<<ans;
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