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

    string treeLogic(int n){
        string ans = "";
        for(int start = n % 10,i = 1;i <= n;++i,start %= 10){
            ans += (char)(start + '0');
            ++start;
        }
        string t = "";
        if((int)ans.size() > 1){
            t = ans.substr(0,(int)ans.size() - 1);
        }
        reverse(t.begin(),t.end());
        return ans + t;
    }

    void solve(){
        int n;
        while(cin >> n){
            cout<<treeLogic(n)<<'\n';
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
