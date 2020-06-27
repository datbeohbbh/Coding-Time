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

    const llong N = 1e6 + 6;
    const llong base[2] = {1000000007,1000000087};
    const llong cc[2] = {29LL,31LL};
    llong pw[2][N];
    llong hs[2][N];
    llong rev_hs[2][N];

    pair <llong,llong> getHs(int l,int r){
        llong hs_1 = (hs[0][r] - hs[0][l - 1] * pw[0][r - l + 1] + base[0] * base[0]) % base[0];
        llong hs_2 = (hs[1][r] - hs[1][l - 1] * pw[1][r - l + 1] + base[1] * base[1]) % base[1];
        return make_pair(hs_1,hs_2);
    }

    pair <llong,llong> rev_getHs(int l,int r){
        llong hs_1 = (rev_hs[0][r] - rev_hs[0][l - 1] * pw[0][r - l + 1] + base[0] * base[0]) % base[0];
        llong hs_2 = (rev_hs[1][r] - rev_hs[1][l - 1] * pw[1][r - l + 1] + base[1] * base[1]) % base[1];
        return make_pair(hs_1,hs_2);
    }

    string calc(const string &s){
        string str = " " + s;
        string rev_s = s;
        reverse(all(rev_s));
        rev_s = " " + rev_s;
        int n = len(s);
        hs[0][0] = hs[1][0] = rev_hs[0][0] = rev_hs[0][1] = 0;
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < 2;++j){
                hs[j][i] = (hs[j][i - 1] * cc[j] + (llong)(str[i] - 'a' + 1)) % base[j];
            }
        }
        for(int i = 1;i <= n;++i){
            for(int j = 0;j < 2;++j){
                rev_hs[j][i] = (rev_hs[j][i - 1] * cc[j] + (llong)(rev_s[i] - 'a' + 1)) % base[j];
            }
        }
        string pref = "";
        int pre = -1;
        for(int i = 1;i <= n;++i){
            if(getHs(1,i) == rev_getHs(n - i + 1,n)){
                pre = i;
            }
        }
        for(int i = 1;i <= pre;++i){
            pref += str[i];
        }
        int cur = 0;
        int pos_a = 0,pos_b = 0;
        for(int i = 1;i <= n;++i){
            if(getHs(1,i) == rev_getHs(1,i)){
                ++cur;
                pos_a = i;
                pos_b = n - i + 1;
            } else {
                break;
            }
        }
        string ans = "";
        if(cur){
            for(int i = 1;i <= pos_a;++i){
                ans += str[i];
            }
            int flag = -1;
            for(int i = cur + 1;i < pos_b;++i){
                if(getHs(cur + 1,i) == rev_getHs(n - i + 1,n - cur)){
                    flag = i;
                }
            }
            for(int i = cur + 1;i <= flag;++i){
                ans += str[i];
            }
            if(pos_a < pos_b) {
                for (int i = pos_b; i <= n; ++i) {
                    ans += str[i];
                }
            }
        }
        return (len(ans) > len(pref) ? ans : pref);
    }

    void solve(){
        int t;
        cin>>t;
        pw[0][0] = pw[1][0] = 1;
        for(int i = 1;i <= N - 6;++i){
            pw[0][i] = (pw[0][i - 1] * 29LL) % base[0];
            pw[1][i] = (pw[1][i - 1] * 31LL) % base[1];
        }
        while(t--){
            string s;
            cin>>s;
            string x = calc(s);
            reverse(all(s));
            string y = calc(s);
            cout<<(len(x) > len(y) ? x : y)<<'\n';
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
