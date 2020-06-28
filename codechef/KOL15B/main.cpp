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

    const int lg = 12;

    class Sol{
    public:
        int n,m;
        vector < vector <int> > a;
        vector < vector <int> > l,r,u,d;
        vector < vector <int> > sum_rows,sum_cols;

        Sol(){}
        ~Sol(){
            a.clear();
            l.clear();
            r.clear();
            u.clear();
            d.clear();
            sum_rows.clear();
            sum_cols.clear();
        }
    public:
        void compute(){
            cin>>n>>m;
            a.resize(n + 2,vector <int> (m + 2,0));
            l.resize(n + 2,vector <int> (m + 2,0));
            r.resize(n + 2,vector <int> (m + 2,0));
            u.resize(n + 2,vector <int> (m + 2,0));
            d.resize(n + 2,vector <int> (m + 2,0));
            sum_rows.resize(n + 2,vector <int> (m + 2,0));
            sum_cols.resize(n + 2,vector <int> (m + 2,0));
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j){
                    cin>>a[i][j];
                    sum_cols[i][j] = sum_rows[i][j] = a[i][j];
                }
            }
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j){
                    sum_rows[i][j] += sum_rows[i][j - 1];
                }
            }
            for(int j = 1;j <= m;++j){
                for(int i = 1;i <= n;++i){
                    sum_cols[i][j] += sum_cols[i - 1][j];
                }
            }
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j){
                    l[i][j] = j;
                    if(sum_rows[i][l[i][j - 1]] > sum_rows[i][j]){
                        l[i][j] = l[i][j - 1];
                    }
                }
                for(int j = m;j >= 1;--j){
                    r[i][j] = j;
                    if(j < m and sum_rows[i][r[i][j + 1]] < sum_rows[i][j]){
                        r[i][j] = r[i][j + 1];
                    }
                }
            }
            for(int j = 1;j <= m;++j){
                for(int i = 1;i <= n;++i){
                    u[i][j] = i;
                    if(sum_cols[u[i - 1][j]][j] > sum_cols[i][j]){
                        u[i][j] = u[i - 1][j];
                    }
                }
                for(int i = n;i >= 1;--i){
                    d[i][j] = i;
                    if(i < n and sum_cols[d[i + 1][j]][j] < sum_cols[i][j]){
                        d[i][j] = d[i + 1][j];
                    }
                }
            }
            llong ans = numeric_limits <llong> :: max();
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j){
                    int ll = min(0,sum_rows[i][j - 1] - sum_rows[i][l[i][j - 1]]);
                    int rr = min(0,sum_rows[i][r[i][min(m,j + 1)]] - sum_rows[i][j]);
                    int uu = min(0,sum_cols[i - 1][j] - sum_cols[u[i - 1][j]][j]);
                    int dd = min(0,sum_cols[d[min(n,i + 1)][j]][j] - sum_cols[i][j]);
                    minimize(ans,1LL * a[i][j] + 1LL * ll + 1LL * rr + 1LL * uu + 1LL * dd);
                }
            }
            cout<<ans<<'\n';
        }
    };

    void solve(){
        int T;
        cin>>T;
        while(T--){
            Sol *t = new Sol();
            t -> compute();
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
