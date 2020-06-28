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
        int t;
        cin>>t;
        vector <int> cnt(1000006,0);
        while(t--){
            int n;
            cin>>n;
            vector <int> a(n + 2);
            vector <int> changes;
            for(int i = 1;i <= n;++i){
                cin>>a[i];
            }
            for(int i = 1;i <= n;++i){
                int val = a[i];
                for(int j = 2;j * j <= val;++j){
                    if(val % j == 0){
                        while(val % j == 0){
                            val /= j;
                            ++cnt[j];
                        }
                        changes.emplace_back(j);
                    }
                }
                if(val > 1){
                    ++cnt[val];
                    changes.emplace_back(val);
                }
            }
            sort(all(changes));
            changes.erase(unique(all(changes)),changes.end());
            llong ans = 1;
            for(int p : changes){
                ans *= (cnt[p] + 1);
                cnt[p] = 0;
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
