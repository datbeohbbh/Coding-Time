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

    const llong inf = 1e18;

    llong compute(){
        int n,m;
        cin>>n>>m;
        vector < vector <int> > prices(n + 2,vector <int> (m + 2,0));
        vector < vector <int> > discounts(n + 2,vector <int> (m + 2,0));
        vector < vector <llong> > minpref(n + 2,vector <llong> (m + 2,inf));
        vector < vector <llong> > minsuff(n + 2,vector <llong> (m + 2,inf));
        vector < vector <llong> > f(n + 2,vector <llong> (m + 2,inf));
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin>>prices[i][j];
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                cin>>discounts[i][j];
            }
        }
        for(int j = 1;j <= m;++j){
            f[1][j] = prices[1][j];
            minpref[1][j] = minsuff[1][j] = prices[1][j];
        }
        for(int j = 2;j <= m;++j){
            minimize(minpref[1][j],minpref[1][j - 1]);
        }
        for(int j = m - 1;j >= 1;--j){
            minimize(minsuff[1][j],minsuff[1][j + 1]);
        }
        for(int i = 2;i <= n;++i){
            for(int j = 1;j <= m;++j){
                minimize(f[i][j],f[i - 1][j] + max(0LL,1LL * (prices[i][j] - discounts[i - 1][j])));
                minimize(f[i][j],prices[i][j] + min(minpref[i - 1][j - 1],minsuff[i - 1][j + 1]));
            }
            for(int j = 1;j <= m;++j){
                minpref[i][j] = minsuff[i][j] = f[i][j];
            }
            for(int j = 2;j <= m;++j){
                minimize(minpref[i][j],minpref[i][j - 1]);
            }
            for(int j = m - 1;j >= 1;--j){
                minimize(minsuff[i][j],minsuff[i][j + 1]);
            }
        }
        return *min_element(f[n].begin() + 1,f[n].begin() + 1 + m);
    }

    void solve(){
        int T;
        cin>>T;
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
