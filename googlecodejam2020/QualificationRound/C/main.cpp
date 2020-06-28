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
        vector <int> s(n + 2);
        vector <int> e(n + 2);
        vector <int> ord(n + 2,0);
        for(int i = 1;i <= n;++i){
            cin>>s[i]>>e[i];
            ord[i] = i;
        }
        sort(ord.begin() + 1,ord.begin() + 1 + n,[&](const int &i,const int &j){
            return (s[i] < s[j]) or (s[i] == s[j] and e[i] < e[j]);
        });
        vector <int> ans(n + 2,0);
        bool chk = true;
        for(int i = 2;i <= n;++i){
            int cnt = 0;
            for(int j = i - 1;j >= 1;--j){
                if(e[ord[j]] > s[ord[i]]){
                    ++cnt;
                    ans[ord[i]] = ans[ord[j]] ^ 1;
                }
            }
            if(cnt > 1){
                chk = false;
                break;
            }
        }
        if(!chk){
            cout<<"Case #"<<test<<":"<<" "<<"IMPOSSIBLE"<<'\n';
        } else {
            cout<<"Case #"<<test<<":"<<" ";
            for(int i = 1;i <= n;++i){
                cout<<(ans[i] ? "J" : "C");
            }
            cout<<'\n';
        }
    }

    void solve(){
        int numTest;
        cin>>numTest;
        for(int test = 1;test <= numTest;++test){
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
