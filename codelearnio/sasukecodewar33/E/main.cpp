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

    bool isPrime(int val){
        if(val < 2){
            return false;
        }
        for(int i = 2;i * i <= val;++i){
            if(val % i == 0){
                return false;
            }
        }
        return true;
    }

    int sumPrimeFactor(int n){
        llong ans = 0;
        for(int i = 1;i * i <= n;++i){
            if(n % i != 0){
                continue;;
            }
            if(isPrime(i)){
                ans += 1LL * i;
            }
            if(i != n / i and isPrime(n / i)){
                ans += 1LL * (n / i);
            }
        }
        return ans;
    }

    void solve(){
        int n;
        while(cin >> n){
            cout<<sumPrimeFactor(n)<<'\n';
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
