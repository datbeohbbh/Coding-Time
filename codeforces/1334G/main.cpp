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

    const int N = 2e5 + 5;
    string s,t;
    int p[1000];
    int n;

    void solve(){
        for(int i = 0;i < 26;++i){
            cin>>p[i];
            --p[i];
        }
        cin>>s>>t;
        string str = s + "#" + t;
        n = len(str);
        vector <int> kmp(n + 2,0);
        for(int i = 1;i < n;++i){
            int j = kmp[i - 1];
            while(j > 0){
                pair <int,int> x = make_pair(str[i],str[i] - 'a');
                pair <int,int> y = make_pair(str[j],str[j] == '#' ? -1 : p[str[j] - 'a']);
                if(x.first == y.first or x.second == y.second){
                    break;
                }
                j = kmp[j - 1];
            }
            kmp[i] = j + (str[i] == str[j] or str[i] - 'a' == (str[j] == '#' ? -1 : p[str[j] - 'a']));
        }
        vector <int> ans(len(t),0);
        for(int i = len(s) + 1;i < n;++i){
            if(kmp[i] == len(s)){
                ans[i - (len(s) << 1)] = 1;
            }
        }
        for(int i = 0;i < len(ans);++i){
            cout<<ans[i];
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
