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
    vector <int> f[maxVal + 2];
    int p[maxVal + 2];
    int freq[maxVal + 2];
    int a[N];
    int n;

    bool canAdd(int r){
        for(int val : f[a[r]]){
            if(freq[val] == 1){
                return false;
            }
        }
        return true;
    }

    int compute(){
        cin>>n;
        for(int i = 1;i <= n;++i){
            cin>>a[i];
        }
        int ans = 1;
        int r = 0;
        for(int i = 1;i <= n;++i){
            while(r + 1 <= n and canAdd(r + 1)){
                ++r;
                for(int val : f[a[r]]){
                    ++freq[val];
                }
            }
            for(int val : f[a[i]]){
                --freq[val];
            }
            maximize(ans,r - i + 1);
        }
        for(int i = 1;i <= n;++i){
            for(int val : f[a[i]]){
                freq[val] = 0;
            }
        }
        return (ans == 1 ? -1 : ans);
    }

    void solve(){
        int T;
        cin>>T;
        for(int i = 0;i <= maxVal;++i){
            p[i] = i;
        }
        for(int i = 2;i <= maxVal;++i){
            if(p[i] == i){
                for(int j = (i << 1);j <= maxVal;j += i){
                    p[j] = i;
                }
            }
        }
        for(int i = 2;i <= maxVal;++i){
            for(int j = i,k = p[j];j > 1 and k > 1;k = p[j]){
                while(j % k == 0){
                    j /= k;
                }
                f[i].emplace_back(k);
            }
        }
        while(T--){
            cout<<compute()<<'\n';
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
