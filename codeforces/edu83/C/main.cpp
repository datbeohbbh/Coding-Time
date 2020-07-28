#include <bits/stdc++.h>

using namespace std;

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

#define ll long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    void solve(){
        int t;
        cin>>t;
        while(t--){
            int n,k;
            cin>>n>>k;
            vector <ll> a;
            for(int i = 1;i <= n;++i){
                ll val;
                cin>>val;
                a.emplace_back(val);
            }
            sort(all(a));
            int lim = 0;
            ll cur = 1;
            while(cur <= (ll)1e16 / k){
                cur *= k;
                ++lim;
            }
            for(int j = lim;j >= 0;--j){
                ll subs = 1;
                for(int t = 1;t <= j;++t){
                    subs *= k;
                }
                for(int i = a.size() - 1;~i;--i){
                    if(a[i] >= subs){
                        a[i] -= subs;
                        break;
                    }
                }
                sort(all(a));
            }
            int cnt = 0;
            for(int i = 0;i < a.size();++i){
                cnt += (a[i] == 0);
            }
            cout<<(cnt == n ? "YES\n" : "NO\n");
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE
    task::solve();
}
