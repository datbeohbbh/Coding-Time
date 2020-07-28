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

    int convert(int val,int j){
        return (j ? -1 : 1) * val;
    }

    bool convertArray(vector <int> a){
        int n = len(a);
        vector < vector <int> > f(n,vector <int> (2,0));
        f[0][0] = f[0][1] = 1;
        for(int i = 1;i < n;++i){
            for(int j = 0;j < 2;++j){
                for(int k = 0;k < 2;++k){
                    maximize(f[i][j],f[i - 1][k] + (convert(a[i - 1],k) < convert(a[i],j)));
                }
            }
        }
        return (max(f[n - 1][0],f[n - 1][1]) == n);
    }

    void solve(){
        vector <int> a;
        int val;
        while(cin >> val){
            a.emplace_back(val);
        }
        cout<<convertArray(a);
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
