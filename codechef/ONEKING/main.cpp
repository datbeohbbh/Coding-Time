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

    int compute(){
        int n;
        cin>>n;
        vector <int> a(n + 2,0);
        vector <int> b(n + 2,0);
        vector <int> ord(n + 2,0);
        int l = 1e9;
        for(int i = 1;i <= n;++i){
            cin>>a[i]>>b[i];
            ord[i] = i;
            minimize(l,a[i]);
        }
        sort(ord.begin() + 1,ord.begin() + 1 + n,[&](const int &x,const int &y){
            return (b[x] < b[y]) or (b[x] == b[y] and a[x] < a[y]);
        });
        int ans = 0;
        --l;
        for(int i = 1;i <= n;++i){
            int j = ord[i];
            if(a[j] > l){
                ++ans;
                l = b[j];
            }
        }
        return ans;
    }

    void solve(){
        int T;
        cin>>T;
        for(int test = 1;test <= T;++test){
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
