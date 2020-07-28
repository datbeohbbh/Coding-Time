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

    llong compute(int n){
        vector <int> col(n + 2,0);
        vector < vector <int> > c(n + 2,vector <int> (n + 2,0));
        vector < vector <llong> > f(n + 2,vector <llong> (n + 2,0));
        for(int i = 1;i <= n;++i){
            cin>>col[i];
        }
        for(int l = 1;l <= n;++l){
            int sum = 0;
            for(int r = l;r <= n;++r){
                sum += col[r];
                c[l][r] = sum % 100;
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                if(i != j){
                    f[i][j] = inf;
                }
            }
        }
        for(int i = 1;i < n;++i){
            f[i][i + 1] = col[i] * col[i + 1];
        }
        for(int gap = 3;gap <= n;++gap){
            for(int l = 1,r = gap;r <= n;++l,++r){
                for(int mid = l;mid < r;++mid){
                    minimize(f[l][r],f[l][mid] + f[mid + 1][r] + 1LL * c[l][mid] * 1LL * c[mid + 1][r]);
                }
            }
        }
        return f[1][n];
    }

    void solve(){
        int n;
        while(cin>>n){
            cout<<compute(n)<<'\n';
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
