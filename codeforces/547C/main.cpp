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
    const int maxVal = 5e5;
    vector < int > prime;
    vector < vector < int > > p;
    int e[maxVal + 5];
    int cnt[maxVal + 5];
    bool inshelf[N];
    int a[N];
    int n,q;

    void solve(){
        cin>>n>>q;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        iota(e,e + 1 + maxVal,0);
        for(int i = 2;i <= maxVal;++i){
            if(e[i] == i){
                prime.emplace_back(i);
            }
            for(int j = 0;j < len(prime) and i * prime[j] <= maxVal;++j){
                e[i * prime[j]] = prime[j];
                if(i % prime[j] == 0){
                    break;
                }
            }
        }
        p.resize(n + 2,vector < int > ());
        for(int i = 1;i <= n;++i){
            int tmp = a[i];
            for(int k = e[tmp];k > 1 and tmp > 1;k = e[tmp]){
                while(tmp % k == 0){
                    tmp /= k;
                }
                p[i].emplace_back(k);
            }
        }
        int cur = 0;
        llong ans = 0;
        while(q--){
            int x;
            cin>>x;
            llong subs = 0;
            int k = (inshelf[x] ? -1 : 1);
            for(int mask = 1;mask < MASK(len(p[x]));++mask){
                int mul = 1;
                for(int i = 0;i < len(p[x]);++i){
                    if(BIT(mask,i)){
                        mul *= p[x][i];
                    }
                }
                subs += 1LL * ((__builtin_popcount(mask) & 1) ? 1 : -1) * 1LL * cnt[mul];
            }
            if(!inshelf[x]){
                ans += cur - subs;
                inshelf[x] = true;
                ++cur;
            } else {
                ans -= cur - (a[x] == 1 ? 1 : subs);
                inshelf[x] = false;
                --cur;
            }
            cout<<ans<<'\n';
            for(int mask = 1;mask < MASK(len(p[x]));++mask){
                int mul = 1;
                for(int i = 0;i < len(p[x]);++i){
                    if(BIT(mask,i)){
                        mul *= p[x][i];
                    }
                }
                cnt[mul] += k;
            }
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
