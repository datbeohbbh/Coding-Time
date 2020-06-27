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

    struct Project {
        int l,r,idx;
        ll p;
        Project(){}
        Project(int _l,int _r,ll _p,int _idx){
            l = _l;
            r = _r;
            p = _p;
            idx = _idx;
        }
        bool operator < (const Project &other) const {
            return (l < other.l) or (l == other.l and r < other.r) or (l == other.l and r == other.r and p > other.p)
                    or (l == other.l and r == other.r and p == other.p and idx < other.idx);
        }
    };
    Project a[N];
    ll sump[N];
    ll g[N];
    int rmq[lg + 2][N];
    int fl[N],fr[N];
    int n;
    ll k;

    void precalc(){
        a[0].r = a[n + 1].r = N;
        stack <int> stk;
        int j = 0;
        stk.push(j);
        for(int i = 1;i <= n;++i){
            while(true){
                j = stk.top();
                if(a[j].r > a[i].r){
                    break;
                }
                stk.pop();
            }
            fl[i] = j + 1;
            stk.push(i);
        }
        while(!stk.empty())stk.pop();
        j = n + 1;
        stk.push(j);
        for(int i = n;i >= 1;--i){
            while(true){
                j = stk.top();
                if(a[j].r > a[i].r){
                    break;
                }
                stk.pop();
            }
            fr[i] = j - 1;
            stk.push(i);
        }
    }

    int getMin(int l,int r){
        int x = (int)log2(r - l + 1);
        if(g[rmq[x][l]] <= g[rmq[x][r - MASK(x) + 1]]){
            return rmq[x][l];
        }
        return rmq[x][r - MASK(x) + 1];
    }

    Project compute(int i){
        Project ret = Project(0,0,0,0);
        for(int t = fr[i];t >= i;--t){
            int j = getMin(fl[i],t);
            if(ret.p < sump[t] - k*1LL*a[i].r - g[j]){
                ret = Project(j,i,sump[t] - k*1LL*a[i].r - g[j],t);
            }
        }
        return ret;
    }

    void solve(){
        cin>>n>>k;
        for(int i = 1;i <= n;++i){
            int l,r;
            ll p;
            cin>>l>>r>>p;
            a[i] = Project(l,r,p,i);
        }
        sort(a + 1,a + 1 + n);
        for(int i = 1;i <= n;++i){
            sump[i] = sump[i - 1] + a[i].p;
        }
        for(int i = 1;i <= n;++i){
            g[i] = sump[i - 1] - k*1LL*(a[i].l - 1);
        }
        precalc();
        for(int i = 1;i <= n;++i){
            rmq[0][i] = i;
        }
        for(int j = 1;j <= lg;++j){
            for(int i = 1;i <= n - MASK(j) + 1;++i){
                rmq[j][i] = (g[rmq[j - 1][i]] <= g[rmq[j - 1][i + MASK(j - 1)]] ? rmq[j - 1][i] : rmq[j - 1][i + MASK(j - 1)]);
            }
        }
        Project ans = Project(0,0,0,0);
        for(int i = 1;i <= n;++i){
            Project cur = compute(i);
            if(ans.p < cur.p){
                ans = cur;
            }
        }
        cout<<ans.p<<' ';
        if(ans.p != 0){
            int jj = ans.l;
            int rr = ans.idx;
            cout<<a[ans.l].l<<' '<<a[ans.r].r<<' '<<rr - jj + 1<<'\n';
            while(jj <= rr){
                cout<<a[jj].idx<<' ';
                ++jj;
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