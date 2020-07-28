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

    const int N = 1e5;

    int longestArray(vector <int> a){
        int ans = 0;
        vector <int> cnt(N + 5,0);
        for(int p : a){
            ++cnt[p];
        }
        for(int i = 2;i <= N;++i){
            int f = 0;
            for(int j = i;j <= N;j += i){
                f += cnt[j];
            }
            ans = max(ans,f);
        }
        return ans;
    }

    void solve(){
        vector <int> a;
        int val;
        while(cin >> val){
            a.emplace_back(val);
        }
        cout<<longestArray(a);
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
