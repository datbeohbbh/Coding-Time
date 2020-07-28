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

#define len(c) (int)((c).size())
#define llong long long
#define MASK(i) ((1LL) << (i))
#define BIT(x,i) (((x) >> (i)) & 1)
#define all(c) (c).begin(),(c).end()
#define fn "test"    ///FILE_NAME_HERE

/*----------END_OF_TEMPLATE----------*/

namespace task{

    void solve(){
        int T;
        cin>>T;
        while(T--){
            int n,k;
            cin>>n>>k;
            vector <int> w(n + 2,0);
            vector <int> c(n + 2,0);
            for(int i = 0;i < n;++i){
                cin>>c[i]>>w[i];
            }
            llong ans = 0;
            for(int mask = 0;mask < MASK(n);++mask){
                llong sum_w = 0;
                llong sum_c = 0;
                for(int i = 0;i < n;++i){
                    sum_w += 1LL * BIT(mask,i) * 1LL * w[i];
                    sum_c += 1LL * BIT(mask,i) * 1LL * c[i];
                }
                if(sum_c <= 1LL * k){
                    maximize(ans,sum_w);
                }
            }
            cout<<ans<<'\n';
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
