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

    void compute(int test){
        int n;
        cin>>n;
        vector < vector <int> > a(n + 2,vector <int> (n + 2));
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= n;++j){
                cin>>a[i][j];
            }
        }
        int k = 0;
        for(int i = 1;i <= n;++i){
            k += a[i][i];
        }
        int r = 0;
        for(int i = 1;i <= n;++i){
            set <int> row;
            for(int j = 1;j <= n;++j){
                row.insert(a[i][j]);
            }
            r += (len(row) < n);
        }
        int c = 0;
        for(int j = 1;j <= n;++j){
            set <int> col;
            for(int i = 1;i <= n;++i){
                col.insert(a[i][j]);
            }
            c += (len(col) < n);
        }
        cout<<"Case #"<<test<<": "<<k<<' '<<r<<' '<<c<<'\n';
    }

    void solve(){
        int tests;
        cin>>tests;
        for(int test = 1;test <= tests;++test){
            compute(test);
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
