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

    const int gr = 595; //595
    const int sz_gr = 5; // 5

    int factorial(int n){
        if(n <= 1){
            return 1;
        }
        return n * factorial(n - 1);
    }

    void compute(int f){
        vector <int> cnt[sz_gr];
        for(int i = 1;i < gr;i += sz_gr){
            cout<<i<<endl;
            char c; cin>>c;
            cnt[c - 'A'].emplace_back(i);
            --f;
        }
        int g = -1;
        string s = "";
        for(int i = 0;i < sz_gr;++i){
            if(len(cnt[i]) == factorial(sz_gr - 1) - 1){
                g = i;
            } else {
                s += (char)(i + 'A');
            }
        }
        map <string,int> vis;
        do{
            ++vis[s] = true;
        }while(next_permutation(all(s)));
        for(int i = 0;i < len(cnt[g]);++i){
            int x = cnt[g][i];
            string str = "";
            for(int j = 1;j <= sz_gr - 1;++j){
                cout<<x + j<<endl;
                char c; cin>>c;
                str += c;
                --f;
            }
            ++vis[str];
        }
        while(f > 0){
            cout<<1<<endl;
            char c; cin>>c;
            --f;
        }
        for (pair<string, int> it : vis) {
            if (it . second == 1) {
                    cout << (char) (g + 'A') << it . first <<endl;
                    char c; cin >> c;
                    if (c == 'N') {
                        exit(0);
                    }
            }
        }
    }

    void compute_2(int f){
        vector <int> ask;
        for(int i = 1;i < gr;i += sz_gr){
            ask.emplace_back(i);
        }
        string ans = "";
        int adds = 0;
        for(int t = sz_gr - 1;t > 0;--t,++adds){
            int x = factorial(t) - 1;
            vector <int> cnt[sz_gr];
            for(int i = 0;i < len(ask);++i){
                cout<<ask[i] + adds<<endl;
                char c; cin>>c;
                cnt[c - 'A'].emplace_back(ask[i]);
                --f;
            }
            int g = -1;
            for(int i = 0;i < sz_gr;++i){
                if(ans.find((char)(i + 'A')) == string::npos and len(cnt[i]) == x){
                    g = i;
                    ans += (char)(i + 'A');
                    break;
                }
            }
            swap(ask,cnt[g]);
        }
        while(f > 0){
            cout<<1<<endl;
            char c; cin>>c;
            --f;
        }
        for(int i = 0;i < sz_gr;++i){
            if(ans.find((char)(i + 'A')) == string::npos){
                ans += (char)(i + 'A');
                break;
            }
        }
        cout<<ans<<endl;
        char c; cin>>c;
        if(c == 'N'){
            exit(0);
        }
    }

    void solve(){
        int T,f;
        cin>>T>>f;
        for(int t = 1;t <= T;++t){
            if(f == 475) {
                compute(f);
            } else {
                compute_2(f);
            }
        }
    }
}

int main(void){
   /* ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(fn".inp","r",stdin);
    //freopen(fn".out","w",stdout);
    #endif // ONLINE_JUDGE*/
    task::solve();
}
