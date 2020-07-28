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

    const int N = 2e5 + 5;
    llong a[N],suff[N],pref[N];
    int n;
    map <llong,int> ma;

    void solve(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
            pref[i] = a[i];
            suff[i] = a[i];
        }
        for(int i = 2;i <= n;++i){
            pref[i] += pref[i - 1];
        }
        for(int i = n - 1;i >= 1;--i){
            suff[i] += suff[i + 1];
            if(i > 1) {
                ++ma[suff[i]];
            }
        }
        ++ma[suff[n]];
        llong ans = 0;
        for(int i = 1;i <= n;++i){
            ans += 1LL * (n - i + 1);
        }
        for(int i = 1;i < n;++i){
            if(i > 1){
                if(ma[suff[i]] > 0){
                    --ma[suff[i]];
                }
            }
            if(ma[pref[i]] > 0){
                ans -= ma[pref[i]];
            }
            if(pref[i] == suff[i + 1]){
                ++ans;
            }
        }
        ans -= (pref[n] == 0);
        cout<<ans;
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
