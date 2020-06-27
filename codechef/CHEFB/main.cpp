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

    const int N = 1e5 + 5;
    const int maxVal = 1e6;
    vector <int> prime;
    vector <int> f[maxVal + 2];
    int p[maxVal + 2];
    int n;

    void compute(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            int val;
            cin>>val;
            for(int k = p[val];k > 1 and val > 1;k = p[val]){
                int c = 0;
                while(val % k == 0){
                    val /= k;
                    ++c;
                }
                f[k].emplace_back(c);
            }
        }
        int ans = 0;
        for(int i = 2;i <= maxVal;++i){
            if(!f[i].empty()){
                sort(all(f[i]));
                int c = 0;
                for(int k : f[i]){
                    ans += k - c;
                    c += (k - c);
                }
            }
        }
        cout<<ans<<'\n';
        for(int i = 2;i <= maxVal;++i){
            if(!f[i].empty()){
                f[i].clear();
            }
        }
    }

    void solve(){
        int T;
        cin>>T;
        for(int i = 0;i <= maxVal;++i){
            p[i] = (i > 1 ? i : 1);
        }
        for(int i = 2;i <= maxVal;++i){
            if(p[i] == i){
                prime.emplace_back(i);
            }
            for(int j = 0;j < len(prime) and i * prime[j] <= maxVal;++j){
                p[i * prime[j]] = prime[j];
                if(i % prime[j] == 0)break;
            }
        }
        while(T--){
            compute();
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
