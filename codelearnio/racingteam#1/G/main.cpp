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

    bool equalArray(vector <int> a,vector <int> b){
        sort(all(a));
        sort(all(b));
        int n = len(a);
        int m = len(b);
        vector < vector <int> > f(n + 2,vector <int> (m + 2,0));
        for(int i = 0;i < n;++i){
            for(int j = 0;j < m;++j){
                if(a[i] == b[j]){
                    maximize(f[i][j],(i - 1 >= 0 and j - 1 >= 0 ? f[i - 1][j - 1] : 0) + 1);
                } else {
                    maximize(f[i][j],(i - 1 >= 0 ? f[i - 1][j] : 0));
                    maximize(f[i][j],(j - 1 >= 0 ? f[i][j - 1] : 0));
                    maximize(f[i][j],(i - 1 >= 0 and j - 1 >= 0 ? f[i - 1][j - 1] : 0));
                }
            }
        }
        return (f[n - 1][m - 1] == min(n,m));
    }

    void solve(){
        vector <int> a,b;
        string x,y;
        getline(cin,x);
        getline(cin,y);
        stringstream ss(x);
        int val;
        while(ss >> val){
            a.emplace_back(val);
        }
        stringstream tt(y);
        while(tt >> val){
            b.emplace_back(val);
        }
        cout<<equalArray(a,b);
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
