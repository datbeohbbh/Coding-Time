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

    void solve(){
        string s;
        cin>>s;
        int n = len(s);
        s = " " + s;
        map <pair <int,int>,int> cnt;
        llong ans = 0;
        vector <int> a(n + 2,0);
        vector <int> b(n + 2,0);
        vector <int> c(n + 2,0);
        for(int i = 1;i <= n;++i){
            a[i] = a[i - 1] + (s[i] == 'A');
            b[i] = b[i - 1] + (s[i] == 'B');
            c[i] = c[i - 1] + (s[i] == 'C');
        }
        cnt[make_pair(0,0)] = 1;
        for(int r = 1;r <= n;++r){
            ans += 1LL * cnt[make_pair(a[r] - b[r],a[r] - c[r])];
            ++cnt[make_pair(a[r] - b[r],a[r] - c[r])];
        }
        cout<<ans;
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
