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

    const int lg = 64;
    vector <int> digits;
    llong dp[lg + 1][lg + 1];

    llong calc(llong val){
        digits.clear();
        for(int j = 0;j < lg;++j){
            if((val >> j) & 1){
                digits.emplace_back(j);
            }
        }
        llong ans = 0;
        int adds = 0;
        for(int j = len(digits) - 1;~j;--j){
            int k = digits[j];
            for(int i = 1;i <= k;++i){
                ans += 1LL * (i + (j != len(digits) - 1) * adds) * 1LL * dp[k][i];
            }
            ans += adds++;
        }
        return ans + adds;
    }

    llong countOnes(long long left,long long right){
        for(int i = 0;i <= lg;++i){
            for(int j = 0;j <= i;++j){
                dp[i][j] = (j == 0 or i == j ? 1LL : dp[i - 1][j - 1] + dp[i - 1][j]);
            }
        }
        return calc(right) - calc(left - 1);
    }

    void solve(){
        llong l,r;
        while(cin>>l>>r){
            cout<<countOnes(l,r)<<'\n';
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
