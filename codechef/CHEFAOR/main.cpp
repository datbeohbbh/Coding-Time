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

    class Solver{
    public:
        vector < vector < llong > > dp;
        vector < vector < llong > > cost;
        vector < int > a;
        int n,k;
        ~Solver(){
            dp.clear();
            cost.clear();
        }
    public:
        void solve(){
            cin>>n>>k;
            a.resize(n + 2,0);
            dp.resize(k + 2,vector < llong > (n + 2,0));
            cost.resize(n + 2,vector < llong > (n + 2,0));
            for(int i = 1;i <= n;++i){
                cin>>a[i];
            }
            for(int i = 1;i <= n;++i){
                cost[i][i] = a[i];
                for(int j = i + 1;j <= n;++j){
                    cost[i][j] = cost[i][j - 1] | a[j];
                }
            }
            for(int i = 1;i <= n;++i){
                dp[1][i] = cost[1][i];
            }
            function <void(int,int,int,int,int)> opt = [&](int jleft,int jright,int kleft,int kright,int gr){
                if(jleft > jright){
                    return ;
                }
                int jmid = (jleft + jright) >> 1;
                int bestk = kleft;
                for(int j = kleft;j <= min(kright,jmid);++j){
                    if(dp[gr][jmid] < dp[gr - 1][j - 1] + cost[j][jmid]){
                        dp[gr][jmid] = dp[gr - 1][j - 1] + cost[j][jmid];
                        bestk = j;
                    }
                }
                opt(jleft,jmid - 1,kleft,bestk,gr);
                opt(jmid + 1,jright,bestk,kright,gr);
            };
            for(int gr = 2;gr <= k;++gr){
                opt(1,n,1,n,gr);
            }
            cout<<dp[k][n]<<'\n';
        }
    };

    void solve(){
        int Tests;
        cin>>Tests;
        while(Tests--){
            (new Solver) -> solve();
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
