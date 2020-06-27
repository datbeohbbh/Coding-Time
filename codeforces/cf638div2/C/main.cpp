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

    string compute(){
        string s;
        int n,k;
        cin>>n>>k;
        cin>>s;
        sort(all(s));
        if(k == 1){
            return s;
        }
        s = " " + s;
        int cnt = 0;
        for(int i = 1;i <= k;++i){
            cnt += (s[i] == s[k]);
        }
        if(cnt != k){
            string ans = "";
            ans += s[k];
            return ans;
        }
        vector <char> t;
        for(int i = k + 1;i <= n;++i){
            t.emplace_back(s[i]);
        }
        sort(all(t));
        t.erase(unique(all(t)),t.end());
        if(len(t) > 1){
            string ans = "";
            ans += s[k];
            ans += s.substr(k + 1);
            return ans;
        }
        int c = (n - k) / k;
        int d = ((n - k) % k ? 1 : 0);
        string ans = "";
        ans += s[k];
        for(int i = 1;!t.empty() and i <= c + d;++i){
            ans += t[0];
        }
        return ans;
    }

    void solve(){
        int t;
        cin>>t;
        while(t--){
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
