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
            int n,f;
            cin>>n>>f;
            vector <int> h(n + 2,0);
            for(int i = 1;i <= n;++i){
                cin>>h[i];
            }
            sort(h.begin() + 1,h.begin() + 1 + n);
            map <int,int> cnt;
            llong ans = 0;
            for(int i = 1;i <= n;++i){
                int tf = 1;
                while(tf <= h[i] and h[i] % tf == 0){
                    ans += 1LL * cnt[h[i] / tf];
                    if(tf > 1e9 / f){
                        break;
                    }
                    tf *= f;
                }
                ++cnt[h[i]];
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
