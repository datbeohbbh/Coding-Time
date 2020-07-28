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

    const int N = 1e6;
    bitset <N + 6> isPrime;
    vector <int> primes;

    void solve(){
        isPrime.set();
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2;i <= N;++i){
            if(isPrime[i]) {
                for (int j = (i << 1); j <= N; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        for(int i = 2;i <= N;++i){
            if(isPrime[i]){
                primes.emplace_back(i);
            }
        }
        int numTest;
        cin>>numTest;
        auto calc = [&](int r,int p) -> int{
            int ret = 0;
            while(r){
                r /= p;
                ret += r;
            }
            return  ret;
        };
        while(numTest--){
            int n,k;
            cin>>n>>k;
            vector < pair <int,int> > product;
            for(int p = 0;p < len(primes) and primes[p] <= n - 1;++p){
                int x = calc(n - k,primes[p]);
                int y = calc(n - 1,primes[p]);
                int z = calc(k - 1,primes[p]);
                y -= x;
                y -= z;
                product.emplace_back(make_pair(primes[p],y));
            }
            llong ans = 1;
            for(pair <int,int> p : product){
                for(int j = 1;j <= p.second;++j){
                    ans *= 1LL * p.first;
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
