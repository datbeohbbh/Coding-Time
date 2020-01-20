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

    const int N = 2e5 + 5;
    const int lg = 18;
    int n,m;
    int a[N],pw[N],maxPref[N];
    int rmq[N][lg + 1];

    int getMax(int l,int r){
        int x = (int)log2(r - l + 1);
        return max(rmq[l][x],rmq[r - MASK(x) + 1][x]);
    }

    int calc(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            rmq[i][0] = a[i];
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i <= n - MASK(j) + 1;++i){
                rmq[i][j] = max(rmq[i][j - 1],rmq[i + MASK(j - 1)][j - 1]);
            }
        }
        cin>>m;
        fill(pw + 1,pw + 1 + n,0);
        fill(maxPref + 1,maxPref + 1 + n,0);
        for(int i = 1;i <= m;++i){
            int p,s;
            cin>>p>>s;
            maximize(pw[s],p);
        }
        for(int i = 1;i <= n;++i){
            maxPref[i] = pw[i];
        }
        for(int i = n - 1;i > 0;--i){
            maximize(maxPref[i],maxPref[i + 1]);
        }
        if(getMax(1,n) > maxPref[1]){
            return -1;
        }
        int ans = 0;
        for(int i = 1;i <= n;++i){
            int cur = i;
            while(cur <= n and maxPref[cur - i + 1] >= getMax(i,cur)){
                ++cur;
            }
            ++ans;
            i = cur - 1;
        }
        return ans;
    }

    void solve(){
        int numTest;
        cin>>numTest;
        while(numTest--){
            cout<<calc()<<'\n';
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